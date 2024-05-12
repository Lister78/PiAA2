cmake_minimum_required(VERSION 3.10)
project(GraphShortestPath)

# Ustawienie standardu języka C++ na C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Znajdź wszystkie pliki nagłówkowe w katalogu inc
file(GLOB INC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h")

# Znajdź wszystkie pliki źródłowe w katalogu src
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Dodaj pliki nagłówkowe dołączając katalog inc
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")

# Utwórz plik wykonywalny i podlinkuj pliki źródłowe
add_executable(GraphShortestPath ${SRC_FILES} ${INC_FILES})

