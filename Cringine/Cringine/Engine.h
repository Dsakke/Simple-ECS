#pragma once
#include <memory>

// Can't forward declare these
#include "PoolManager.h"
#include "SystemManager.h"

class Engine final
{
public:
#pragma region deleted functions
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;
#pragma endregion
	Engine() = default;
	~Engine();
	void Initialize();
	void Run();
	PoolManager& GetPoolManager();
	SystemManager& GetSystemManager();
private:
	std::unique_ptr<PoolManager> m_pPoolManager;
	std::unique_ptr<SystemManager> m_pSystemManager;
};