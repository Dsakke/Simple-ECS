#Simple ECS

This is a basic implementation of an ECS.

##Entities
The entities in this implementation don't have a class but are rather just an interger which is their ID.

##Components
The components are stored in a sparse sets, named pools in this implementation.
With the sparse set the components are accessible through the ID of their Entity but the components themselves are stored contiguous in the memory.

##Systems
The systems are implemented with an abstract base class from which they inherit.
They are templated in such a way that adding new systems with one or more component types is easy and quick.

###Current limitations:
	..- Entities can only have 1 of a component type.
	..- For the systems to function the used components must all have the same index in their respective pools.
	
###Future work:
	..- Allow entities to have more than one of the same component type.
	..- Allow systems to use components that don't have the same indexes.
	..- Write a static heap allocator, right now a couple of heap allocations happen at runtime. A static heap allocator could help speed up this process.
	..- Perform speed tests, comparing this ECS to public implementations.
