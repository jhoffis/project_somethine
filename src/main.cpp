#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "engine/Window.h"
#include "engine/VkSetup.h"

class Game {
    Window window;
    VkSetup vkSetup;

public:
    void run() {
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initVulkan() {
        vkSetup.initVulkan(window);
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window.getWindow())) {
            window.update();
        }
    }

    void cleanup() {

    }
};

int main() {
    Game game;

    try {
        game.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}