#include "Traductor.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include "json.hpp"
using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string Traductor::traducir(const std::string& textoEsp) {
    CURL* curl = curl_easy_init();
    std::string response;

    std::string postData = "q=" + textoEsp + "&source=es&target=en&format=text";

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://libretranslate.de/translate");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error en la solicitud de traducción: " << curl_easy_strerror(res) << std::endl;
            return "";
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    try {
        auto jsonResp = nlohmann::json::parse(response);
        return jsonResp["translatedText"];
    } catch (...) {
        std::cerr << "❌ Error procesando la respuesta de la API de traducción." << std::endl;
        return "";
    }
}
