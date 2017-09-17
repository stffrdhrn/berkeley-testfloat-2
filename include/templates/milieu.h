
/*============================================================================

This C header file template is part of Berkeley TestFloat, Release 2c, a
package of programs for testing the correctness of floating-point arithmetic
complying with the IEEE Standard for Floating-Point, by John R. Hauser.

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

/*----------------------------------------------------------------------------
| Include common integer types and flags.
*----------------------------------------------------------------------------*/
#include "../../processors/!!!processor.h"

/*----------------------------------------------------------------------------
| If the `BITS64' macro is defined by the processor header file but the
| version of SoftFloat being used/tested is the 32-bit one (`bits32'), the
| `BITS64' macro must be undefined here.
*----------------------------------------------------------------------------*/
#if 0
#undef BITS64
#endif

/*----------------------------------------------------------------------------
| The macro `LONG_DOUBLE_IS_FLOATX80' can be defined to indicate that the
| C compiler supports the type `long double' as an double-extended-precision
| format.  Alternatively, the macro `LONG_DOUBLE_IS_FLOAT128' can be defined
| to indicate that `long double' is a quadruple-precision format.  If neither
| of these macros is defined, `long double' will be ignored.
*----------------------------------------------------------------------------*/
#if 0
#define LONG_DOUBLE_IS_FLOATX80
#endif

/*----------------------------------------------------------------------------
| Symbolic Boolean literals.
*----------------------------------------------------------------------------*/
enum {
    FALSE = 0,
    TRUE  = 1
};

