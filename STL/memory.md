

std::destroy_at(ptr); // destroy the object at ptr

template< class T >
void destroy_at( T* p );

If T is not an array type, calls the destructor of the object pointed to by p, as if by `p->~T()`.

If T is an array type, the program is ill-formed(until C++20) recursively destroys elements of *p in order, as if by calling `std::destroy(std::begin (*p), std::end(*p))` (since C++20).
```cpp
#include <iostream>
#include <memory>
#include <new>
 
struct Tracer
{
    int value;
    ~Tracer() { std::cout << value << " destructed\n"; }
};
 
int main()
{
    alignas(Tracer) unsigned char buffer[sizeof(Tracer) * 8];
 
    for (int i = 0; i < 8; ++i)
        new(buffer + sizeof(Tracer) * i) Tracer{i}; //manually construct objects
 
    auto ptr = std::launder(reinterpret_cast<Tracer*>(buffer));
 
    for (int i = 0; i < 8; ++i)
        std::destroy_at(ptr + i);
}
```