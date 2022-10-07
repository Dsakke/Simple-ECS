#pragma once
#include <vector>
#include <memory>
#include "PoolManager.h"
#include <utility>

class IPool;


class ISystemBase // Only for internal use, do not inherit from this 
{
public:
	virtual ~ISystemBase() = default;
	virtual void BaseExecute(std::unique_ptr<PoolManager>& pPoolManager) = 0;

private:
};


template <class... ARGS>
class ISystem : public ISystemBase
{
public:
	virtual ~ISystem() = default;
	void BaseExecute(std::unique_ptr<PoolManager>& pPoolManager);

protected:
	virtual void Execute(ARGS&... components) = 0;

};

template<class... ARGS>
inline void ISystem<ARGS...>::BaseExecute(std::unique_ptr<PoolManager>& pPoolManager)
{
	constexpr std::size_t nArgs = sizeof...(ARGS);
	std::tuple<std::vector<std::reference_wrapper<ARGS>>...> view
	{
		std::vector<std::reference_wrapper<ARGS>>
		{
			pPoolManager->GetComponents<ARGS>().begin(), pPoolManager->GetComponents<ARGS>().end()
		}...
	};


	for (size_t i{}; i < std::get<0>(view).size(); ++i)
	{
		Execute(std::get<std::vector<std::reference_wrapper<ARGS>>>(view)[i]...);
	}
}


