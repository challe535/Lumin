#include <Lumin.h>;

class Sandbox : public Lumin::Application
{
public:
	Sandbox()
	{

	};

	~Sandbox()
	{

	};
};

Lumin::Application* Lumin::CreateApplication()
{
	return new Sandbox();
}