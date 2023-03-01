#pragma once

#ifdef THEA_PLATFORM_WINDOWS

extern Thease::Application* Thease::CreateApplication();

int main(int argc, char** argv) {
	Thease::Log::Init();
	TH_CORE_WARN("Initialized");
	int a = 5;
	TH_INFO("Initialized {0}", a);
	auto app = Thease::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Thease only works on windows currently!
#endif
