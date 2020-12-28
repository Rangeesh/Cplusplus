# STL

1. push_back vs emplace_back

[Link 1](https://abseil.io/tips/112)
- Use push_back when you are not sure what type you're adding to the vector. If you need to use implicit constructors, use this.
- Use emplace_back for invoking explicit constructors. For expensive data types, use this instead. Why? push_back = Create and move. emplace_back = create directly. 

```C++
struct player{
int a; 
int b;
};
vector<player> A;
A.push_back({3,4});
A.emplace_back(3,4); // Compile Error -> Needs an explicit constructor to work on. 
 ``` 
 ```C++
struct player{
int a; 
int b;
player(int a=0, int b=0) : a(player::a), b(player::b) {} // Initializer List
};
vector<player> A;
A.push_back({3,4});
A.emplace_back(3,4); // Works fine now, since we have an explicit constructor
 ``` 
 
 


2. Initializing a vector in C++ with size -- The most optimized way

[Link 1](https://stackoverflow.com/questions/25108854/initializing-the-size-of-a-c-vector/25108894)

