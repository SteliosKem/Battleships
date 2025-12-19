cmake_minimum_required(VERSION 3.11)
project(TerminalEngine VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_executable(TerminalEngine src/TerminalEngine/Windows/Application.c src/Game/main.c src/TerminalEngine/Windows/Input.c src/TerminalEngine/Renderer/Renderer.c src/TerminalEngine/Math.c)
target_include_directories(TerminalEngine PRIVATE src/)

add_library(pdcurses STATIC IMPORTED)

set_target_properties(pdcurses PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/external/pdcurses/wincon/pdcurses.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/external/pdcurses"
)

target_link_libraries(TerminalEngine PRIVATE pdcurses)