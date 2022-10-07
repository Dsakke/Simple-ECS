# Simple ECS

This is a basic implementation of an ECS.

#### Entities
The entities in this implementation don't have a class but only exist as their ID

#### Components
The components are stored in a sparse sets, named pools in this implementation.
With the sparse set the components are accessible through the ID of their Entity but the components themselves are stored contiguous in the memory.

#### Systems
The systems are implemented with an abstract base class from which they inherit. They are templated in such a way that adding new systems with one or more component types is easy and quick. The user just has to override the Execute function with the components they want to use.

#### Current limitations:
	- Entities can only have 1 of a component type.
	- For the systems to function the used components must all have the same index in their respective pools.
	
#### Future work:
	- Allow entities to have more than one of the same component type.
	- Allow systems to use components that don't have the same indexes.
	- Write a static heap allocator, to avoid data being allocated at runtime.
	- Perform speed tests, comparing this ECS to public implementations.
