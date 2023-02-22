#include <Thease.h>

class CloseTheWindow : public Thease::Application {
public:
	CloseTheWindow() {

	}

	~CloseTheWindow() {

	}
};

Thease::Application* Thease::CreateApplication() {
	return new CloseTheWindow();
}