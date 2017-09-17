
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
#include "milieu.h"
#include "random.h"

uint8 randomUint8( void )
{

    return (bits8) ( rand()>>4 );

}

uint16 randomUint16( void )
{

    return ( ( rand() & 0x0FF0 )<<4 ) | ( ( rand()>>4 ) & 0xFF );

}

uint32 randomUint32( void )
{

    return
          ( ( (uint32) ( rand() & 0x0FF0 ) )<<20 )
        | ( ( (uint32) ( rand() & 0x0FF0 ) )<<12 )
        | ( ( rand() & 0x0FF0 )<<4 )
        | ( ( rand()>>4 ) & 0xFF );

}

#ifdef BITS64

uint64 randomUint64( void )
{

    return ( ( (uint64) randomUint32() )<<32 ) | randomUint32();

}

#endif

