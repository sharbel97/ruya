    cmake_minimum_required (VERSION 3.0)
    cmake_policy(SET CMP0012 NEW)
    project (ruya)

# Opencv Package required
    find_package(OpenCV REQUIRED)
    MESSAGE("OpenCV version : ${OpenCV_VERSION}")


# add opencv header files to project
    include_directories(${OpenCV_INCLUDE_DIR})
    link_directories(${OpenCV_LIB_DIR})

# generate our new executable
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(ruya $(OpenCV_LIBS))