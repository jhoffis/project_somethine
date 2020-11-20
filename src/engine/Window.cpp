#include "Window.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

Window::Window() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

}

void Window::update() {
    glfwPollEvents();
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::initExtensions(VkInstanceCreateInfo *createInfo) {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo->enabledExtensionCount = glfwExtensionCount;
    createInfo->ppEnabledExtensionNames = glfwExtensions;
}
