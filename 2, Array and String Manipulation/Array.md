# Array

## Quick Reference:

An array organizes items sequentially, one after another in memory. Each position in the array has an index starting at 0. 

####Strengths
+ Fast Lookups
+ Fast appends
####Weaknesses
+ Fixed Size
+ Costly inserts and deletes
    + the "scoot over" motion other elements have to do to fill in the gaps

Function | Worst Case 
--- | ---
space | $O(n)$
lookup | $O(1)$
append | $O(1)$
insert | $O(n)$
delete | $O(n)$

###In C++:
This is how an array looks in C++.

```cpp
// declare an array that holds 10 integers
int gasPrices[10];

gasPrices[0] = 346;
gasPrices[1] = 360;
gasPrices[2] = 354;
```

--- 
[Arrays | Interview Slice](https://www.interviewcake.com/concept/cpp/array?course=fc1&section=array-and-string-manipulation)