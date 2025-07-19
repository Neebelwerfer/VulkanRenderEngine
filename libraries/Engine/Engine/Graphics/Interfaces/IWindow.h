#pragma once
#include <string>

enum class NativeWindowHandleType {
	Unknown,
	GLFW,
};
struct NativeWindowHandle {
	NativeWindowHandleType type = NativeWindowHandleType::Unknown;

	union {
		struct {
			void* ptr;
		} glfw;
		void* raw; // fallback, raw pointer if needed
	};
	NativeWindowHandle() : type(NativeWindowHandleType::Unknown), raw(nullptr) {}
};

class IWindow
{
public:
	virtual ~IWindow() = default;

	virtual void GetDimensions(int& width, int& height) const = 0;
	virtual void GetFramebufferSize(int& width, int& height) const = 0;
	virtual float GetAspectRatio() const = 0;

	virtual bool ShouldClose() const = 0;
	virtual bool IsValid() const = 0;
	virtual bool HaveResized() const = 0;
	virtual bool IsMinimized() const = 0;

	virtual const std::string& GetWindowTitle() const = 0;

	virtual void ClearResizedFlag() = 0;
	virtual void SetResizedFlag() = 0;
	virtual void PollEvents() const = 0;
	virtual void Close() const = 0;

public:
    virtual NativeWindowHandle GetNativeWindow() const = 0;
};