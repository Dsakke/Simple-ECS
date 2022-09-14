#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
using ComponentType = std::type_index;

class IPool;

class PoolManager
{
public:
	PoolManager();
	void AddPool(ComponentType type, std::unique_ptr<IPool>&& pPool);
private:
	std::unordered_map<ComponentType, std::unique_ptr<IPool>> m_Pools;
};