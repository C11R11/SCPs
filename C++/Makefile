#g++ -std=c++17 -ggdb -Iinclude src/hello.cpp src/main.cpp -o bin/main.exe

#CXX = g++
CXX_FLAGS = -std=c++17 -ggdb
 
SRC := src
BIN := bin
OBJ := $(SRC)/*.cpp
INCLUDE := -Iinclude $(OBJ)
EXECUTABLE := $(BIN)/hello.exe

all: hello
 
hello: $(OBJ) 
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -o $(EXECUTABLE)
 
.PHONY: clean
clean: Remove-Item $(EXECUTABLE)