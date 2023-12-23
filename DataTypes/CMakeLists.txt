
project(DataTypes)

file(GLOB SOURCES "src/*.cpp")

add_library(DataTypes src/string.cpp
        src/number.cpp
        src/object.cpp
        src/list.cpp)

message(${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
