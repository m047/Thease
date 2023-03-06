#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Thease {

	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TH_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			TH_TRACE(e);
		}
		while (true);
	}
}