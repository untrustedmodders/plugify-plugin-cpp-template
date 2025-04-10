#include <iostream>
#include <plugify/cpp_plugin.hpp>
#include <plugify/string.hpp>
#include <plugin_export.h>

class ExamplePlugin final : public plg::IPluginEntry {
public:
	void OnPluginStart() final {
		std::cout << "Example Start!" << std::endl;
	}

	void OnPluginUpdate(float dt) final {
		std::cout << "Example Update!" << dt << std::endl;
	}

	void OnPluginEnd() final {
		std::cout << "Example End!" << std::endl;
	}

	void MakePrint(int count, const plg::string& message) {
		for (int i = 0; i < count; ++i) {
			std::cout << message.data() << std::endl;
		}
	}
} g_examplePlugin;

EXPOSE_PLUGIN(PLUGIN_API, ExamplePlugin, &g_examplePlugin)

extern "C"
PLUGIN_API void MakePrint(int count, const plg::string& message) {
	g_examplePlugin.MakePrint(count, message);
}
