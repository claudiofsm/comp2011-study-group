# Mid-term Exam Preparation

The following sections outline some tricky points instructors love to test in
exams. Knowing these tricks will save you valuable points that may cost you a
sub-grade!

## Prefix and Postfix

- What is the differnece in value between the expression `++n` and `n++`?
- What is the output of the program below?

```
#include <iostream>
using namespace std;

int main()
{
    int n = 4, k = 2;

    cout << ++n << endl;
    cout << n << endl;
    cout << n++ << endl;
    cout << n << endl;
    cout << -n << endl;
    cout << n << endl;

    cout << --n << endl;
    cout << n << endl;

    cout << n-- << endl;
    cout << n << endl;

    cout << n + k << endl;
    cout << n << endl;
    cout << k << endl;
    cout << n << k << endl;
    cout << n << endl;
    cout << " " << n << endl;
    cout << " n" << endl;
    cout << "\n" << endl;
    cout << " n * n = "; //CAREFUL!
    cout << n * n << endl;
    cout << 'n' << endl;

    return 0;
}
```

## Value of Assignments

- Do you know that the assignment `n = 4` can be used as an expression and has an evaluated value?
- What is the output of the below code fragment?

```
int n = 5;
if (n = 0)
    cout << "n is zero" << ".\n";
else
    cout << "n is not zero" << ".\n";
cout << "The square of n is " << n * n << ".\n";
```

## Values of `true` and `false`

- What is(are) the value(s) that is(are) evaluated to `true` and `false` respectively?

- What is the output of the program below?

```
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << (n = 4) << endl;
    cout << (n == 4) << endl;
    cout << (n > 3) << endl;
    cout << (n < 4) << endl;
    cout << (n = 0) << endl;
    cout << (n == 0) << endl;
    cout << (n > 0) << endl;
    cout << (n && 4) << endl;
    cout << (n || 4) << endl;
    cout << (!n) << endl;
    return 0;
}
```

## Short-circuit Evaluation

- Do you know that C++ will skip evaluation of the expression to the right of `&&` and `||` operators?
- What is the output of the following code fragment?

```
int found = 0, count = 5;
if (!found || --count == 0)
    cout << "danger" << endl;
cout << "count = " << count << endl;
```

## Braces in `if`, `for` and `while`

- What will happen if we don't put braces to surround the statements under the above constructs?
- What will be the output of the below code fragment?

```
int n = 10;
while (n > 0)
    n /= 2;
    cout << n * n << endl;
```

## Empty Statement

- `;` on its own is a statement.
- What will be the output of the following code fragment?

```
int k;
for (k = 0; k < 10; k++);
    cout << "k is " << k << endl;
```

## Unreachable Branches

- If you are not careful you may write branches that are unreachable:

```
int n;
cout << "Enter an integer: ";
cin >> n;
if (n < 10)
    cout << "less than 10" << endl;
else if (n > 5)
    cout << "greater than 5" << endl;
else
    cout << "not interesting" << endl;
```

## Infinite Loops

- Remember to update the loop condition.
- What is the output of the following code fragment?

```
cout << "Here's a list of the ASCII values of all the upper"
     << " case letters.\n";
char letter = 'A';
while (letter <= 'Z')
    cout << letter << " " << int(letter) << endl;
```

## Fall-through in `switch`
- Notice that execution will fall to the next `case` if there is no `break`.
- What is the output of the below code fragment?

```
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        switch (i)
        {
            case 0: 
                cout << "0";
            case 1: 
                cout << "1"; 
                continue;
            case 2: 
                cout << "2";
                continue;
            default: 
                cout << "D";
                break;
        }
        cout << ".";
    }
    return 0;
}
```

## Other Useful Things to Remember
- The decimal values of `'a'` to `'z'` range from 97 to 122, `'A'` to `'Z'`
from 65 to 90, `'0'` to `'9'` from 48 to 57.
- The precedence of common operators, such as `++`, `--`, `==`, `!=`, `&&`,
`||`, and `a ? b : c `. Check out 
[this](https://en.cppreference.com/w/cpp/language/operator_precedence) table.
- If you are given a code fragment and are asked to determine its output, 
watch out that the fragment may even fail to be compiled, i.e. compilation
error is a possible output.

## Additional Resource

The program fragments used in this document are copied from the following:
- [https://clas.iusb.edu/docs/CSCI/C101-PracticeProblems.pdf](https://clas.iusb.edu/docs/CSCI/C101-PracticeProblems.pdf)

The level of the questions in my opionion is about right for a beginner course.
If you have attempted the questions yourself and be aware of the tricky things
that are asked for each question, you must be able to pass the mid-term exam.