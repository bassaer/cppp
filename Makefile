COMPILER  = g++
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers
LDFGAGS   = -L/usr/lib64 -lcppunit -lCppUTestExt
LIBS      =
INCLUDE   = -I./include
TARGET    = ./bin/$(shell basename `readlink -f .`)
TEST      = ./bin/test
SRCDIR    = ./src
TESTDIR   = ./tests
ifeq "$(strip $(SRCDIR))" ""
	SRCDIR  = .
endif
SOURCES   = $(wildcard $(SRCDIR)/*.cpp)
TESTS     = $(wildcard $(TESTDIR)/*.cpp)
OBJDIR    = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR  = .
endif
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET) run

test: $(TESTDIR)
	$(COMPILER) $(TESTS) $(LDFLAGS) -o $(TEST)

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

run:  
	$(TARGET)

-include $(DEPENDS)
