**Approaches**
​
1. *using extra space*. put the last k elements at the beginning of the array & rest of array at the end.
​
2. Rotate one by one
​
3. *Using reverse operation:*
i. reverse(arr, 0, n-k-1);
reverse(arr, n-k, n);
reverse(arr);
​