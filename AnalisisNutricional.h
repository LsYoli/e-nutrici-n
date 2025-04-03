#ifndef ANALISISNUTRICIONAL_H
#define ANALISISNUTRICIONAL_H
#include <string>
#include "Receta.h"
class AnalisisNutricional {
public:
    std::string consultarAPI(const Receta& receta);
    void mostrarResumen(const std::string& json);
};
#endif