CC = g++

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := question01
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final Paths
INSTALLBINDIR := /usr/local/bin

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
INCDIRS := $(shell find src/**/* -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst src/%,-I src/%,$(INCDIRS))
BUILDLIST := $(patsubst src/%,$(BUILDDIR)/%,$(INCDIRS))

# Shared Compiler Flags
# CFLAGS := -g -std=c++11 -w
CFLAGS := -g -ggdb -Wall -Wextra -O3 -std=c++0x
INC := -I include $(INCLIST) -I /usr/local/include
LIB :=

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking all targets"
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "Compiling $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGETDIR)

install:
	@echo "Installing $(EXECUTABLE)"; cp $(TARGET) $(INSTALLBINDIR)

distclean:
	@echo "Removing $(EXECUTABLE)"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

.PHONY: clean
