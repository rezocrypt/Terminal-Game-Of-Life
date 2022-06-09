TARGET = GameOfLife
CC = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, .%.o, $(SRC))

$(TARGET) : $(OBJ) 
	$(CC) $(OBJ) -o $(TARGET)

.%.o : %.cpp
	$(CC) -w -c $< -o  $@

clear:
	rm .*.o
	rm GameOfLife
