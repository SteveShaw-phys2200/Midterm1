CC=gcc
# flags for compiling .c's
CFLAGS=-c -std=c99 -Wall -lm
# flags for compiling .o's
OFLAGS=-lm
# list of .h's
DEPS= pi_funs.h
# list of dependent .c's
SOURCES=Midterm1.c pi_leibniz.c pi_bbp.c
# .o's from .c's
OBJECTS=$(SOURCES:.c=.o)
# final binary produced is Midterm1
EXECUTABLE=Midterm1
# files to be deleted with clean
CLEANFILES= *.o *.c~ *.o~ *.h~ Midterm~ makefile~

all: $(SOURCES) $(EXECUTABLE)
	# sucsess!

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OFLAGS) $(OBJECTS) -o $@

.c.o: $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(CLEANFILES)
	# clean!

veryclean: clean
	rm -f $(EXECUTABLE)
	# squeky clean!
