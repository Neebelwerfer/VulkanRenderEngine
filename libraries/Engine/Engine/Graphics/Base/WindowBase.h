#pragma once
#include <Engine/Graphics/Interfaces/IWindow.h>

class WindowBase : public IWindow
{
public:
	WindowBase();
	~WindowBase();

public:
	inline bool HaveResized() const override { return m_resized; }
	inline void ClearResizedFlag() override { m_resized = false; }
	inline void SetResizedFlag() override { m_resized = true; }

private:
	bool m_resized;
};