# C++ Notes

1. Always make sure you have the namespace used. Makes it easier to identify which variable is being used. Do not use `using namespace std` and others like that etc. Maybe ignore it in leetcode, but not elsewhere.
2. How to extract words from a string using `stringstream` ?

```C++
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string s{"The cat is in the bag"}; // What happens if you have a punctuation mark at the end?
    stringstream ss{s}; // Uniform initialization
    
    string word;
    
    while (ss>>word)
    {
        cout<<word<<endl; // Although, I remember seeing somewhere that '/n' is preferred. Why?
    }
    
    

    return 0;
}
```
