cmake_minimum_required(VERSION 3.30)
project(adwm)

find_package(X11 REQUIRED COMPONENTS Xinerama)
find_package(Freetype)

add_executable(
    adwm
    source/dwm.cpp
    source/drw.cpp
    source/util.cpp
)

target_compile_options(adwm PRIVATE -std=c++20 -Wall -Wextra -Wpedantic -O2)
target_link_libraries(adwm PRIVATE X11::X11 X11::Xft X11::Xinerama Freetype::Freetype)
