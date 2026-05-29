cmake_minimum_required(VERSION 4.2)
project(quicksilver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.8
    GIT_PROGRESS TRUE
)
    
FetchContent_MakeAvailable(SDL3)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(quicksilver SHARED src/quicksilver.cpp)
target_link_libraries(quicksilver PRIVATE SDL3::SDL3)

set_target_properties(quicksilver PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)