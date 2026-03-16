# Code-Expression-Data-Structures-Problem---III
Problem 3: Given an array of integers and a window size k, find the maximum element in each sliding window.

Example: Array -> [1,3,-1,-3,5,3,6,7]   k->3   Output : 3 3 5 5 6 7

Example: Array->  [4, 2, 12, 3, 8, 7, 5] k->3  Output:  12 12 12 8 8  
# Solution:
1. Initialize Structures:

   Use a Deque (Double-Ended Queue) to store indices of array elements.

2. Process the Array:

   Iterate through the array from index i = 0 to n-1.

3. Maintain the Window (Front Check):

   If the index at the front of the deque is equal to i - k, it means that element has fallen out of the current window. Pop from front.

4. Maintain Monotonicity (Back Check):

   While the deque is not empty and the current element arr[i] is greater than the element at the back of the deque:

    Pop from back. (This ensures the deque only keeps elements that could potentially be the maximum).

5. Add Current Element:

   Push the current index i to the back of the deque.

6. Store/Print Result:

   Once the first window is complete (i.e., i >= k - 1), the element at the front of the deque is the maximum for the current window. Print arr[dq.front()].
