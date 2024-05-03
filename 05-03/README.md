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

## 1. Remove Duplicates

Write a ```remove_duplicates()``` function which takes a list sorted in 
increasing order and deletes any duplicate nodes from the list. Ideally, the 
list should only be traversed once.

For example, if the original list is ```{1, 2, 2, 3, 4, 4, 5}```, after calling
this function, the resulting list becomes ```{1, 2, 3, 4, 5}```.

```c++
void remove_duplicates(Node*& list);
```

## 2. Alternating Split

Write a function ```alternating_split()``` that takes one list and divides up 
its nodes to make two smaller lists. The sublists should be made from 
alternating elements in the original list. So if the original list is 
```{1, 2, 1, 2, 1}```, then one sublist should be ```{1, 1, 1}``` and the
other should be ```{2, 2}```. The elements in the new lists may be in any order 
(for some implementations, it turns out to be convenient if they are in the 
reverse order from the original list.)

```c++
/**
 * Given the source list, split its nodes into two shorter lists.
 * If we number the elements 0, 1, 2, ... then all the even elements
 * should go in the first list, and all the odd elements in the second.
 * The elements in the new lists may be in any order.
 *
 * @param list   the list to be split
 * @param first  stores the head to the first resulting list
 * @param right  stores the head to the second resulting list
 */
void alternating_split(Node* list, Node*& first, Node*& second);
```

## 3. Reverse

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
void reverse(Node*& list);
```
