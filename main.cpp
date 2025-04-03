#include <iostream>
#include "Receta.h"
#include "AnalisisNutricional.h"

int main() {
    Receta receta;
    receta.solicitar();

    AnalisisNutricional analisis;
    std::string respuestaJSON = analisis.consultarAPI(receta);
    analisis.mostrarResumen(respuestaJSON);

    return 0;
}
