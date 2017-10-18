COMPILER  = g++
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers
LDFLAGS   = -lcppunit 
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

all: clean $(TEST) $(TARGET) test run

$(TEST): $(TESTDIR)
	$(COMPILER) $(TESTS) $(LDFLAGS) -o $@ 

clean:
	-rm -f $(OBJECTS) $(DEPENDS) $(TARGET) $(TEST)

run:  
	$(TARGET)

test:
	$(TEST)

-include $(DEPENDS)
