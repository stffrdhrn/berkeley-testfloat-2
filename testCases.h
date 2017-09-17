
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

void testCases_setLevel( int8 );

void testCases_initSequence( int8 );
enum {
    testCases_sequence_a_int32,
#ifdef BITS64
    testCases_sequence_a_int64,
#endif
    testCases_sequence_a_float32,
    testCases_sequence_ab_float32,
    testCases_sequence_a_float64,
    testCases_sequence_ab_float64,
#ifdef FLOATX80
    testCases_sequence_a_floatx80,
    testCases_sequence_ab_floatx80,
#endif
#ifdef FLOAT128
    testCases_sequence_a_float128,
    testCases_sequence_ab_float128,
#endif
};

extern uint32 testCases_total;
extern flag testCases_done;

void testCases_next( void );

extern int32 testCases_a_int32;
#ifdef BITS64
extern int64 testCases_a_int64;
#endif
extern float32 testCases_a_float32;
extern float32 testCases_b_float32;
extern float64 testCases_a_float64;
extern float64 testCases_b_float64;
#ifdef FLOATX80
extern floatx80 testCases_a_floatx80;
extern floatx80 testCases_b_floatx80;
#endif
#ifdef FLOAT128
extern float128 testCases_a_float128;
extern float128 testCases_b_float128;
#endif

