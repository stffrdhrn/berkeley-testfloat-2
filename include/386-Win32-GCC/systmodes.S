
/*============================================================================

This GNU assembler source file is part of Berkeley TestFloat, Release 2c, a
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

	.text

/*----------------------------------------------------------------------------
| Sets the system's IEEE floating-point rounding mode.  Also disables all
| system exception traps.
*----------------------------------------------------------------------------*/
	.align 4
	.global syst_float_set_rounding_mode
syst_float_set_rounding_mode:
	movb 4(%esp),%al
	andb $3,%al
	shlw $10,%ax
	orw $63,%ax
	subl $2,%esp
	fnstcw 0(%esp)
	andw $768,0(%esp)
	orw %ax,0(%esp)
	fldcw 0(%esp)
	addl $2,%esp
	ret

/*----------------------------------------------------------------------------
| Sets the rounding precision of subsequent double-extended-precision
| operations.  The `precision' argument should be one of 0, 32, 64, or 80.
| If `precision' is 32, the rounding precision is set equivalent to single-
| precision; else if `precision' is 64, the rounding precision is set
| equivalent to double-precision; else the rounding precision is set to full
| double-extended-precision.
*----------------------------------------------------------------------------*/
	.align 4
	.global syst_float_set_rounding_precision
syst_float_set_rounding_precision:
	movb 4(%esp),%al
	movb $0,%ah
	cmpb $32,%al
	je setRoundingPrecision
	movb $2,%ah
	cmpb $64,%al
	je setRoundingPrecision
	movb $3,%ah
	cmpb $80,%al
	je setRoundingPrecision
	movb $0,%ah
setRoundingPrecision:
	movb $0,%al
	subl $2,%esp
	fnstcw 0(%esp)
	andw $64767,0(%esp)
	orw %ax,0(%esp)
	fldcw 0(%esp)
	addl $2,%esp
	ret

