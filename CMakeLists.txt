# cmake version
    cmake_minimum_required (VERSION 3.0)
    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        MESSAGE("Clang")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        MESSAGE("GNU")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
        MESSAGE("Intel")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        MESSAGE("MSVC")
    endif()
    
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
    target_link_libraries(ruya ${Open_CV_LIBS})