#include "vtpch.h"
#include "Application.h"
#include "Vritra/Events/ApplicationEvent.h"
#include "Vritra/Log.h"

namespace VT {
	Application::Application()
	{
	
	}
	Application::~Application()
	{
	
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			VT_Trace(e);
		}

		while (true);
	}
}