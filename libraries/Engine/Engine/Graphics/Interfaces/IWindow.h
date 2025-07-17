#pragma once

class IWindow
{
public:
	IWindow() {}
	virtual ~IWindow() {}


	virtual void GetDimensions(int& width, int& height) const = 0;
	virtual void GetFramebufferSize(int& width, int& height) const = 0;
	virtual float GetAspectRatio() const = 0;

	virtual void Close() const = 0;
	virtual bool ShouldClose() const = 0;
	virtual bool IsValid() const = 0;
	virtual void PollEvents() const = 0;

public:
	enum class NativeHandleType {
		Unknown,
		GLFW,
	};
    struct NativeHandle {
        NativeHandleType type = NativeHandleType::Unknown;

        union {
            struct {
                void* ptr;
            } glfw;
            void* raw; // fallback, raw pointer if needed
        };
        NativeHandle() : type(NativeHandleType::Unknown), raw(nullptr) {}
    };

    virtual NativeHandle GetNativeWindow() const = 0;

private:
	char* m_title;
};