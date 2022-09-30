#pragma once
class CounterComponent
{
public:
	CounterComponent(int entityID)
		: m_EntityID{entityID}
	{

	}

	int m_EntityID;
	int m_CurrentVal = 0;
};