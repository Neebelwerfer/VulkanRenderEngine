#pragma once
#include <vulkan/vulkan.h>

class Device {

public:
	Device(VkInstance instance);
	~Device();

	void Initialize();
	void Cleanup();

};