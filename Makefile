CXX = g++
CXXFLAGS = -std=c++11

all: nutricion

nutricion: main.o Receta.o AnalisisNutricional.o Traductor.o
	$(CXX) $(CXXFLAGS) -o nutricion main.o Receta.o AnalisisNutricional.o Traductor.o -lcurl

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Receta.o: Receta.cpp
	$(CXX) $(CXXFLAGS) -c Receta.cpp

AnalisisNutricional.o: AnalisisNutricional.cpp
	$(CXX) $(CXXFLAGS) -c AnalisisNutricional.cpp

Traductor.o: Traductor.cpp
	$(CXX) $(CXXFLAGS) -c Traductor.cpp

clean:
	rm -f *.o nutricion
