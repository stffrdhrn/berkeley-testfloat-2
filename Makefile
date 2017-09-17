
ARCH = 386-Win32-GCC
SOFTFLOAT_DIR = ../berkeley-softfloat-2

VPATH = ./include/$(ARCH):$(SOFTFLOAT_DIR)/include/$(ARCH)

OBJ = .o
# When on windows
#EXE = .exe
CC = gcc
INCLUDES = -I. -I./include/$(ARCH) \
	-I$(SOFTFLOAT_DIR) \
	-I$(SOFTFLOAT_DIR)/include/$(ARCH)
CFLAGS = $(INCLUDES) -O2 -Wall -Werror
COMPILE_ASM = $(CC) -c -o $@
COMPILE_C = $(CC) -c -o $@ $(CFLAGS)
LINK = $(CC) -o $@

SOFTFLOAT_OBJ = $(SOFTFLOAT_DIR)/softfloat$(OBJ)

ALL: testsoftfloat$(EXE) testfloat$(EXE)

fail$(OBJ): milieu.h fail.h
	$(COMPILE_C) fail.c

random$(OBJ): milieu.h random.h
	$(COMPILE_C) random.c

testCases$(OBJ): milieu.h fail.h random.h softfloat.h testCases.h testCases.c
	$(COMPILE_C) testCases.c

writeHex$(OBJ): milieu.h $(SOFTFLOAT_H) writeHex.h writeHex.c
	$(COMPILE_C) writeHex.c

testLoops$(OBJ): milieu.h $(SOFTFLOAT_H) testCases.h writeHex.h testLoops.h testLoops.c
	$(COMPILE_C) testLoops.c

slowfloat$(OBJ): milieu.h $(SOFTFLOAT_H) slowfloat.h slowfloat-32.c slowfloat-64.c slowfloat.c
	$(COMPILE_C) slowfloat.c

testsoftfloat$(OBJ): milieu.h fail.h $(SOFTFLOAT_H) testCases.h testLoops.h slowfloat.h testsoftfloat.c
	$(COMPILE_C) testsoftfloat.c

testsoftfloat$(EXE): fail$(OBJ) random$(OBJ) $(SOFTFLOAT_OBJ) testCases$(OBJ) writeHex$(OBJ) testLoops$(OBJ) slowfloat$(OBJ) testsoftfloat$(OBJ)
	$(LINK) fail$(OBJ) random$(OBJ) $(SOFTFLOAT_OBJ) testCases$(OBJ) writeHex$(OBJ) testLoops$(OBJ) slowfloat$(OBJ) testsoftfloat$(OBJ)

systmodes$(OBJ): systmodes.S
	$(COMPILE_ASM) ./include/$(ARCH)/systmodes.S

systflags$(OBJ): systflags.S
	$(COMPILE_ASM) ./include/$(ARCH)/systflags.S

# compile systfloat ingnoring warnings of type punning
systfloat$(OBJ): systfloat.c
	$(CC) -c $(INCLUDES) -O2 -o $@ systfloat.c

testFunction$(OBJ): milieu.h $(SOFTFLOAT_H) testCases.h testLoops.h systmodes.h systflags.h systfloat.h testFunction.h testFunction.c
	$(COMPILE_C) testFunction.c

testfloat$(OBJ): milieu.h fail.h $(SOFTFLOAT_H) testCases.h testLoops.h systflags.h testFunction.h testfloat.c
	$(COMPILE_C) testfloat.c

testfloat$(EXE): fail$(OBJ) random$(OBJ) $(SOFTFLOAT_OBJ) testCases$(OBJ) writeHex$(OBJ) testLoops$(OBJ) systmodes$(OBJ) systflags$(OBJ) systfloat$(OBJ) testFunction$(OBJ) testfloat$(OBJ)
	$(LINK) -lm fail$(OBJ) random$(OBJ) $(SOFTFLOAT_OBJ) testCases$(OBJ) writeHex$(OBJ) testLoops$(OBJ) systmodes$(OBJ) systflags$(OBJ) systfloat$(OBJ) testFunction$(OBJ) testfloat$(OBJ)

clean:
	rm -f *$(OBJ) testfloat$(EXE) testsoftfloat$(EXE)
