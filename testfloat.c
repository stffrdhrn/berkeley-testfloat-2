
/*============================================================================

This C source file is part of Berkeley TestFloat, Release 2c, a package of
programs for testing the correctness of floating-point arithmetic complying
with the IEEE Standard for Floating-Point, by John R. Hauser.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has
been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES
RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS
AND ORGANIZATIONS WHO CAN AND WILL TOLERATE ALL LOSSES, COSTS, OR OTHER
PROBLEMS THEY INCUR DUE TO THE SOFTWARE WITHOUT RECOMPENSE FROM JOHN HAUSER,
AND WHO FURTHERMORE EFFECTIVELY INDEMNIFY JOHN HAUSER (possibly via similar
legal notice) AGAINST ALL LOSSES, COSTS, OR OTHER PROBLEMS INCURRED BY THEIR
CUSTOMERS AND CLIENTS DUE TO THE SOFTWARE, OR INCURRED BY ANYONE DUE TO A
DERIVATIVE WORK THEY CREATE USING ANY PART OF THE SOFTWARE.

Derivative works require also that (1) the source code for the derivative work
includes prominent notice that the work is derivative, and (2) the source code
includes prominent notice of these three paragraphs for those parts of this
code that are retained.

This has been modified to work as needed by Stafford Horne.

============================================================================*/

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "milieu.h"
#include "fail.h"
#include "softfloat.h"
#include "testCases.h"
#include "testLoops.h"
#include "systflags.h"
#include "testFunction.h"

static void catchSIGINT( int signalCode )
{

    if ( stop ) exit( EXIT_FAILURE );
    stop = TRUE;

}

main( int argc, char **argv )
{
    char *argPtr;
    flag functionArgument;
    uint8 functionCode;
    int8 operands, roundingPrecision, roundingMode;

    fail_programName = "testfloat";
    if ( argc <= 1 ) goto writeHelpMessage;
    testCases_setLevel( 1 );
    trueName = "soft";
    testName = "syst";
    errorStop = FALSE;
    forever = FALSE;
    maxErrorCount = 20;
    trueFlagsPtr = &float_exception_flags;
    testFlagsFunctionPtr = syst_float_flags_clear;
    tininessModeName = 0;
    functionArgument = FALSE;
    functionCode = 0;
    operands = 0;
    roundingPrecision = 0;
    roundingMode = 0;
    --argc;
    ++argv;
    while ( argc && ( argPtr = argv[ 0 ] ) ) {
        if ( argPtr[ 0 ] == '-' ) ++argPtr;
        if ( strcmp( argPtr, "help" ) == 0 ) {
 writeHelpMessage:
            fputs(
"testfloat [<option>...] <function>\n"
"  <option>:  (* is default)\n"
"    -help            --Write this message and exit.\n"
"    -list            --List all testable functions and exit.\n"
"    -level <num>     --Testing level <num> (1 or 2).\n"
" *  -level 1\n"
"    -errors <num>    --Stop each function test after <num> errors.\n"
" *  -errors 20\n"
"    -errorstop       --Exit after first function with any error.\n"
"    -forever         --Test one function repeatedly (implies `-level 2').\n"
"    -checkNaNs       --Check for bitwise correctness of NaN results.\n"
#ifdef FLOATX80
"    -precision32     --Only test rounding precision equivalent to float32.\n"
"    -precision64     --Only test rounding precision equivalent to float64.\n"
"    -precision80     --Only test maximum rounding precision.\n"
#endif
"    -nearesteven     --Only test rounding to nearest/even.\n"
"    -tozero          --Only test rounding to zero.\n"
"    -down            --Only test rounding down.\n"
"    -up              --Only test rounding up.\n"
"    -tininessbefore  --Underflow tininess detected before rounding.\n"
"    -tininessafter   --Underflow tininess detected after rounding.\n"
"  <function>:\n"
"    int32_to_<float>                 <float>_add   <float>_eq\n"
"    <float>_to_int32                 <float>_sub   <float>_le\n"
"    <float>_to_int32_round_to_zero   <float>_mul   <float>_lt\n"
#ifdef BITS64
"    int64_to_<float>                 <float>_div   <float>_eq_signaling\n"
"    <float>_to_int64                 <float>_rem   <float>_le_quiet\n"
"    <float>_to_int64_round_to_zero                 <float>_lt_quiet\n"
"    <float>_to_<float>\n"
"    <float>_round_to_int\n"
"    <float>_sqrt\n"
#else
"    <float>_to_<float>               <float>_div   <float>_eq_signaling\n"
"    <float>_round_to_int             <float>_rem   <float>_le_quiet\n"
"    <float>_sqrt                                   <float>_lt_quiet\n"
#endif
"    -all1            --All 1-operand functions.\n"
"    -all2            --All 2-operand functions.\n"
"    -all             --All functions.\n"
"  <float>:\n"
"    float32          --32-bit single-precision.\n"
"    float64          --64-bit double-precision.\n"
#ifdef FLOATX80
"    floatx80         --80-bit double-extended-precision.\n"
#endif
#ifdef FLOAT128
"    float128         --128-bit quadruple-precision.\n"
#endif
                ,
                stdout
            );
            return EXIT_SUCCESS;
        }
        else if ( strcmp( argPtr, "list" ) == 0 ) {
            for ( functionCode = 1;
                  functionCode < NUM_FUNCTIONS;
                  ++functionCode
                ) {
                if ( functionExists[ functionCode ] ) {
                    puts( functions[ functionCode ].name );
                }
            }
            return EXIT_SUCCESS;
        }
        else if ( strcmp( argPtr, "level" ) == 0 ) {
            if ( argc < 2 ) goto optionError;
            testCases_setLevel( atoi( argv[ 1 ] ) );
            --argc;
            ++argv;
        }
        else if ( strcmp( argPtr, "level1" ) == 0 ) {
            testCases_setLevel( 1 );
        }
        else if ( strcmp( argPtr, "level2" ) == 0 ) {
            testCases_setLevel( 2 );
        }
        else if ( strcmp( argPtr, "errors" ) == 0 ) {
            if ( argc < 2 ) {
     optionError:
                fail( "`%s' option requires numeric argument", argv[ 0 ] );
            }
            maxErrorCount = atoi( argv[ 1 ] );
            --argc;
            ++argv;
        }
        else if ( strcmp( argPtr, "errorstop" ) == 0 ) {
            errorStop = TRUE;
        }
        else if ( strcmp( argPtr, "forever" ) == 0 ) {
            testCases_setLevel( 2 );
            forever = TRUE;
        }
        else if (    ( strcmp( argPtr, "checkNaNs" ) == 0 )
                  || ( strcmp( argPtr, "checknans" ) == 0 ) ) {
            checkNaNs = TRUE;
        }
#ifdef FLOATX80
        else if ( strcmp( argPtr, "precision32" ) == 0 ) {
            roundingPrecision = 32;
        }
        else if ( strcmp( argPtr, "precision64" ) == 0 ) {
            roundingPrecision = 64;
        }
        else if ( strcmp( argPtr, "precision80" ) == 0 ) {
            roundingPrecision = 80;
        }
#endif
        else if (    ( strcmp( argPtr, "nearesteven" ) == 0 )
                  || ( strcmp( argPtr, "nearest_even" ) == 0 ) ) {
            roundingMode = ROUND_NEAREST_EVEN;
        }
        else if (    ( strcmp( argPtr, "tozero" ) == 0 )
                  || ( strcmp( argPtr, "to_zero" ) == 0 ) ) {
            roundingMode = ROUND_TO_ZERO;
        }
        else if ( strcmp( argPtr, "down" ) == 0 ) {
            roundingMode = ROUND_DOWN;
        }
        else if ( strcmp( argPtr, "up" ) == 0 ) {
            roundingMode = ROUND_UP;
        }
        else if ( strcmp( argPtr, "tininessbefore" ) == 0 ) {
            float_detect_tininess = float_tininess_before_rounding;
        }
        else if ( strcmp( argPtr, "tininessafter" ) == 0 ) {
            float_detect_tininess = float_tininess_after_rounding;
        }
        else if ( strcmp( argPtr, "all1" ) == 0 ) {
            functionArgument = TRUE;
            functionCode = 0;
            operands = 1;
        }
        else if ( strcmp( argPtr, "all2" ) == 0 ) {
            functionArgument = TRUE;
            functionCode = 0;
            operands = 2;
        }
        else if ( strcmp( argPtr, "all" ) == 0 ) {
            functionArgument = TRUE;
            functionCode = 0;
            operands = 0;
        }
        else {
            for ( functionCode = 1;
                  functionCode < NUM_FUNCTIONS;
                  ++functionCode
                ) {
                if ( strcmp( argPtr, functions[ functionCode ].name ) == 0 ) {
                    break;
                }
            }
            if ( functionCode == NUM_FUNCTIONS ) {
                fail( "Invalid option or function `%s'", argv[ 0 ] );
            }
            if ( ! functionExists[ functionCode ] ) {
                fail(
                    "Function `%s' is not supported or cannot be tested",
                    argPtr
                );
            }
            functionArgument = TRUE;
        }
        --argc;
        ++argv;
    }
    if ( ! functionArgument ) fail( "Function argument required" );
    (void) signal( SIGINT, catchSIGINT );
    (void) signal( SIGTERM, catchSIGINT );
    if ( functionCode ) {
        if ( forever ) {
            if ( ! roundingPrecision ) roundingPrecision = 80;
            if ( ! roundingMode ) roundingMode = ROUND_NEAREST_EVEN;
        }
        testFunction( functionCode, roundingPrecision, roundingMode );
    }
    else {
        if ( forever ) {
            fail( "Can only test one function with `-forever' option" );
        }
        if ( operands == 1 ) {
            for ( functionCode = 1;
                  functionCode < NUM_FUNCTIONS;
                  ++functionCode
                ) {
                if (    functionExists[ functionCode ]
                     && ( functions[ functionCode ].numInputs == 1 ) ) {
                    testFunction(
                        functionCode, roundingPrecision, roundingMode );
                }
            }
        }
        else if ( operands == 2 ) {
            for ( functionCode = 1;
                  functionCode < NUM_FUNCTIONS;
                  ++functionCode
                ) {
                if (    functionExists[ functionCode ]
                     && ( functions[ functionCode ].numInputs == 2 ) ) {
                    testFunction(
                        functionCode, roundingPrecision, roundingMode );
                }
            }
        }
        else {
            for ( functionCode = 1;
                  functionCode < NUM_FUNCTIONS;
                  ++functionCode
                ) {
                if ( functionExists[ functionCode ] ) {
                    testFunction(
                        functionCode, roundingPrecision, roundingMode );
                }
            }
        }
    }
    exitWithStatus();

}

