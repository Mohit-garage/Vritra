#pragma once
#include"Core.h"

namespace VT
{
	class VRITRA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};
	// To be defined in Client
	Application* CreateApplication();
}