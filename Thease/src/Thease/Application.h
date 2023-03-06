#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Thease {

	class THEASE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

