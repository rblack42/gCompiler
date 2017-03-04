# generic Makefile for COSC2325

# set the executable name
BIN     := gCompiler
TEST    := unit_test

LIBS    := math

SRCDIR  :=  src/
LIBDIR  :=  lib/
TSTDIR  :=  tests/
DOCDIR  :=  docs/
OBJDIR  :=  _obj/
INCDIR  := include/

CXX     := g++
CFLAGS  := -I $(INCDIR) -std=c++11
LFLAGS  :=

RM      := rm -f
PIP     := _venv/bin/pip
VENV    := virtulenv

# get a list of the app sources and the library sources
MSRCS   := $(wildcard $(SRCDIR)*.cpp)
LSRCS   := $(wildcard $(LIBDIR)*.cpp)
ISRCS   := $(wildcard $(INCDIR)*.h)
TSRCS   := $(wildcard $(TSTDIR)*.cpp)

# generate a list of all obj files to create
MOBJS    := $(MSRCS:%.cpp=$(OBJDIR)%.o)
LOBJS    := $(LSRCS:%.cpp=$(OBJDIR)%.o)
TOBJS    := $(TSRCS:%.cpp=$(OBJDIR)%.o)


# denerate a list of all dependency files to create
LDEPS   := $(LOBJS:.o=.d)
TDEPS   := $(TOBJS:.o=.d)

# rules section -----------------------------------------------

# primary application build rule
.PHONY: all
all:    $(BIN) $(TEST) | $(OBJDIR)

.PHONY: run
run:    $(BIN)
		./$(BIN) -d tests/test.c

.PHONY: test
test:   $(BIN) $(TEST)
		./$(TEST)

$(BIN): $(MOBJS) $(LOBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

$(TEST): $(TOBJS) $(LOBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

# build rules for Sphnx documentation
.PHONY: reqs
reqs:   init _venv
	$(PIP) install -r requirements.txt

_venv:
	$(VENV) _venv

.PHONY: docs
docs:   reqs _venv
	sphinx-build -b html -d _build/doctrees . _build/html

.PHONY: pdf
pdf:
	sphinx-build -b latex -d _build/doctrees . _build/latex
	cd _build/latex && pdflatex CPUkit.tex

# implicit rule to build any obj file and associated dependency file
$(OBJDIR)%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD -MP

# create project folders if needed
.PHONY: init
init:
	mkdir -p $(SRCDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(TSTDIR)
	mkdir -p $(DOCDIR)

# create object directories only if needed
$(OBJDIR):
	mkdir -p $(OBJDIR)$(SRCDIR)
	mkdir -p $(OBJDIR)$(LIBDIR)
	mkdir -p $(OBJDIR)$(TSTDIR)

# remove all constructed files
.PHONY: clean
clean:
	$(RM) $(BIN) $(TEST) \
    $(MOBJS) $(LOBJS) $(TOBJS) \
    $(MDEPS) $(LDEPS) $(TDEPS)

# show file lists
.PHONY: debug
debug:
	-@echo MSRCS = $(MSRCS)
	-@echo LSRCS = $(LSRCS)
	-@echo ISRCS = $(ISRCS)
	-@echo TSRCS = $(TSRCS)
	-@echo MOBJS = $(MOBJS)
	-@echo TOBJS = $(TOBJS)
	-@echo LDEPS = $(LDEPS)
	-@echo TDEPS = $(TDEPS)

# include compiler generated dependencies
-include $(OBJDIR)*.d

