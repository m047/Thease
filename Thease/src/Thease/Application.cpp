#include "Application.h"

#include <iostream>
#include <Windows.h>
namespace Thease {

	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {
		int i = 3;
		while (i-- > 0) {
			std::cout << "You win when you quit this window!\n";
			Sleep(500);
			std::cout << "Try it now!\n";
			Sleep(500);
		};
		std::cout << "You lost! To slow!\n";
		Sleep(1000);
	}
}