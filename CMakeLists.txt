cmake_minimum_required(VERSION 3.0)

project(baseDeDatos)

# Agrega todos los archivos fuente en la carpeta 'src'
file(GLOB SOURCES "src/*.cpp" "src/models/*.cpp" "src/controller/*.cpp" "src/components/*.cpp" "src/screens/*.cpp" "src/screens/*.h" "src/store/*.cpp" "src/helpers/*.cpp")

# Crea un ejecutable a partir de los archivos fuente
add_executable(main ${SOURCES})

# Configura propiedades del ejecutable, como C++ estándar
set_target_properties(main PROPERTIES CXX_STANDARD 17)

# Enlace con la biblioteca NCurses
find_package(Curses REQUIRED)
target_link_libraries(main PRIVATE ${CURSES_LIBRARIES})

# Incluye las cabeceras de NCurses
target_include_directories(main PRIVATE ${CURSES_INCLUDE_DIRS})
