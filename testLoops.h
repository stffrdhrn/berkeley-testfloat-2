
/*============================================================================

This C header file is part of Berkeley TestFloat, Release 2c, a package of
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

#include <stdio.h>

extern volatile flag stop;

extern char *trueName, *testName;
extern flag forever, errorStop;
extern uint32 maxErrorCount;
extern flag checkNaNs;
extern int8 *trueFlagsPtr;
extern int8 ( *testFlagsFunctionPtr )( void );
extern char *functionName;
extern char *roundingPrecisionName, *roundingModeName, *tininessModeName;
extern flag anyErrors;

void writeFunctionName( FILE * );
void exitWithStatus( void );

void test_a_int32_z_float32( float32 ( int32 ), float32 ( int32 ) );
void test_a_int32_z_float64( float64 ( int32 ), float64 ( int32 ) );
#ifdef FLOATX80
void test_a_int32_z_floatx80( floatx80 ( int32 ), floatx80 ( int32 ) );
#endif
#ifdef FLOAT128
void test_a_int32_z_float128( float128 ( int32 ), float128 ( int32 ) );
#endif
#ifdef BITS64
void test_a_int64_z_float32( float32 ( int64 ), float32 ( int64 ) );
void test_a_int64_z_float64( float64 ( int64 ), float64 ( int64 ) );
#ifdef FLOATX80
void test_a_int64_z_floatx80( floatx80 ( int64 ), floatx80 ( int64 ) );
#endif
#ifdef FLOAT128
void test_a_int64_z_float128( float128 ( int64 ), float128 ( int64 ) );
#endif
#endif

void test_a_float32_z_int32( int32 ( float32 ), int32 ( float32 ) );
#ifdef BITS64
void test_a_float32_z_int64( int64 ( float32 ), int64 ( float32 ) );
#endif
void test_a_float32_z_float64( float64 ( float32 ), float64 ( float32 ) );
#ifdef FLOATX80
void test_a_float32_z_floatx80( floatx80 ( float32 ), floatx80 ( float32 ) );
#endif
#ifdef FLOAT128
void test_a_float32_z_float128( float128 ( float32 ), float128 ( float32 ) );
#endif
void test_az_float32( float32 ( float32 ), float32 ( float32 ) );
void
 test_ab_float32_z_flag(
     flag ( float32, float32 ), flag ( float32, float32 ) );
void
 test_abz_float32(
     float32 ( float32, float32 ), float32 ( float32, float32 ) );

void test_a_float64_z_int32( int32 ( float64 ), int32 ( float64 ) );
#ifdef BITS64
void test_a_float64_z_int64( int64 ( float64 ), int64 ( float64 ) );
#endif
void test_a_float64_z_float32( float32 ( float64 ), float32 ( float64 ) );
#ifdef FLOATX80
void test_a_float64_z_floatx80( floatx80 ( float64 ), floatx80 ( float64 ) );
#endif
#ifdef FLOAT128
void test_a_float64_z_float128( float128 ( float64 ), float128 ( float64 ) );
#endif
void test_az_float64( float64 ( float64 ), float64 ( float64 ) );
void
 test_ab_float64_z_flag(
     flag ( float64, float64 ), flag ( float64, float64 ) );
void
 test_abz_float64(
     float64 ( float64, float64 ), float64 ( float64, float64 ) );

#ifdef FLOATX80

void test_a_floatx80_z_int32( int32 ( floatx80 ), int32 ( floatx80 ) );
#ifdef BITS64
void test_a_floatx80_z_int64( int64 ( floatx80 ), int64 ( floatx80 ) );
#endif
void test_a_floatx80_z_float32( float32 ( floatx80 ), float32 ( floatx80 ) );
void test_a_floatx80_z_float64( float64 ( floatx80 ), float64 ( floatx80 ) );
#ifdef FLOAT128
void
 test_a_floatx80_z_float128( float128 ( floatx80 ), float128 ( floatx80 ) );
#endif
void test_az_floatx80( floatx80 ( floatx80 ), floatx80 ( floatx80 ) );
void
 test_ab_floatx80_z_flag(
     flag ( floatx80, floatx80 ), flag ( floatx80, floatx80 ) );
void
 test_abz_floatx80(
     floatx80 ( floatx80, floatx80 ), floatx80 ( floatx80, floatx80 ) );

#endif

#ifdef FLOAT128

void test_a_float128_z_int32( int32 ( float128 ), int32 ( float128 ) );
#ifdef BITS64
void test_a_float128_z_int64( int64 ( float128 ), int64 ( float128 ) );
#endif
void test_a_float128_z_float32( float32 ( float128 ), float32 ( float128 ) );
void test_a_float128_z_float64( float64 ( float128 ), float64 ( float128 ) );
#ifdef FLOATX80
void
 test_a_float128_z_floatx80( floatx80 ( float128 ), floatx80 ( float128 ) );
#endif
void test_az_float128( float128 ( float128 ), float128 ( float128 ) );
void
 test_ab_float128_z_flag(
     flag ( float128, float128 ), flag ( float128, float128 ) );
void
 test_abz_float128(
     float128 ( float128, float128 ), float128 ( float128, float128 ) );

#endif

