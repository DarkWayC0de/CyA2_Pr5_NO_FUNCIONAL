CC=g++
CXXFLAGS=-g -std=c++17 -pedantic
ODIR=src
BUILD=build

_OBJ=$(BUILD)/ER2Tree.o $(BUILD)/AnalizadorER.o  
OBJ=$(patsubst %,%,$(_OBJ))

all:ER2Tree
$(BUILD)/ER2Tree.o: $(ODIR)/ER2Tree.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD)/AnalizadorER.o: $(ODIR)/AnalizadorER.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)


ER2Tree: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) -lm

.PHONY:clean

clean:
	rm -rf build/* ER2Tree

