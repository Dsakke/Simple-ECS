#include "Engine.h"

#include "EntityGenerator.h"

Engine::~Engine()
{
}

void Engine::Initialize()
{
	m_pPoolManager = std::make_unique<PoolManager>();
	m_pSystemManager = std::make_unique<SystemManager>();
}

void Engine::Run()
{
	while (true)
	{
		m_pSystemManager->Update(m_pPoolManager);
	}
}

PoolManager& Engine::GetPoolManager()
{
	return *m_pPoolManager;
}

SystemManager& Engine::GetSystemManager()
{
	return *m_pSystemManager;
}
