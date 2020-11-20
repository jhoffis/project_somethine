//
// Created by Jens Benz on 20.11.2020.
//
#include "Window.h"
#ifndef PROJECTSOMTHINE_VKSETUP_H
#define PROJECTSOMTHINE_VKSETUP_H

class VkSetup {
public:
    VkSetup() = default;
    void initVulkan(const Window& window);
    void createInstance(Window window);
private:
    VkInstance instance{};
};


#endif //PROJECTSOMTHINE_VKSETUP_H
