# Linked Lists Programming Exercises

## Common Data Structure

Let's assume that in the following exercises, we have defined a strcuture for
the nodes of out lists:

```c++
struct Node {
    int data;
    Node* next;
};
```

## Tasks

You have to implement the ```removeDuplicates()``` and ```reverse()``` functions
in ```list.cpp```.

### Task 1: Remove Duplicates

Write a ```remove_duplicates()``` function which takes a list sorted in 
increasing order and deletes any duplicate nodes from the list. Ideally, the 
list should only be traversed once.

For example, if the original list is ```{1, 2, 2, 3, 4, 4, 5}```, after calling
this function, the resulting list becomes ```{1, 2, 3, 4, 5}```.

```c++
/**
 * Removes duplicating items from the supplied list.
 * 
 * @param list  a reference to the head of the list to have duplicates removed.
 */
void removeDuplicates(Node*& list) {
    // TODO: Replace the codes below with your implementation
    list = nullptr;
}
```

### Task 2: Reverse

Write an iterative ```reverse()``` function that reverses a list by rearranging 
all the ```next``` pointers and the head pointer. Ideally, ```reverse()``` 
should only need to make one pass of the list. 

For example, if the original list is ```{1, 2, 3, 4, 5}```, after calling this
function, the list becomes ```{5, 4, 3, 2, 1}```.

```c++
/**
 * Reverses the supplied linked list.
 * 
 * @param list  a reference to the head of the list to be reversed.
 */
void reverse(Node*& list) {
    // TODO: Replace the codes below with your implementation
    list = nullptr;
}
```

## Compilation

In your terminal program, go to the directory containing the ```main.cpp```
file, and type the following:

```
g++ -Wall -g -O0 -o list_exercise main.cpp list_utility.cpp list.cpp testcases.cpp reverse_tests.cpp remove_duplicates_tests.cpp
```

Then, you may run the program as follows:

```
./list_exercise
```

## Output

Before you implement anything in ```list.cpp```, you will see the following
output:

```
Test removeDuplicates() function
--------------------------------
Test null list: Passed
Single element list: FAILED
List without duplicates: FAILED
List with duplicates - A: FAILED
List with duplicates - B: FAILED
List with duplicates - C: FAILED
List with duplicates - D: FAILED

Test reverse() function
-----------------------
Test null list: Passed
Test single element list: FAILED
Test multiple element list: FAILED

All testcases completed.
```

After you have got your implementation correct, you will see:

```
Test removeDuplicates() function
--------------------------------
Test null list: Passed
Single element list: Passed
List without duplicates: Passed
List with duplicates - A: Passed
List with duplicates - B: Passed
List with duplicates - C: Passed
List with duplicates - D: Passed

Test reverse() function
-----------------------
Test null list: Passed
Test single element list: Passed
Test multiple element list: Passed

All testcases completed.
```
