#include <Engine/Graphics/Base/ImGuiBase.h>
#include <Engine/Graphics/GraphicsManager.h>

class VulkanImGuiContext : public ImGuiBase
{
public:
	~VulkanImGuiContext();
	VulkanImGuiContext(IWindow& window);

	void Initialize() override;
	void Cleanup() override;

	void BeginFrame() override;
	void EndFrame() override;

private:
	friend GraphicsManager;
};