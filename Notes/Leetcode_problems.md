# LeetCode Problems

## Running Sum of 1-D array

```C++
std::transform(vec.begin()+1,vec.end(), vec.begin(), vec.begin()+1, [](int a, int b){return a + b;}); 
```

## Count Primes

Sieve of Eratosthenes

Make sure that based on the input given by the user, you modify int i to long long int i or something

So, when you're doing i * i, make sure that that number exists within the possible memory. So, as a safety, assign that to a bigger value, or use numeric_limits or something similar. 

## Bijection search in map 

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true



