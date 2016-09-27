# Makefile-6
#
# Some decorations (final version)!
#
#

C_OBJS    = main.o hello.o world.o
C_HEADERS = hello.h world.h
EXE       = R5

CC        = gcc
CC_FLAGS  = -std=c11 -g -Wall -c
LD_FLAGS  = -std=c11 -g -Wall

################################################################################

# Linking step
R5: $(C_OBJS)
	@echo "Linking..."
	$(CC) $(LD_FLAGS) $(C_OBJS) -o $(EXE)
	@echo ""

# Recompiles everything if headers change
$(C_OBJS): $(C_HEADERS)

# Compiling step
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CC_FLAGS) $<
	@echo ""

# Clean the directory in order to later build from scratch
clean:
	rm -rf *.o $(EXE)
package:
	tar -cvf package.tar *.h *.c
nickCage:
	firefox https://www.cs.colostate.edu/~habeeb
