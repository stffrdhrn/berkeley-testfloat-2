
/*============================================================================

This C source file template is part of Berkeley TestFloat, Release 2c, a
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

#include "milieu.h"
#include "systmodes.h"

/*----------------------------------------------------------------------------
| Sets the system's IEEE floating-point rounding mode.  Also disables all
| system exception traps.
*----------------------------------------------------------------------------*/
void syst_float_set_rounding_mode( int8 roundingMode )
{

    !!!code

}

/*----------------------------------------------------------------------------
| Sets the rounding precision of subsequent double-extended-precision
| operations.  The `precision' argument should be one of 0, 32, 64, or 80.
| If `precision' is 32, the rounding precision is set equivalent to single
| precision; else if `precision' is 64, the rounding precision is set
| equivalent to double precision; else the rounding precision is set to full
| double-extended-precision.
*----------------------------------------------------------------------------*/
void syst_float_set_rounding_precision( int8 precision )
{

    !!!code (possibly empty)

}

