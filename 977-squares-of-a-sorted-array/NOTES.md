**Approaches:**
​
1. First sqaure the arrays, then apply merge sort. DO NOT APPLY QUICK SORT as it will cause TLE since the array is already sorted.
​
2. Apply Merge Function of Merge Sort
​
3. Two Pointer Approach: Compare low & high.
if(low<high) push arr[high]^2 into res and do high--;
else push arr[low]^2 into res and do low++;