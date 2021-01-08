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




## 4. When to use unordered_map and when to use map?

- Use map over unordered_map when
 - You don't have much memory -- unordered_map uses more memory bcoz of hashing
 - When you need a perfect time Complexity O(log N) ... and O(l) with a worst case of O(N) -- depending on the hash implementation
 - When you want it to be sorted -- Balanced Trees are sorted.

- Use unordered_map over map when
 - You have a good hash implementation and lots of memory.
 [Link 1](https://thispointer.com/map-vs-unordered_map-when-to-choose-one-over-another/)
 
 
 ---
 
 STL Data types
 
## Vector
### Initialization
```C++
//1 Normal
vector<int> vect;
vect.push_back(2); vect.push_back(4);
//2 
vector<int> vect(5,2); // (n, element). If it's a class, copy constructor needs to be defined.
//3
vector<int> A{1,2,3};
//4a Range Constructor
int arr[]={2,3,4,5};
int n = sizeof(arr)/sizeof(int);
vector<int> vect(arr, arr + n);
//4b Range COnstructor
vector<int> vect(vect1.begin(), vect1.end());
//5 
vector<int> vect;
vect.reserve(50); // Array dynamically changing its size is avoided.
//6 std::copy
vector<int> A{2,3,4};
vector<int> C(A.size());
std::copy(A.begin(), A.end(), C.begin()); // Make sure to have the size of the C vector already defined.
//6b
std::copy(A.begin(), A.end(), std::back_inserter(C.begin())); // If memory isn't already allocated, it will allocate and then add in the value
//7 Move
vector<int> v1, v2;
auto it = std::next(v1.begin(), 17); // Fills the next 17 elements. Doesn't fill_n also do that?
std::move(v1.begin(), it, sstd::back_inserter(v2.begin())); // Size isn't reallocated, so use std::back_inserter
v1.erase(v1.begin(), it); 
// When you move, you actually create place holders in the vector you moved from. Therefore, you need to erase those, unless you want to reuse that memory again.
// vector<char> to string
std::ostringstream out;
for (char c: vect)
    out<<c;
std::string s(out.str());
// transform
std::transform(charv.begin(), charv.end(), back_inserter(s), [](char c){return c;});
// s.append(1,c); s.insert(i,1,charv[i]);
// s +=c is same as s.push_back(c); // Memory is also allocated with push_back


```
### Access
```C++
//Size
Vect.size();
// Copying a vector into an array
int arr[vect.size()];
copy(vect.begin(), vect.end(), arr);

```


### Modification
```C++
//Erase
vector<int> v1{2,3,5}; // Implicit type casting isn't possible during uniform initialization
v1.erase(v1.begin(), v1.end());
//Insert
v1.insert(From where, new vector- sstart, new vector-end);
v1.insert(v1.end(),v2.begin(), v2,end());
// Insert with move
v1.insert(v1.end(), std::make_move_iterator(v2.begin()), std::make_move_iterator(v2.end()));
v2.erase(v2.begin(), v2.end()); // Removing placeholders. Move operation done.
//Swap
vector<int> v1{2,3,4}, v2{4,6,7,8}; 
v1.swap(v2); // Any size for vectors
//Swap Ranges
std::swap_ranges(v1.begin(), v1.end(), v2.begin()); // Must be for same size of elements
// Delete vector contents and free up space.
v1.clear(); // size() changes. capacity() doesn't change. Similar behavior - erase()
v1.shrink_to_fit(); // non-binding argument.
vector<int> ().swap(v1)//Therefore, to free up the space


```
### Sorting
```C++
// Can you sort in reverse order?
sort(A.begin(), A.end());
reverse(A.begin(), A.end());
//2
sort(A.rbegin(),A.rend());
//Comparator std::greater<int>() for reverse. std::less<int>() for normal
struct comp
{
template<typename T>
bool operator()(const T& lhs, const T& rhs){
return lhs > rhs; // For reverse. For Normal, lhs < rhs
}
};
sort(A.begin(), A.end(), comp());
//3  lambda function
sort(A.begin(), A.end(), [](const T& a, const T& b){return a>b;});



```




---
# Questions
1. What is the `std::make_move_iterator` ?
2. What does `std::next` do?
3. Tell me all about iterators ... Reverse, move itertors etc.


 - Stack & Queue
 
 - Set (All 4 variations)
 - Map (All 4 variations)
 
 - deque
 - priority_queue
 
 - string
 



