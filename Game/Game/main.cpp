#include "Engine.h"

int main()
{
	Engine* pEngine = new Engine{};
	pEngine->Initialize();
	pEngine->Run();
	return 0;
}