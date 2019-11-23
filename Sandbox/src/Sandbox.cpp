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


/*
* Pushing to git hub
*	1.) cmd 
	2.) git add *
	3.) git commit -m "desc." 
	4.) git push origin master
*/