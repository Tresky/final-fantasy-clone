# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -pedantic -Wall

# Relative directories
ODIR = obj

#Libraries to link to
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -llua -L/usr/local/lib
INCS = -I/usr/local/include



#### OBJECT FILES ####
# Utilities Objects
_UTIL_OBJ = logger.o
UTIL_OBJ = $(patsubst %, $(ODIR)/%, $(_UTIL_OBJ))

# Engine Objects
_ENG_OBJ = system.o video.o modes.o
ENG_OBJ = $(patsubst %, $(ODIR)/%, $(_ENG_OBJ))



#### DEPENDENCY HEADER FILES ####
# Utilities Headers
_UTIL_DEP = logger.hpp
UTIL_DEP = $(patsubst %, ./src/utils/%, $(_UTIL_DEP))

# Engine Headers
_ENG_DEP = system.hpp video.hpp modes.hpp
ENG_DEP = $(patsubst %, ./src/core/%, $(_ENG_DEP))




#### RULES ####
# Links object files and libraries into executable
rpg: $(UTIL_OBJ) $(ENG_OBJ) obj/main.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS) $(INCS)

# Compiles utility code from /src/utils/*
$(ODIR)/%.o: ./src/utils/%.cpp $(UTIL_DEP)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Compiles engine from /src/core/*
$(ODIR)/%.o: ./src/core/%.cpp $(ENG_DEP)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Compiles the main.cpp file and places the object
# file in the obj/ directory.
$(ODIR)/main.o: ./src/main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)



#### CLEANUP ####
# Ensures that the clean 'rule' isn't mistaken for
# a file name. If a file called 'clean' were made and
# this line wasn't present, the 'clean' file would not
# compile because it has no prerequisites and would be
# considered up-to-date all the time.
#
# NOTE: Rules only activate if the dependant files
# (right side of colon) have changed since the last time
# the make was run.
.PHONY: clean

# Ran independantly.
# Deletes all object files and the executable.
clean:
	rm -f $(ODIR)/*.o #*~ core ./src/*~
	rm -f rpg
