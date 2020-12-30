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
![](https://github.com/Rangeesh/Cplusplus/blob/main/leetcode.png)
## Contains Duplicates I
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.


### Answer

```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        // Logic
        // Put in map. If it already exists, check difference. If <=k, true, else replace and continue
        
        // Size <=1 => false
        
        if (nums.size()<=1)
            return false;
        
        map<int, int> M;
        
        for(int i = 0; i<nums.size(); ++i)
        {
            if (M.find(nums.at(i)) == M.end()){ // Does it exist or not in map. If not, add element
                M[nums.at(i)] = i; 
             continue;   
            }
            
            if (abs(M[nums.at(i)] - i) <=k ) // Checking condition
            {return true; }
            M[nums.at(i)] = i; // Replace
        }
        
        return false;       
    }
};
```
Don't make silly mistakes with maps... Look at what you're trying to extract
![](https://github.com/Rangeesh/Cplusplus/blob/main/leetcode2.png)

## Powerful Integers
Don't make mistakes with such questions. Read if the bound is less than or less than and equal to. Also, 1 + 1 is 2. Just FYI



```C++
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        // bound - 1 == max value of x^i => max value of i
        // similar for max value of j. 
        // Then do 2 for loop?
        // If either number is 1 or if both are 1, then it is a special case. 
        
        if (x==1 and y==1)
        {
            vector<int> res{2};
            if (bound > 1)
            return res;
            
            res.clear();
            return res;
        }
        
        
        
        
        unordered_set<int> S;
        
        int i = 0;
        
        while(x!=1)
        {
            int res = pow(x,i);
            if ( (bound - 1) >= res)
            {
                S.insert(res+1);
                ++i;
                continue;
            }
            break;
        }
        // Max value of i is got
        
        int j = 0;
        
        while(y!=1)
        {
            int res = pow(y,j);
            if ( (bound - 1) >= res)
            {
                S.insert(res+1);
                ++j;
                continue;
            }
            break;
        }
        // Max value of j is got
        
        for (int k = 0; k<=i; ++k)
        {
            for (int l = 0; l<=j; ++l)
            {
                int res = pow(x,k) + pow(y,l);
                if (res <= bound){
                    S.insert(res);
                    continue;
                }
                break;
            }
        }
        
        vector<int> output;
        
        copy(S.begin(), S.end(), back_inserter(output));
        
        return output;
        
        
    }
};
```

A better solution

```C++
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
       unordered_set<int> res;
        if(x>y)swap(x,y);
        for(int i=1;i<bound;i*=x){
            for(int j=1;j<bound;j*=y){
                if(i+j<=bound)res.insert(i+j);
                else break;
                if(y==1)break;
            }
            if(x==1)break;
        }
        return vector<int>(res.begin(),res.end());
    }
};
```

## Set Mismatch

 The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array. 


### Answer

```C++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Insert all elements in map. If duplicate, out.
        // Add sum side by side. Subtract from n(n+1)/2 . Done. Missing found
        
        unordered_map<int,int> M;
        
        
        vector<int> res; // Use reserve if you want, not that (2) and all. It puts 2 zeros over there instead. 
        int sum = 0;
        
        for(int a: nums)
        {            
            if (M.find(a)!=M.end())
            {
                res.push_back(a);
                continue;
            }
            M[a]++;
            sum +=a;
        }
        
        int p = res[0];
        int n = nums.size();      
        
        res.push_back(n*(n+1)/2 - sum);
        return res;
        
    }
};
```

## Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

### Answer

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // Empty or no size match
        
        if (s.size()!=t.size())
            return false;
        
        // Add in map. Keep checking if it didn't exist. If exist, check if they match
        int i = 0;
        unordered_map<char, char> M;
        unordered_map<char, char> M2;
        
        while(i<s.size()){
            char c = s[i];
            char d = t[i];
            if(M.find(c)!=M.end()){ // If exists, check
                if (M[c]!=d)
                    return false;
            }
            if(M2.find(d)!=M2.end()){ // If exists, check
                if (M2[d]!=c)
                    return false;
            }
            
            M[c] = d;
            M2[d] = c;
            ++i;
            
        }
        
        return true;
        
    }
};

Think about edge cases thoroughly. Don't leave it halfwayy -- Finish what you started.
