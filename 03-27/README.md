# Fisher-Yates Shuffle

This algorithm is used to shuffle a finite sequence, for example a deck
of cards. It can be summarized as follows:
- Choose a random element from the sequence and remove it
- Shuffle the remaining sequence of elements
- Place the randomly selected element at the front

Write a recursive function to shuffle the characters of a given string:

```c++
string randomShuffle(string input);
```

# String Subsequences

Write a recursive function named `​isSubsequence`​ ​that takes two strings 
and returns true if the second string is a subsequence of the first 
string. A string is a subsequence of another if it contains the same 
letters in the same order, but not necessarily consecutively. You can
assume both strings are already lower-cased.

For example:
- isSubsequence("computer", "core") returns `false`
- isSubsequence("computer", "cope") returns `true`
- isSubsequence("computer", "computer") returns `true`

```c++
bool isSubsequence(string first, string second);
```
