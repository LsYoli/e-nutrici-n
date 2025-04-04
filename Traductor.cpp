
#include "Traductor.h"
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string Traductor::traducir(const std::string& textoEsp) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "content-type: application/json");
        headers = curl_slist_append(headers, "X-RapidAPI-Key: f3baa4d1b6msh198c31d74358da3p1e258fjsn1a745831f734");
        headers = curl_slist_append(headers, "X-RapidAPI-Host: ai-translate.p.rapidapi.com");

        curl_easy_setopt(curl, CURLOPT_URL, "https://ai-translate.p.rapidapi.com/translate");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        json j;
        j["text"] = textoEsp;
        j["target_language"] = "en";
        j["source_language"] = "es";

        std::string jsonData = j.dump();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error en la solicitud CURL: " << curl_easy_strerror(res) << std::endl;
            return "";
        }
        std::cout << "📥 Respuesta cruda de la API:\n" << readBuffer << std::endl;

    }

    try {
        auto jsonResponse = json::parse(readBuffer);
        return jsonResponse["translated_text"];
    } catch (...) {
        std::cerr << "Error al analizar la respuesta JSON" << std::endl;
        return "";
    }
}
