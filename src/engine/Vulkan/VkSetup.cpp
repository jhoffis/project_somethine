//
// Created by Jens Benz on 20.11.2020.
//
#include <stdexcept>
#include "VkSetup.h"
#include "VkValidationLayers.h"
#include "VkPhysicalDevice.h"

void VkSetup::initVulkan() {
    createInstance();
    pickPhysicalDevice(instance);
}

void VkSetup::createInstance() {
    if (enableValidationLayers && !checkValidationLayerSupport()) {
        throw std::runtime_error("validation layers requested, but not available!");
    }

    VkApplicationInfo  appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_2;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    Window::initExtensions(&createInfo);
    createInfo.enabledLayerCount = 0;
    attemptIncludeValidationLayers(createInfo);

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance");
    }
}

VkSetup::~VkSetup() {
    vkDestroyInstance(instance, nullptr);
}

