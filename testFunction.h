
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

============================================================================*/

enum {
    INT32_TO_FLOAT32 = 1,
    INT32_TO_FLOAT64,
    INT32_TO_FLOATX80,
    INT32_TO_FLOAT128,
    INT64_TO_FLOAT32,
    INT64_TO_FLOAT64,
    INT64_TO_FLOATX80,
    INT64_TO_FLOAT128,
    FLOAT32_TO_INT32,
    FLOAT32_TO_INT32_ROUND_TO_ZERO,
    FLOAT32_TO_INT64,
    FLOAT32_TO_INT64_ROUND_TO_ZERO,
    FLOAT32_TO_FLOAT64,
    FLOAT32_TO_FLOATX80,
    FLOAT32_TO_FLOAT128,
    FLOAT32_ROUND_TO_INT,
    FLOAT32_ADD,
    FLOAT32_SUB,
    FLOAT32_MUL,
    FLOAT32_DIV,
    FLOAT32_REM,
    FLOAT32_SQRT,
    FLOAT32_EQ,
    FLOAT32_LE,
    FLOAT32_LT,
    FLOAT32_EQ_SIGNALING,
    FLOAT32_LE_QUIET,
    FLOAT32_LT_QUIET,
    FLOAT64_TO_INT32,
    FLOAT64_TO_INT32_ROUND_TO_ZERO,
    FLOAT64_TO_INT64,
    FLOAT64_TO_INT64_ROUND_TO_ZERO,
    FLOAT64_TO_FLOAT32,
    FLOAT64_TO_FLOATX80,
    FLOAT64_TO_FLOAT128,
    FLOAT64_ROUND_TO_INT,
    FLOAT64_ADD,
    FLOAT64_SUB,
    FLOAT64_MUL,
    FLOAT64_DIV,
    FLOAT64_REM,
    FLOAT64_SQRT,
    FLOAT64_EQ,
    FLOAT64_LE,
    FLOAT64_LT,
    FLOAT64_EQ_SIGNALING,
    FLOAT64_LE_QUIET,
    FLOAT64_LT_QUIET,
    FLOATX80_TO_INT32,
    FLOATX80_TO_INT32_ROUND_TO_ZERO,
    FLOATX80_TO_INT64,
    FLOATX80_TO_INT64_ROUND_TO_ZERO,
    FLOATX80_TO_FLOAT32,
    FLOATX80_TO_FLOAT64,
    FLOATX80_TO_FLOAT128,
    FLOATX80_ROUND_TO_INT,
    FLOATX80_ADD,
    FLOATX80_SUB,
    FLOATX80_MUL,
    FLOATX80_DIV,
    FLOATX80_REM,
    FLOATX80_SQRT,
    FLOATX80_EQ,
    FLOATX80_LE,
    FLOATX80_LT,
    FLOATX80_EQ_SIGNALING,
    FLOATX80_LE_QUIET,
    FLOATX80_LT_QUIET,
    FLOAT128_TO_INT32,
    FLOAT128_TO_INT32_ROUND_TO_ZERO,
    FLOAT128_TO_INT64,
    FLOAT128_TO_INT64_ROUND_TO_ZERO,
    FLOAT128_TO_FLOAT32,
    FLOAT128_TO_FLOAT64,
    FLOAT128_TO_FLOATX80,
    FLOAT128_ROUND_TO_INT,
    FLOAT128_ADD,
    FLOAT128_SUB,
    FLOAT128_MUL,
    FLOAT128_DIV,
    FLOAT128_REM,
    FLOAT128_SQRT,
    FLOAT128_EQ,
    FLOAT128_LE,
    FLOAT128_LT,
    FLOAT128_EQ_SIGNALING,
    FLOAT128_LE_QUIET,
    FLOAT128_LT_QUIET,
    NUM_FUNCTIONS
};

typedef struct {
    char *name;
    int8 numInputs;
    flag roundingPrecision, roundingMode;
} functionT;
extern const functionT functions[ NUM_FUNCTIONS ];
extern const flag functionExists[ NUM_FUNCTIONS ];

enum {
    ROUND_NEAREST_EVEN = 1,
    ROUND_TO_ZERO,
    ROUND_DOWN,
    ROUND_UP,
    NUM_ROUNDINGMODES
};

void testFunction( uint8, int8, int8 );

