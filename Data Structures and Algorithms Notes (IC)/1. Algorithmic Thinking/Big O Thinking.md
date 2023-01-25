# Big O Notation

Big O notation is the language we use for talking about how long an algorithm takes to run. It is how we compare the efficiency of different approaches to a problem. 

With big O notation we express runtime In terms of _how quickly it grows relative to the input, as the input gets arbitrarily large_.

1. **How quickly the runtime grows**
a. It is hard to pin down the exact runtime of an algorithm. So we instead measure how quickly the runtime grows over an amount
2. **Relative to the input**
a. If we measure our runtime directly, we could express our speed in seconds. But since we are measure the rate of growth, we use different notation to measure the rate. This measurement is based on the order of the size of the input (O(n), O(n2), etc.)
3. **As the input gets arbitrarily large**
a. For big O analysis, we care most about the stuff that grows fastest as the input grows. 


```cpp
void printFirstItem(const vector<int>& items)
{
    cout << items[0] << endl;
}
```

This function runs in O(1) time (constant) relative to its input, since it just requires one step.


```cpp
void printAllItems(const vector<int>& items)
{
    for (int item : items) {
        cout << item << endl;
    }
}
```

This function runs in O(n) time (linear), where n is the number of items in the vector. 
 + additionally if you have two loops that are inside each other you would get a big O notation with a value of O($n^2$)

### Drop the Constants    

When you are calculating the big O complexity of something, you just throw out the constants. So in this example:

```cpp
void printFirstItemThenFirstHalfThenSayHi100Times(const vector<int>& items) {
    cout << items[0] << endl;

    size_t middleIndex = items.size() / 2;
    size_t index = 0;

    while (index < middleIndex) {
        cout << items[index] << endl;
        ++index;
    }

    for (size_t i = 0; i < 100; ++i) {
        cout << "hi" << endl;
    }
}
```

This would be 3 equations with O(1 + n/2 + 100) which again simplifies out to O(n)

For big O notation since we are looking at numbers as n gets arbitrarily large, the order is the only thing that matters. 
+  O($n^3 + 50n^2 + 10000$) is O($n^3$)
+  O($(n + 30) * (n + 5)$) is O($n^2$)

## We Consider the "Worst Case"

```cpp

  bool contains(const vector<int>& haystack, int needle)
{
    // does the haystack contain the needle?
    for (int n : haystack) {
        if (n == needle) {
            return true;
        }
    }

    return false;
}
```

In examples, like this we could find the needle on the first element in the list but we only consider that we would find it on the last possible element.

## Space Complexity
Sometimes we want to optimize the amount of memory that a piece of code use, we simply use to total size of any new variables we are allocating. 

```cpp
void sayHiNTimes(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        cout << "hi" << endl;
    }
}

```
This function takes up O(1) space since we use a fixed number of variables.

```cpp
vector<string> vectorOfHiNTimes(size_t n) {
    vector<string> hiVector;
    for (size_t i = 0; i < n; ++i) {
        hiVector.push_back("hi");
    }
    return hiVector;
}
```
This function uses up O(n) space as the vector hiVector scales up with the amount of items in the structure. 

Usually when we talk about space complexity, **we are taking about the additional space** and we do not consider the space taken up by the inputs. 

## Big O Analysis is Awesome Except...

When coding you should be thinking about the time and space complexity of algorithms as you design them. 

Big O ignores constants, but sometimes constants matter. 
> If we have a script that takes 5 hours to run, an optimization that divides the runtime by 5 might not affect big O, but it still saves you 4 hours of waiting.

#### Beware of premature optimization
Sometimes optimizing time or space negatively impacts the readability or coding time. 

> A great engineer (start-up or otherwise) knows how to strike the right balance between runtime, space, implementation time, maintainability, and readability.

___

[Big O Notation | Interview Cake](https://www.interviewcake.com/article/cpp/big-o-notation-time-and-space-complexity?course=fc1&section=algorithmic-thinking)
