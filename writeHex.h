
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

#include <stdio.h>

void writeHex_flag( flag, FILE * );
void writeHex_bits32( bits32, FILE * );
#ifdef BITS64
void writeHex_bits64( bits64, FILE * );
#endif
void writeHex_float32( float32, FILE * );
void writeHex_float64( float64, FILE * );
#ifdef FLOATX80
void writeHex_floatx80( floatx80, FILE * );
#endif
#ifdef FLOAT128
void writeHex_float128( float128, FILE * );
#endif
void writeHex_float_flags( uint8, FILE * );

