#include "AnalisisNutricional.h"
#include "json.hpp"
#include <curl/curl.h>
#include <iostream>

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

std::string AnalisisNutricional::consultarAPI(const Receta& receta) {
    CURL* curl;
    CURLcode res;
    std::string response;

    std::string app_id = "66c863b9";
    std::string app_key = "3b797da8030d8bbace629fccab47de17";
    std::string url = "https://api.edamam.com/api/nutrition-data?app_id=" + app_id + "&app_key=" + app_key + "&ingr=" + receta.getTextoInglesCodificado();

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

void AnalisisNutricional::mostrarResumen(const std::string& jsonStr) {
    try {
        json data = json::parse(jsonStr);
        std::cout << "\n📊 INFORMACIÓN NUTRICIONAL 📊\n";
        std::cout << "Calorías: " << data["calories"] << "\n";
        std::cout << "Peso total (g): " << data["totalWeight"] << "\n";
        std::cout << "Etiquetas de dieta: ";
        for (const auto& label : data["dietLabels"]) {
            std::cout << label << " ";
        }
        std::cout << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error al procesar JSON: " << e.what() << std::endl;
    }
}
