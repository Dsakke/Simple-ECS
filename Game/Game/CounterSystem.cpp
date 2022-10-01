#include "CounterSystem.h"
#include "Pool.h"
#include <iostream>

void CounterSystem::Execute(CounterComponent& component)
{
	std::cout << "ID: " << component.m_EntityID << "\tCounter: " << component.m_CurrentVal++ << "\n";
}