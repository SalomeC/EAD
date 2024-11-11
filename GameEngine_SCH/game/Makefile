# Compiler and directory settings
CC = g++
CXXFLAGS = -std=c++17 -Wall -fPIC -I$(INCLUDEDIR) -I./private_include
LDFLAGS = -L../engine -lEngine
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = ../include
APPNAME = game

# File management - List all .cpp files in src
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Debug information
# $(info SRC: $(SRC))
# $(info OBJ: $(OBJ))

# Build the game executable
all: $(APPNAME)

$(APPNAME): $(OBJ)
	@echo "Linking executable..."
	$(CC) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS)

# Compile .o files from .cpp sources in src
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $< to $@..."
	mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Dependency: Build the engine if its library doesn’t exist
../engine/libEngine.so:
	$(MAKE) -C ../engine

# Run target to set LD_LIBRARY_PATH and execute the program
run: $(APPNAME)
	LD_LIBRARY_PATH=../engine:$$LD_LIBRARY_PATH ./$(APPNAME)


# Clean up
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(APPNAME)
