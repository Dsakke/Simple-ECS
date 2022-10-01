#pragma once
#include <vector>
#include <memory>
#include "PoolManager.h"

class IPool;


class ISystemBase // Only for internal use, do not inherit from this 
{
public:
	virtual ~ISystemBase() = default;
	virtual void BaseExecute(std::unique_ptr<PoolManager>& pPoolManager) = 0;

private:
};


template <class ComponentType>
class ISystem : public ISystemBase
{
public:
	virtual ~ISystem() = default;
	void BaseExecute(std::unique_ptr<PoolManager>& pPoolManager);

protected:
	virtual void Execute(ComponentType& component) = 0;
};

template<class ComponentType>
inline void ISystem<ComponentType>::BaseExecute(std::unique_ptr<PoolManager>& pPoolManager)
{
	std::shared_ptr<Pool<ComponentType>> pPool = std::dynamic_pointer_cast<Pool<ComponentType>>(pPoolManager->GetPool(typeid(ComponentType)));
	std::vector<ComponentType>& components = pPool->GetComponents();
	for (size_t i{}; i < components.size(); i++)
	{
		Execute(components[i]);
	}
}
