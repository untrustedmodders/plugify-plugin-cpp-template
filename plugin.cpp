#include <iostream>
#include <plugify/cpp_plugin.hpp>
#include <plugify/string.hpp>
#include <plugin_export.h>

class ExamplePlugin final : public plg::IPluginEntry {
public:
	void OnPluginStart() final {
		std::cout << GetName() << "Start!" << std::endl;
	}

	void OnPluginUpdate(float dt) final {
		std::cout << GetName() << "Update!" << dt << std::endl;
	}

	void OnPluginEnd() final {
		std::cout << GetName() << "End!" << std::endl;
	}
} g_examplePlugin;

EXPOSE_PLUGIN(PLUGIN_API, ExamplePlugin, &g_examplePlugin)
