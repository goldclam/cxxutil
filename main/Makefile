EXECUTABLE := a.out

BUILDDIR := build
OBJDIR = $(BUILDDIR)/obj
APPDIR = $(BUILDDIR)/bin

SRCROOTDIR := src
SRCDIRS = $(shell find $(SRCROOTDIR) -type d)
SRCINC = $(addprefix -I,$(SRCROOTDIR))

CPPFILES != find src -name "*.cpp"
#CPPFILES = $(shell find $(SRCROOTDIR) -name "*.cpp")
CCFILES != find src -name "*.cc"
#CCFILES = $(shell find $(SRCROOTDIR) -name "*.cc")
SRCS = $(CPPFILES) $(CCFILES)
OBJS = $(filter %.o,$(SRCS:%.cc=$(OBJDIR)/%.o)) \
       $(filter %.o,$(SRCS:%.cpp=$(OBJDIR)/%.o))
DEPS = $(OBJS:%o=%d)

GTESTINC := -Iexternal/googletest/include
GTESTLIB := -Lexternal/googletest -lgtest
JSONCPPINC := -Iexternal/jsoncpp/include
JSONCPPLIB := -Lexternal/jsoncpp -ljsoncpp

CXX := g++
CXXFLAGS ?= -W -Wall \
            -std=c++14 -MMD -pthread
CXXFLAGS_ROBUST = $(CXXFLAGS) -pedantic-errors -Wextra -Werror

INCLUDE = -I. -Iinclude $(SRCINC) $(GTESTINC) $(JSONCPPINC)
LDFLAGS = -L/usr/lib -lstdc++ -lm -lcurl $(GTESTLIB) $(JSONCPPLIB)


###########################
# PHONY RECIPES
###########################
all: build $(APPDIR)/$(EXECUTABLE)
.PHONY: all


build:
	@mkdir -p $(APPDIR)
	@mkdir -p $(OBJDIR)
.PHONY: build


debug: CXXFLAGS += -DDEBUG -g
debug: all
.PHONY: debug


release: CXXFLAGS += -O2
release: all
.PHONY: release


clean:
	-@rm -rvf $(BUILDDIR)
.PHONY: clean


run: all
	@$(APPDIR)/$(EXECUTABLE)
.PHONY: run


############################
# FOR MAKE DEBUG
#
# Just checks value of variable
#
# USAGE: $ make print-<VARIABLE NAME>
# EX: $ make print-SRCDIRS
############################
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true


############################
# PATTERN RULES
#
# If MAKE is facing any type of file extension included in PATTERN RULES then
# MAKE will make EXECUTABLE extension(file) using sepcified recipes.
############################
## Compile into object files but not link executable
$(OBJDIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

## Link object files into executable
## IMPORTANT!!! $(LDFLAGS) should be placed behind of $(SRCS) or $(OBJS)
## so that $(SRCS) or $(OBJS) can find symbols in 3rd libraries
$(APPDIR)/$(EXECUTABLE): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APPDIR)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)


############################
# Include DEPS for header incremental build
############################
-include $(DEPS)