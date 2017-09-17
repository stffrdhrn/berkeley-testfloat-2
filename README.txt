
Package Overview for Berkeley TestFloat Release 2c

John R. Hauser
2015 January 30


----------------------------------------------------------------------------
Overview

Berkeley TestFloat is a program for testing that a binary floating-point
implementation conforms to the IEEE Standard for Floating-Point Arithmetic.
Release 2c updates an older version of TestFloat that has for most purposes
been supplanted by Release 3 or later.  For the latest version of TestFloat,
see Web page `http://www.jhauser.us/arithmetic/TestFloat.html'.

TestFloat is distributed in the form of C source code.  For Release 2c, the
TestFloat package actually provides two related programs:

-- The `testfloat' program tests a system's binary floating-point for
   conformance to the IEEE Standard.  This program uses the Berkeley
   SoftFloat software floating-point implementation as a basis for
   comparison.

-- The `testsoftfloat' program tests SoftFloat itself for conformance
   to the IEEE Standard.  These tests are performed by comparing against
   a separate, slower software floating-point that is included in the
   TestFloat package.

TestFloat depends on Berkeley SoftFloat, but SoftFloat is not included
in the TestFloat package.  SoftFloat can be obtained through the Web page
`http://www.jhauser.us/arithmetic/SoftFloat.html'.

This version of TestFloat is documented in three text files:

   testfloat.txt          Documentation for using the TestFloat programs
                             (both `testfloat' and `testsoftfloat').
   testfloat-source.txt   Documentation for porting and compiling TestFloat.
   testfloat-history.txt  History of major changes to TestFloat.

Other files in the package comprise the source code for TestFloat.

Please be aware that some work is involved in porting this software to other
targets.  It is not just a matter of getting `make' to complete without
error messages.  You should not attempt to compile this release of TestFloat
without first reading `testfloat-source.txt'.  Depending on your needs, you
may find that newer versions of TestFloat are less work to port.


----------------------------------------------------------------------------
Legal Notice

TestFloat was written by John R. Hauser.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort
has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT
TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO
PERSONS AND ORGANIZATIONS WHO CAN AND WILL TOLERATE ALL LOSSES, COSTS, OR
OTHER PROBLEMS THEY INCUR DUE TO THE SOFTWARE WITHOUT RECOMPENSE FROM JOHN
HAUSER, AND WHO FURTHERMORE EFFECTIVELY INDEMNIFY JOHN HAUSER (possibly via
similar legal notice) AGAINST ALL LOSSES, COSTS, OR OTHER PROBLEMS INCURRED
BY THEIR CUSTOMERS AND CLIENTS DUE TO THE SOFTWARE, OR INCURRED BY ANYONE
DUE TO A DERIVATIVE WORK THEY CREATE USING ANY PART OF THE SOFTWARE.

The following are expressly permitted, even for commercial purposes:
(1) distribution of TestFloat in whole or in part, as long as this and
other legal notices remain and are prominent, and provided also that, for a
partial distribution, prominent notice is given that it is a subset of the
original; and
(2) inclusion or use of TestFloat in whole or in part in a derivative
work, provided that the use restrictions above are met and the minimal
documentation requirements stated in the source code are satisfied.


----------------------------------------------------------------------------
Contact Information

At the time of this writing, the most up-to-date information about TestFloat
and the latest release can be found at the Web page `http://www.jhauser.us/
arithmetic/TestFloat.html'.

