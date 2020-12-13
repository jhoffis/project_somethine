#include <vulkan/vulkan.h>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

bool checkValidationLayerSupport();
void attemptIncludeValidationLayers(VkInstanceCreateInfo createInfo);

// TODO add more later