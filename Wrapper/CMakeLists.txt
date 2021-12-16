# CMakeList.txt: проект CMake для Wrapper; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Wrapper")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Wrapper "engine/wrapper/wrapper.h" "engine/wrapper/wrapper.cpp" "engine/engine.h" "engine/engine.cpp" "main.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
