
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

/*----------------------------------------------------------------------------
| The following macros are defined to indicate that the corresponding
| functions exist.
*----------------------------------------------------------------------------*/
#define SYST_INT32_TO_FLOAT32
#define SYST_INT32_TO_FLOAT64
#ifdef BITS64
#define SYST_INT64_TO_FLOAT32
#define SYST_INT64_TO_FLOAT64
#endif
#define SYST_FLOAT32_TO_INT32_ROUND_TO_ZERO
#ifdef BITS64
#define SYST_FLOAT32_TO_INT64_ROUND_TO_ZERO
#endif
#define SYST_FLOAT32_TO_FLOAT64
#define SYST_FLOAT32_ADD
#define SYST_FLOAT32_SUB
#define SYST_FLOAT32_MUL
#define SYST_FLOAT32_DIV
#define SYST_FLOAT32_REM
#define SYST_FLOAT64_REM
#define SYST_FLOAT32_EQ
#define SYST_FLOAT32_LE
#define SYST_FLOAT32_LT
#define SYST_FLOAT64_TO_INT32_ROUND_TO_ZERO
#ifdef BITS64
#define SYST_FLOAT64_TO_INT64_ROUND_TO_ZERO
#endif
#define SYST_FLOAT64_TO_FLOAT32
#define SYST_FLOAT64_ADD
#define SYST_FLOAT64_SUB
#define SYST_FLOAT64_MUL
#define SYST_FLOAT64_DIV
#define SYST_FLOAT64_SQRT
#define SYST_FLOAT64_EQ
#define SYST_FLOAT64_LE
#define SYST_FLOAT64_LT
#if defined( FLOATX80 ) && defined( LONG_DOUBLE_IS_FLOATX80 )
#define SYST_INT32_TO_FLOATX80
#ifdef BITS64
#define SYST_INT64_TO_FLOATX80
#endif
#define SYST_FLOAT32_TO_FLOATX80
#define SYST_FLOAT64_TO_FLOATX80
#define SYST_FLOATX80_TO_INT32_ROUND_TO_ZERO
#ifdef BITS64
#define SYST_FLOATX80_TO_INT64_ROUND_TO_ZERO
#endif
#define SYST_FLOATX80_TO_FLOAT32
#define SYST_FLOATX80_TO_FLOAT64
#define SYST_FLOATX80_ADD
#define SYST_FLOATX80_SUB
#define SYST_FLOATX80_MUL
#define SYST_FLOATX80_DIV
#define SYST_FLOATX80_EQ
#define SYST_FLOATX80_LE
#define SYST_FLOATX80_LT
#endif
#if defined( FLOAT128 ) && defined( LONG_DOUBLE_IS_FLOAT128 )
#define SYST_INT32_TO_FLOAT128
#ifdef BITS64
#define SYST_INT64_TO_FLOAT128
#endif
#define SYST_FLOAT32_TO_FLOAT128
#define SYST_FLOAT64_TO_FLOAT128
#define SYST_FLOAT128_TO_INT32_ROUND_TO_ZERO
#ifdef BITS64
#define SYST_FLOAT128_TO_INT64_ROUND_TO_ZERO
#endif
#define SYST_FLOAT128_TO_FLOAT32
#define SYST_FLOAT128_TO_FLOAT64
#define SYST_FLOAT128_ADD
#define SYST_FLOAT128_SUB
#define SYST_FLOAT128_MUL
#define SYST_FLOAT128_DIV
#define SYST_FLOAT128_EQ
#define SYST_FLOAT128_LE
#define SYST_FLOAT128_LT
#endif

/*----------------------------------------------------------------------------
| System function declarations.  (Some of these functions may not exist.)
*----------------------------------------------------------------------------*/
float32 syst_int32_to_float32( int32 );
float64 syst_int32_to_float64( int32 );
#ifdef FLOATX80
floatx80 syst_int32_to_floatx80( int32 );
#endif
#ifdef FLOAT128
float128 syst_int32_to_float128( int32 );
#endif
#ifdef BITS64
float32 syst_int64_to_float32( int64 );
float64 syst_int64_to_float64( int64 );
#ifdef FLOATX80
floatx80 syst_int64_to_floatx80( int64 );
#endif
#ifdef FLOAT128
float128 syst_int64_to_float128( int64 );
#endif
#endif
int32 syst_float32_to_int32( float32 );
int32 syst_float32_to_int32_round_to_zero( float32 );
#ifdef BITS64
int64 syst_float32_to_int64( float32 );
int64 syst_float32_to_int64_round_to_zero( float32 );
#endif
float64 syst_float32_to_float64( float32 );
#ifdef FLOATX80
floatx80 syst_float32_to_floatx80( float32 );
#endif
#ifdef FLOAT128
float128 syst_float32_to_float128( float32 );
#endif
float32 syst_float32_round_to_int( float32 );
float32 syst_float32_add( float32, float32 );
float32 syst_float32_sub( float32, float32 );
float32 syst_float32_mul( float32, float32 );
float32 syst_float32_div( float32, float32 );
float32 syst_float32_rem( float32, float32 );
float32 syst_float32_sqrt( float32 );
flag syst_float32_eq( float32, float32 );
flag syst_float32_le( float32, float32 );
flag syst_float32_lt( float32, float32 );
flag syst_float32_eq_signaling( float32, float32 );
flag syst_float32_le_quiet( float32, float32 );
flag syst_float32_lt_quiet( float32, float32 );
int32 syst_float64_to_int32( float64 );
int32 syst_float64_to_int32_round_to_zero( float64 );
#ifdef BITS64
int64 syst_float64_to_int64( float64 );
int64 syst_float64_to_int64_round_to_zero( float64 );
#endif
float32 syst_float64_to_float32( float64 );
#ifdef FLOATX80
floatx80 syst_float64_to_floatx80( float64 );
#endif
#ifdef FLOAT128
float128 syst_float64_to_float128( float64 );
#endif
float64 syst_float64_round_to_int( float64 );
float64 syst_float64_add( float64, float64 );
float64 syst_float64_sub( float64, float64 );
float64 syst_float64_mul( float64, float64 );
float64 syst_float64_div( float64, float64 );
float64 syst_float64_rem( float64, float64 );
float64 syst_float64_sqrt( float64 );
flag syst_float64_eq( float64, float64 );
flag syst_float64_le( float64, float64 );
flag syst_float64_lt( float64, float64 );
flag syst_float64_eq_signaling( float64, float64 );
flag syst_float64_le_quiet( float64, float64 );
flag syst_float64_lt_quiet( float64, float64 );
#ifdef FLOATX80
int32 syst_floatx80_to_int32( floatx80 );
int32 syst_floatx80_to_int32_round_to_zero( floatx80 );
#ifdef BITS64
int64 syst_floatx80_to_int64( floatx80 );
int64 syst_floatx80_to_int64_round_to_zero( floatx80 );
#endif
float32 syst_floatx80_to_float32( floatx80 );
float64 syst_floatx80_to_float64( floatx80 );
#ifdef FLOAT128
float128 syst_floatx80_to_float128( floatx80 );
#endif
floatx80 syst_floatx80_round_to_int( floatx80 );
floatx80 syst_floatx80_add( floatx80, floatx80 );
floatx80 syst_floatx80_sub( floatx80, floatx80 );
floatx80 syst_floatx80_mul( floatx80, floatx80 );
floatx80 syst_floatx80_div( floatx80, floatx80 );
floatx80 syst_floatx80_rem( floatx80, floatx80 );
floatx80 syst_floatx80_sqrt( floatx80 );
flag syst_floatx80_eq( floatx80, floatx80 );
flag syst_floatx80_le( floatx80, floatx80 );
flag syst_floatx80_lt( floatx80, floatx80 );
flag syst_floatx80_eq_signaling( floatx80, floatx80 );
flag syst_floatx80_le_quiet( floatx80, floatx80 );
flag syst_floatx80_lt_quiet( floatx80, floatx80 );
#endif
#ifdef FLOAT128
int32 syst_float128_to_int32( float128 );
int32 syst_float128_to_int32_round_to_zero( float128 );
#ifdef BITS64
int64 syst_float128_to_int64( float128 );
int64 syst_float128_to_int64_round_to_zero( float128 );
#endif
float32 syst_float128_to_float32( float128 );
float64 syst_float128_to_float64( float128 );
#ifdef FLOATX80
floatx80 syst_float128_to_floatx80( float128 );
#endif
float128 syst_float128_round_to_int( float128 );
float128 syst_float128_add( float128, float128 );
float128 syst_float128_sub( float128, float128 );
float128 syst_float128_mul( float128, float128 );
float128 syst_float128_div( float128, float128 );
float128 syst_float128_rem( float128, float128 );
float128 syst_float128_sqrt( float128 );
flag syst_float128_eq( float128, float128 );
flag syst_float128_le( float128, float128 );
flag syst_float128_lt( float128, float128 );
flag syst_float128_eq_signaling( float128, float128 );
flag syst_float128_le_quiet( float128, float128 );
flag syst_float128_lt_quiet( float128, float128 );
#endif

