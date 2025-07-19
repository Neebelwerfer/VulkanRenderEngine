#include <Engine/Graphics/Base/ImGuiBase.h>
#include <Engine/Graphics/GraphicsManager.h>

class VulkanImGuiContext : public ImGuiBase
{
public:
	~VulkanImGuiContext();

	void Initialize() override;
	void Cleanup() override;

	void BeginFrame() override;
	void EndFrame() override;

private:
	friend GraphicsManager;

	void Render();

	VulkanImGuiContext(IWindow& window);

private:

};