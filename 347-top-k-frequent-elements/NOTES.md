**APPROACHES**
​
**1. Brute Force**:  Sort the array and then maintain a count variable to find the maximum repeated element. Then again do the same to find second maximum element.
Time Complexity: O(nlogn)
​
**2. Better Solution 1**: Create a map of given array, then create another multimap to store reverse of key and value pair so that the frequency gets sorted.
Time Complexity: O(nlogn)
**3. Better Solution 2**: USING HEAPS. First create map of array to store frequency of individual elements. Then store the frequency in a heap to find out maximum freq.
Time Complexity: O(k logn), where k = given in question
**4. Optimal Solution**: Create a map to store frequency. Then Form an array of size nums.size(), because if all the elements are same then the frequency of array will be equal to nums.size(). The array's index will act as frequency and its element corresponding to the index will denote all the elements of nums which has frequency equal to that index.
​
Time Complexity: O(n)
Space Complexity: O(n)