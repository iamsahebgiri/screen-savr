OBJS = main.cc
OBJ_NAME = main

INCLUDE_PATHS = -IC:/msys64/mingw64/include/SFML
LIBRARY_PATHS = -LC:/msys64/mingw64/lib

COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJS)
	g++ -o $(OBJ_NAME) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)
	./$(OBJ_NAME)