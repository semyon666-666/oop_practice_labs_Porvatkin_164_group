cmake_minimum_required(VERSION 3.16)

project(nasledpolimorf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(nasledpolimorf main.cpp)

include(GNUInstallDirs)
install(TARGETS nasledpolimorf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
