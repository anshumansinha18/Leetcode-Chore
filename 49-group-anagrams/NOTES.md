**APPROACHES**
​
*1. Brute Force:* Match one string with all the other strings.
Time Complexity: O(n^2 * m^2)
*2. Better Approach:* First Sort then, **map<string, vector<string>>**
Time Complexity: O(m*nlog n)
3. Optimal Approach: **map<map<char, int>, vector<string>>**
Time Complexity: O(m*n)