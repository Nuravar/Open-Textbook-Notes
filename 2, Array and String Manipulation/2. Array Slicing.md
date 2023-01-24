# Array Slicing

Array slicing involves taking a subset from an array and allocating a new array with those elements. 
In C++ you can create a new vector of elements in `myVector`, from `startIndex` to `endIndex` like this:

```cpp
  vector<int> slice(myVector.begin() + startIndex, myVector.begin() + endIndex);
```

There is a hidden time and space cost here! As unlike just "getting elements" you are in fact. 
1. allocating a new vector
2. copying the elements from the original vector to the new vector

This takes $O(n)$ time and space complexity 

---
[Array Slicing | Interview Cake](https://www.interviewcake.com/concept/cpp/slice?course=fc1&section=array-and-string-manipulation)