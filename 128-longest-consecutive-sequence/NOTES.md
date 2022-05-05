**APPROACHES**
​
1. Use Hash maps: TC: O(nlogn)
​
2. Optimal approach: Create an unordered map for array. Then, select those elements from array which could be the start of sequence by checking -> m[arr[i]-1]>0 or not. Then, iterate over those element to check for sequence.