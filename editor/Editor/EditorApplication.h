#include <Engine/Core/Application.h>


class EditorApplication : public Application
{
public:
	EditorApplication();
	~EditorApplication();

protected:
	void Initialize() override;
	void Update() override;
	void Render() override;
	void Cleanup() override;

private:
	void RenderGUI();

private:
	std::unique_ptr<ImGuiBase> m_imguiContext;
};