# MAKEFILE FOR GAME ENGINE

# Compiler and directory settings
CC = g++
CXXFLAGS = -std=c++17 -Wall -fPIC -I../include -I./private_include
LDFLAGS = -shared -lspdlog -lfmt -lglfw
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = ../include
TARGET = libEngine.so

# File management
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)

# Build the shared library
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile .o files from .cpp sources
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Generate dependencies with INCLUDEDIR
%.d: $(SRCDIR)/%.cpp
	@$(CC) $(CXXFLAGS) -I$(INCLUDEDIR) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) > $@

# Include dependency files
-include $(DEP)

# Clean up
.PHONY: clean
clean:
	rm -f $(OBJ) $(DEP) $(TARGET)
