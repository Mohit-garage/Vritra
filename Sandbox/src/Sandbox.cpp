#include <Vritra.h>

class Sandbox : public VT::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};
VT::Application* VT::CreateApplication()
{
	return new Sandbox();
}