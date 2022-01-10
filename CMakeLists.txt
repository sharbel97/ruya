# cmake version
    cmake_minimum_required (VERSION 3.22.1)
    
# specify c++ standard
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


#project name
    project (ruya)

# Opencv Package required
    find_package(OpenCV REQUIRED)
    MESSAGE("OpenCV version : ${OpenCV_VERSION}")

    FIND_PACKAGE( OpenCV REQUIRED)
    FIND_PACKAGE( OpenGL REQUIRED)

    find_package(FreeGLUT CONFIG REQUIRED)
    find_package(glew CONFIG REQUIRED)


    include_directories(${OpenCV_INCLUDE_DIR} )
    link_directories(${OpenCV_LIB_DIR})
    link_libraries(FreeGLUT::freeglut GLEW::GLEW)

# generate our new executable
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${OpenGL_LIBS})