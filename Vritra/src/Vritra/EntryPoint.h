#pragma once

#ifdef VT_PLATFORM_WINDOWS
	extern VT::Application* VT::CreateApplication();

	int main(int argc, char** argv)
	{
		VT::Log::Init();
		VT_Core_Warn("Initialised");
		VT_Info("Hello");

		auto app = VT::CreateApplication();
		app->Run();
		delete app;
	}
#endif