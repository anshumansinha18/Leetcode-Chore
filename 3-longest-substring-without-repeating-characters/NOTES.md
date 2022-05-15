**APPROACHES**
​
1. Sliding Window Approach: Use two pointers, set it to 0 each. Then iterate second pointer while storing chars in set or map until you find repeating element. After finding repeating element, increament first pointer to find the repeating character in the substring formed so far between first and second pointer.
Time Complexity: O(2n)
2. Sliding window optimized: In the above approach, on finding the repeating character, we had to increment the first pointer using while loop till we found the repeating character in the substring. But in this approach, we will directly jump to that repeating character without iterating by storing the index of every char in a map instead of storing its frequency.
​
Time Complexity: O(n)
Refer Striver's Video for better understanding: [https://www.youtube.com/watch?v=qtVh-XEpsJo](http://)
​
​