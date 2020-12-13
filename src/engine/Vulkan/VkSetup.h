//
// Created by Jens Benz on 20.11.2020.
//
#include <vulkan/vulkan.h>
#include "../Window.h"
#ifndef PROJECTSOMTHINE_VKSETUP_H
#define PROJECTSOMTHINE_VKSETUP_H

class VkSetup {
public:
    VkSetup() = default;
    ~VkSetup();
    void initVulkan();
    void createInstance();
private:
    VkInstance instance{};
};


#endif //PROJECTSOMTHINE_VKSETUP_H
