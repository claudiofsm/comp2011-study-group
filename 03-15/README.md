# Bubble Sort

Bubble sort is an easy and simple sorting algorithm every computer science
student must learn. We are going to write a function that performs bubble sort
on a given array of integers.

## Algorithm

To sort an array containing `n` elements in ascending order, we start from the 
`0-th` element and compare it with the `1-th` element. If they are not in 
ascending order we swap them. Next we compare the `1-th` and `2-th` element, 
and the process is continued until the end of the array. In this way the 
largest elements will be "bubbled" to the end of the array, and after *at most*
`n-1` passes, we sorted the array in ascending order.

## Illustration

Suppose we have an array of integers `[ 6, 3, 0, 5 ]`.

### First Pass

1. Compare `6` and `3`. Do a swap. Array becomes `[ 3, 6, 0, 5 ]`.
1. Compare `6` and `0`. Do a swap. Array becomes `[ 3, 0, 6, 5 ]`.
1. Compare `6` and `5`. Do a swap. Array becomes `[ 3, 0, 5, 6 ]`.
1. Now the `3-th` element is sorted correctly, and can be ignored in subsequent
passes.

### Second Pass

1. Compare `3` and `0`. Do a swap. Array becomes `[ 0, 3, 5, 6 ]`.
1. Compare `3` and `5`. Do not swap. Array becomes `[ 0, 3, 5, 6 ]`.
1. Now the `2-th` element is sorted correctly, and can be ignored in subsequent
passes.

### Third Pass

1. Compare `0` and `3`. Do not swap. Array becomes `[ 0, 3, 5, 6 ]`. 
1. Now both the `0-th` and `1-th` element are sorted correctly. We are done!

It can be seen that we sort the array in `4 - 1 = 3` passes. Notice that each
pass results in one more element near the end of the arrary being sorted and
can be ignored in subsequent passes.

## Programming Exercises

1. Write a function `bubble_sort` which takes two parameters:
    - an integer array `arr`
    - an integer `size` which denotes the number of elements in the array `arr`

    After the function returns, the elements in the array supplied to the 
    function will be sorted in ascending order.
1. Write a function `bubble_sort_descending` which takes two parameters:
    - an integer array `arr`
    - an integer `size` which denotes the number of elements in the array `arr`

    After the function returns, the elements in the array supplied to the 
    function will be sorted in descending order.
1. Modify `bubble_sort` and `bubble_sort_descending` to use a recursive
approach.
