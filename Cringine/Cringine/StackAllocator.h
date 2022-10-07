#include <cstddef>
#include <cstdint>


class StackAllocator final
{
public:
	StackAllocator(const StackAllocator&) = delete;
	StackAllocator& operator=(const StackAllocator&) = delete;

	StackAllocator(StackAllocator&&) noexcept;
	StackAllocator& operator=(StackAllocator&&) noexcept;

	~StackAllocator() noexcept;

	void* Allocate(const std::size_t& size, const std::uintptr_t& allignment = = sizeof(std::intptr_t));
	void Free(void* ptr);

	std::size_t GetSize() const noexcept;
	std::size_t GetUsed() const noexcept;
	std::size_t GetNumAllocations() const noexcept;

	const void* GetStart() const noexcept;
private:
	static std::size_t m_Size;
	static std::size_t m_UsedBytes;
	static std::size_t m_NumAllocations;
	static void* m_pStart;

};
