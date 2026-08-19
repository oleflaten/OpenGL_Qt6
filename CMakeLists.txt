cmake_minimum_required(VERSION 3.21)

project(3D-programmering
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    OpenGL
)

qt_standard_project_setup()

include(FetchContent)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.3
)

FetchContent_MakeAvailable(glm)

add_executable(${PROJECT_NAME}
    main.cpp

    camera.cpp
    camera.h

    light.cpp
    light.h

    logger.cpp
    logger.h

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    quad.cpp
    quad.h

    renderer.cpp
    renderer.h

    shader.cpp
    shader.h

    texture.cpp
    texture.h

    triangle.cpp
    triangle.h

    vertex.cpp
    vertex.h

    gameobject.cpp
    gameobject.h

    xyz.cpp
    xyz.h

    gltypes.h

    input.h

    # Shader files - included so they appear in the IDE
    phongshader.frag
    phongshader.vert
    plainshader.frag
    plainshader.vert
    textureshader.frag
    textureshader.vert
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::OpenGL
        glm::glm
)

