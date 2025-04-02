# Proyecto de Nutrición

## Descripción

Este proyecto de nutrición permite a los usuarios obtener información detallada sobre los nutrientes de las recetas que ingresan. Utiliza la API de Edamam para proporcionar datos nutricionales precisos y se implementa utilizando C++ y la biblioteca cURL para manejar las solicitudes HTTP. El proyecto está diseñado para ser modular, reutilizable y fácil de mantener. Este es un caso de estudio para la curso de Fundamentos de Programación Orientada a Objetos de la Universidad del Valle.

## Contenidos

- Uso de clases
- Uso de bibliotecas
- Uso de APIs
- Reutilización de código
- Software modular

## Funcionalidades

- **Ingresar recetas**: Permite a los usuarios ingresar recetas en formato de texto.
- **Obtener información nutricional**: Proporciona un desglose detallado de los nutrientes de los ingredientes ingresados.
- **Compatibilidad con otros programas**: Se puede integrar con aplicaciones de gestión de dietas y software de monitoreo de salud.
- **Uso de JSON**: Los datos se intercambian en formato JSON, facilitando la interoperabilidad.

## Requisitos

- C++ Compiler (ej. g++, clang++)
- cURL Library
- Acceso a Internet (para realizar solicitudes a la API de Edamam)

## Instalación
Asegúrate de tener instalada la biblioteca cURL. Puedes instalarla en sistemas basados en Debian/Ubuntu con:

### Instalación librerias
sudo apt-get install libcurl4-openssl-dev

### Compila el proyecto:
g++ -o nutricion main.cpp -lcurl

### Uso

./nutricion
