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
	virtual void Execute(std::shared_ptr<PoolManager> pPool) = 0;
};


template <class ComponentType>
class ISystem : public ISystemBase
{
public:
	virtual ~ISystem() = default;
	void BaseExecute(std::unique_ptr<PoolManager>& pPoolManager);

protected:
	virtual void Execute(std::shared_ptr<IPool> pPool) override = 0;
};

template<class ComponentType>
inline void ISystem<ComponentType>::BaseExecute(std::unique_ptr<PoolManager>& pPoolManager)
{
	Execute(pPoolManager->GetPool(ComponentType));
}
