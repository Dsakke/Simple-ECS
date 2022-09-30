#include "CounterSystem.h"
#include "Pool.h"
#include <iostream>

void CounterSystem::Execute(std::shared_ptr<IPool> pPool)
{
	Pool<CounterComponent>& pool = dynamic_cast<Pool<CounterComponent>&>(*pPool);
	std::vector<CounterComponent>& components = pool.GetComponents();
	for (size_t i{}; i < components.size(); ++i)
	{
		std::cout << "ID: " << components[i].m_EntityID << "\tCounter: " << components[i].m_CurrentVal++ << "\n";
	}
}