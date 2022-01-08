# cmake version
    cmake_minimum_required (VERSION 3.0)
    
# # specify c++ standard
#     set(CMAKE_CXX_STANDARD 11)
#     set(CMAKE_CXX_STANDARD_REQUIRED ON)
#     set(CMAKE_CXX_EXTENSIONS OFF)
#     set(CMAKE_GXX_FLAGS "-Wall -Wextra -Wconversion  -pedantic -std=gnu11")


#project name
    project (ruya)

# Opencv Package required
    find_package(OpenCV REQUIRED)
    MESSAGE("OpenCV version : ${OpenCV_VERSION}")

    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIB_DIR})

# generate our new executable
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})