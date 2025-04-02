# Variables
CXX = g++                   # Especifica el compilador
CXXFLAGS = -Wall -std=c++11  -I/usr/include/nlohmann # Opciones del compilador: -Wall para las advertencias y -std=c++11 para usar C++11
LIBS = -lcurl                # Especifica que se debe enlazar la biblioteca curl


# Nombre del ejecutable
TARGET = programa

# Archivos fuente
SRCS = main.cpp

# Archivos objeto (se generan automáticamente a partir de SRCS)
OBJS = $(SRCS:.cpp=.o)

# Regla principal: compilar todo
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)   # Enlaza los objetos y la biblioteca curl

# Regla para compilar archivos .cpp a archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos generados (.o y el ejecutable)
clean:
	rm -f $(OBJS) $(TARGET)