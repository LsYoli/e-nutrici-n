#ifndef RECETA_H
#define RECETA_H

#include <string>
#include "Traductor.h"

class Receta {
private:
    std::string textoOriginal;
    std::string textoIngles;
    Traductor traductor;
    bool esEspanol;
public:
    void solicitar();
    std::string getTextoIngles() const;
    std::string getTextoInglesCodificado() const;
};

#endif
