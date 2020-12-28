# STL

## 1. push_back vs emplace_back

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
 
 


## 2. Initializing a vector in C++ with size -- The most optimized way

[Link 1](https://stackoverflow.com/questions/25108854/initializing-the-size-of-a-c-vector/25108894)

If you already know the size of your vector, reserve it and then start using it. If you don't have an actual estimate of the size, just reserve a large number and you can shrink_to_fit it later. Example?

```C++
vector<int> A(nums.size()); // Already known size -> Can it be zero as well? Yes. So, nums can have a size of 0 as well. Won't cause an error.

// or
// vector<int> A;
// A.reserve(nums.size());
```

In case you have a class or struct which you want to initialize for every element in the vector, use the following, provided the copy constructor is defined... Can work even if the copy constructor isn't defined... But better to have it defined. 
```C++ 
vector<int> A(n, player1);
```

If you want to fill or add n elements to the vector at a later stage... There are two ways to do it, depending on whether it is filled/generated.

Fill -> All elements are same.
Generate -> All elements are different, based on a generator function. 

```C++
std::fill_n(back_inserter(vec1), n, entry);
std::generate_n(back_inserter(vec2), n, []{return vec_generator();}
```


## 3. What is this std::back_inserter?

[Link 1](https://www.geeksforgeeks.org/stdback_inserter-in-cpp/)

