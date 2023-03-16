#pragma once

#include "thpch.h"
#include "Core.h"
#include "Window.h"
#include "Thease/Events/ApplicationEvent.h"
#include "Events/Event.h"

namespace Thease {

	class THEASE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& e);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}

