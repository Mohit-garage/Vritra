#pragma once

#ifdef VT_PLATFORM_WINDOWS
	extern VT::Application* VT::CreateApplication();

	int main(int argc, char** argv)
	{
		auto app = VT::CreateApplication();
		app->Run();
		delete app;
	}
#endif