CXX=g++
CXXFLAGS=-Wall -march=native -O3 -pipe

main: main.cpp
	$(CXX) main.cpp -o MyProgram $(CXXFLAGS)
	@echo "Compilation finished"
