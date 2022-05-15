**APPROACHES**
​
*1. Sliding Window:* Eg. Consider a window - BABB. In this the maximum freq is of char 'B'. So, we only have to replace the other characters apart from B.
Use-
```
if( windowLength - maxFreq <= k) r++;
else l++;
```
​
Time Complexity: O(26n)
​
*2. Optimized Sliding Window Approach:*  Use maxf = max(maxf, ++count[s[i]]);
Time Complexity: O(n)