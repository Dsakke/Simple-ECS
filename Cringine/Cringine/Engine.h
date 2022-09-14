#pragma once
class Engine final
{
public:
#pragma region deleted functions
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;
#pragma endregion
	Engine() = default;
	void Initialize();
	void Run();
private:
};