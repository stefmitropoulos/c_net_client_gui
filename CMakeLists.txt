cmake_minimum_required(VERSION 3.14)
project(c_net_client_gui)

set(CMAKE_CXX_STANDARD 14)

# The version number.
set (c_net_client_gui_VERSION_MAJOR 1)
set (c_net_client_gui_VERSION_MINOR 0)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(c_net_client_gui ${GTK3_INCLUDE_DIRS} include)
include_directories("${PROJECT_BINARY_DIR}")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "include/c_net_client_guiConfig.h.in"
        "${PROJECT_BINARY_DIR}/c_net_client_guiConfig.h" )


add_executable(c_net_client_gui src/main.cpp include/c_net_client_guiConfig.h.in)
target_link_libraries(c_net_client_gui ${GTK3_LIBRARIES})

install(FILES "${PROJECT_BINARY_DIR}/c_net_client_guiConfig.h"
        DESTINATION include)