#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "ISystem.h"

class PoolManager;

class SystemManager final
{
public:
	void AddSystem(std::type_index componentType, std::unique_ptr<ISystemBase>&& pSystem);
	void Update(std::unique_ptr<PoolManager>& pPoolManager);
	~SystemManager();
private:
	std::unordered_map<std::type_index, std::unique_ptr<ISystemBase>> m_Systems;
};