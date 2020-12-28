# LeetCode Problems

## Running Sum of 1-D array

```C++
std::transform(vec.begin()+1,vec.end(), vec.begin(), vec.begin()+1, [](int a, int b){return a + b;}); 
```

## Count Primes

Sieve of Eratosthenes

Make sure that based on the input given by the user, you modify int i to long long int i or something

So, when you're doing i * i, make sure that that number exists within the possible memory. So, as a safety, assign that to a bigger value, or use numeric_limits or something similar. 

### Answer

```C++
class Solution {
public:
    int countPrimes(int n) {
        if (n<=2)
            return 0;
        
//         int i = 2;
//         int ct = 0;
//         unordered_map<int, bool> M;
//         while (i <n){
//             if (M.find(i)==M.end())
//             {
//                 ct++;
//                 int mult = 2;
//                 while(mult*i<n and sqrt(n) > i )
//                 {
//                     M[mult*i] = false;
//                     ++mult;
//                 }
//             }
//             ++i;
//         }
        
//         return ct;
        
        vector<bool> primes(n, false);
        
        for (long long int i = 3; i < n; i+=2){
            primes.at(i) = true;
        } // Potential Primes
        int countPrimes=0;
        
        for (long long int i = 3; i < n; i+=2){
         
            if (primes.at(i) == true)
            {
                ++countPrimes;
                for (long double j = i*i; j<n; j+=i)
                {
                    primes.at(static_cast<int>(j)) = false;
                }
            }
            
        }
        
        
        
        return ++countPrimes; // For 2
        
        
    }
};
```

## Bijection search in map 

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

### Answer

I wanted to use a bimay from boost. But, instead, I had to choose to work with two unordered_maps instead. 
```C++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // Stringstream to extract words.
        // Normal extract of characters.
        // Is there a way to identify size mismatch early on? No, so take lite
        // Extract simultaneously. Assign map if not already assigned. If already assigned, see if they match. 
        // It's a bijection, meaning given the string, I must be able to find the corresponding character as well.
        
        // TODO -- Check for empty strings 
        
        if (pattern.empty() or s.empty())
        {
            return false;
        }
        
        stringstream ss{s};
        
        char p;
        string word;
        unordered_map<char, string> M;
        unordered_map<string, char> M2;
        auto it = pattern.begin(); // String iterator.
        
        while (ss>>word){
            if (it==s.end()){
                // Length of pattern < Length of s
                cout<<"1";
                return false;
            }
            p = *it;
            ++it;
            if (M.find(p) == M.end() and M2.find(word) == M2.end())
            {
                M[p] = word;
                M2[word] = p;
                continue;
            }
            if (M[p] != word or M2[word]!= p) 
            {
                cout<<"2";
                return false;
            }
        }
        
        if (it !=pattern.end())
        {
                cout<<"3";
            return false; // Length of pattern > Length of s
        }
            
        return true;
    }
};
```



