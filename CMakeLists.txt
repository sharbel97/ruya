# cmake version
    cmake_minimum_required (VERSION 3.0)
    
# specify c++ standard
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

#project name
    project (ruya)

# Opencv Package required
    find_package(OpenCV REQUIRED)
    MESSAGE("OpenCV version : ${OpenCV_VERSION}")
    include_directories(${OpenCV_INCLUDE_DIR})
    link_directories(${OpenCV_LIB_DIR})

# generate our new executable
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(ruya ${OpenCV_LIBS})