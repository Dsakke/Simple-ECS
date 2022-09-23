#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
class ISystemBase;
class PoolManager;

class SystemManager final
{
public:
	void AddSystem(std::type_index componentType, std::unique_ptr<ISystemBase>&& pSystem);
	void Update(std::unique_ptr<PoolManager>& pPoolManager);
private:
	std::unordered_multimap<std::type_index, std::unique_ptr<ISystemBase>> m_Systems;
};