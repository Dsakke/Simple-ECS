#pragma once
#include "ISystem.h"
#include "CounterComponent.h"

class CounterSystem final : public ISystem<CounterComponent>
{
public:
	
protected:
	void Execute(CounterComponent& component) override;
};