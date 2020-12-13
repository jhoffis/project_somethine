//
// Created by Jens Benz on 19.11.2020.
//

#ifndef PROJECTSOMTHINE_WINDOW_H
#define PROJECTSOMTHINE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    void update();
    ~Window();

    GLFWwindow *getWindow() {
        return window;
    }

    static void initExtensions(VkInstanceCreateInfo *createInfo);

private:
    GLFWwindow* window;
};


#endif //PROJECTSOMTHINE_WINDOW_H
