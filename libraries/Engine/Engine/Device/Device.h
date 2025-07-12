#pragma once
#include <vulkan/vulkan.h>

class Device {
	Device(VkInstance instance);
	~Device();

	void Initialise();

};