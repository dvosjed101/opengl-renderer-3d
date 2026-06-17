cmake_minimum_required(VERSION 4.4)

project(RenderingEngine)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "source/*.cpp"
    "Main.cpp"
)

add_executable(main
    ${SOURCES}
    glad.c
)

target_include_directories(main PRIVATE
    Libraries/include
    headers
)

target_link_directories(main PRIVATE
    Libraries/lib
)

target_link_libraries(main
    glfw3
    opengl32
)