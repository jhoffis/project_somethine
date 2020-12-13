cmake_minimum_required(VERSION 3.17)
project(projectsomthine)

set(CMAKE_CXX_STANDARD 20)

add_executable(projectsomthine
        src/main.cpp
        src/engine/Window.cpp
        src/engine/Window.h
        src/engine/Vulkan/VkSetup.cpp
        src/engine/Vulkan/VkSetup.h
        src/engine/Vulkan/VkValidationLayers.cpp src/engine/Vulkan/VkValidationLayers.h src/engine/Vulkan/VkPhysicalDevice.cpp src/engine/Vulkan/VkPhysicalDevice.h)

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glm)
target_link_libraries(${PROJECT_NAME} glm::glm)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/stb)

#target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/lib-mingw-w64/libglfw3dll.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/lib-mingw-w64/libglfw3.a)