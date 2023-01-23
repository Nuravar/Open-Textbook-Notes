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
 + additionally with multiple functions that are beside each other with a value of O(2n) we would ignore the constant making the function run in O(n) time


