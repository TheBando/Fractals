CC = g++

LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ=$(TARGET).o Triangle.o
DEPS=
LIBS=
TARGET=TFractal

all:$(TARGET)

$(TARGET): $(TARGET).o Triangle.o
	g++ $(TARGET).o Triangle.o -o $(TARGET) $(LFLAGS)

$(TARGET).o: $(TARGET).cpp
	g++ -c $(TARGET).cpp

Triangle.o: Triangle.cpp
	g++ -c Triangle.cpp

clean:
	rm $(OBJ)