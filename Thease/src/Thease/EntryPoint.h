#pragma once

#ifdef THEA_PLATFORM_WINDOWS

extern Thease::Application* Thease::CreateApplication();

int main(int argc, char** argv) {
	auto app = Thease::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Thease only works on windows currently!
#endif
