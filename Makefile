CXX=g++
CXXFLAGS=-Wall -std=c++14 $(DEBUG)

LDLIBS=$(shell sdl2-config --libs)

SRCDIR=src
BIN=bin
INCLUDE=include
BUILD=build
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp, $(BIN)/%.o, $(SRC))
DEPS := -I$(INCLUDE) $(shell sdl2-config --cflags)

TARGET=$(BUILD)/chess

MKDIR=mkdir -p
RM=rm -rf

$(BIN)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(DEPS)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

build_dir:
	@$(MKDIR) $(BUILD)
	@$(MKDIR) $(BIN)

all: build_dir $(TARGET)

debug: DEBUG=-DDEBUG -g
debug: all

.PHONY:
clean:
	$(RM) $(BUILD) $(BIN)

