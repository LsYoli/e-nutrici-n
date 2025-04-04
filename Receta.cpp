#include "Receta.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <limits>

void Receta::solicitar() {
    std::cout << "¿En qué idioma deseas ingresar tu receta? (es/en): ";
    std::string idioma;
    std::cin >> idioma;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

    esEspanol = (idioma == "es");

    std::cout << "Ingresa tu receta (" << (esEspanol ? "español" : "inglés") << "):\n> ";
    std::getline(std::cin, textoOriginal); // Leer la receta

    if (textoOriginal.empty()) {
        std::cerr << "❌ No ingresaste ningún texto. Intenta de nuevo.\n";
        exit(1);
    }

    if (esEspanol) {
        textoIngles = traductor.traducir(textoOriginal);
        std::cout << "🔄 Traducción: " << textoIngles << "\n";
    } else {
        textoIngles = textoOriginal;
    }

    if (textoIngles.empty()) {
        std::cerr << "❌ La traducción o entrada falló. Revisa tu conexión o intenta de nuevo.\n";
        exit(1);
    }
}

std::string Receta::getTextoIngles() const {
    return textoIngles;
}

std::string Receta::getTextoInglesCodificado() const {
    std::ostringstream encoded;
    encoded << std::hex << std::uppercase;

    for (unsigned char c : textoIngles) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            encoded << '%' << std::setw(2) << int(c);
        }
    }

    return encoded.str();
}
