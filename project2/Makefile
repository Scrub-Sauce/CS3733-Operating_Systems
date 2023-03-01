# Makefile for programs in directory ./project3
# ***************************************************************

PROGRAMS = main

# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined

CC = gcc
CFLAGS = 

# ***************************************************************
# Entry to bring the package up to date

all: $(PROGRAMS)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    scratch -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

# ***************************************************************
# C compilations
    
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# ***************************************************************
# Executable programs
    
main: main.o
	$(CC) $(CFLAGS) main.o -o main