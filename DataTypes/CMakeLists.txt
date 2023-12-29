
project(DataTypes)

add_library(DataTypes src/string.cpp
        src/number.cpp
        src/object.cpp
        src/list.cpp
        src/data_types.cpp
        src/null.cpp
        src/bool.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
