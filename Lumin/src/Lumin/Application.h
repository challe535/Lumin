#pragma once

#include "Core.h"

namespace Lumin {

	class LUMIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	
	Application* CreateApplication();
}

