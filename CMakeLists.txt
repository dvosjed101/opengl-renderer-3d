cmake_minimum_required(VERSION 4.4)

project(RenderingEngine)

add_executable(main Main.cpp)

target_include_directories(main PRIVATE
    Libraries/include
)

target_link_directories(main PRIVATE
    Libraries/lib
)

target_link_libraries(main
    glfw3
    opengl32
)