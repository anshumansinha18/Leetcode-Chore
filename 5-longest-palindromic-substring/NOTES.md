**APPROACHES**
​
1. *Brute Force*: Test out every substring. TC: O(n^3)
​
2. *Optimal*: Inside out approach. TC: O(n^2)
​
Eg.   s = "babad"
for i=1:
go to its left and right and compare characters.
b = b (on left and right side of a)
so, it is a palindrom. store it inside res.
repeat this step for every char.