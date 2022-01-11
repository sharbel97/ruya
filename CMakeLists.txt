# cmake version
    cmake_minimum_required (VERSION 3.22.1)
    
# specify c++ standard
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# specify location of opencv build
    set(OpenCV_DIR /Users/sharbel/dev/opencv-4.5.5/build)


#project name
    project (ruya)

# Opencv Package required
    FIND_PACKAGE(OpenCV 4.5.5 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )



    MESSAGE("OpenCV version : ${OpenCV_VERSION}")

    include_directories(${OpenCV_INCLUDE_DIR} )
    link_directories(${OpenCV_LIB_DIR})

# generate our new executable
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

