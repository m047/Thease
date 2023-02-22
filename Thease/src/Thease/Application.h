#pragma once

#include "Core.h"

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

