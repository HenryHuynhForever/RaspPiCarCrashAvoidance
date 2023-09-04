CXX=g++
CXXFLAGS=-Wall -march=native -O3 -pipe -lwiringPi

main: main.cpp
	@echo "[Compilation started]\n"
	$(CXX) main.cpp -o MyProgram $(CXXFLAGS)
	@echo "\n[Compilation finished]"
