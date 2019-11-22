#include <AGE.h>

class Sandbox : public AGE::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
private:

};

AGE::Application* AGE::CreateApplication()
{
	return new Sandbox();
}