#
# This is the Makefile for the progam rc_cad.

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
#  for C++ define  CC = g++
CC = g++
#CC = win_g++



#CFLAGS  = -g -Wall
CFLAGS  = -g -std=c++17



#perferred progam name (executable)
EXECUTABLE = ex3


# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but default or all
# are the most commonly used names by convention
#
default: $(EXECUTABLE)


#define header files
INCLUDES = -I/../Matrix.hxx
INCLUDES += -I/../Matrix3D.hxx
INCLUDES += -I/../Vector3D.hxx


#define the source files
SOURCES = ex3.cxx
SOURCES += ../Matrix.cxx
SOURCES += ../Matrix3D.cxx
SOURCES += ../Vector3D.cxx

#define object file names from source file names
OBJECTS = $(SOURCES:.c=.o)

# library paths

# To create the executable file $(PROG_NAME) we need
# all the object files.
$(EXECUTABLE):  $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(INCLUDES)

clean:
	$(RM) $(EXECUTABLE) *.o *~

depend:$(SOURCES)
	makedepend $(INCLUDES) $^
