# Logarithms

## What does logarithm even mean?
In general a logarithm asks "What power must we raise this base to, in order to get this answer?"

$ log_{10}(100)$ which would translate into $ 10^x = 100$ where $x=2$.

## Where logs come up in algorithms and interviews
**"How many times must we double 1 before we get to $n$"**? If often a question we ask ourselves in computer science or **"How many times must we divide $n$ in half to get back down to 1"**?

The answer to both of these question is $log_{2} n $

## Logarithms in Binary Search

Binary search is the process where: 
1. Start with the middle number: is it bigger or smaller than our target number?
2. We've effectively divided the problem in half.
3. Repeat the same approach (of starting in the middle) on the new half-size problem.

Which in code looks like 

```cpp
  bool binarySearch(int target, const vector<int>& nums) {
    size_t floorIndex = 0; //starts with the bounds at the start
    size_t ceilingIndex = nums.size(); //... and the end

    while (floorIndex < ceilingIndex) {
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDistance = distance / 2;
        size_t guessIndex = floorIndex + halfDistance;
        int guessValue = nums[guessIndex]; 

        if (guessValue == target) { // if the middle value is the target number
            return true;
        }
        if (guessValue > target) {
            // target is to the left, so move ceiling to the left
            ceilingIndex = guessIndex;
        }
        else {
            // target is to the right, so move floor to the right
            floorIndex = guessIndex + 1;
        }
    }
    return false; // if the number is not found return false
}

```

So what is the time cost of binary search? The only non-constant part of our time cost is the number of times our while loop runs. This leads us back to our original question of **"How many times must we double 1 before we get to $n$"**? 
+ leading to a total time cost of binary search being $O(log_2n)$

## Logarithms in Sorting

Sorting costs $O(n*log_2n)$ time in general, it is the best worst case runtime we can get for sorting. For example, in merge sort, the idea is to divide the vector in half, sort the two halves, merge the halves into one and keep sorting. 

```cpp
void mergeSort(vector<int>& vectorToSort){
    // BASE CASE: arrays with fewer than 2 elements are sorted
    if (vectorToSort.size() < 2) {
        return;
    }
    // STEP 1: divide the array in half
    // we use integer division, so we'll never get a "half index"
    size_t midIndex = vectorToSort.size() / 2;

    vector<int> left(vectorToSort.begin(), vectorToSort.begin() + midIndex);
    vector<int> right(vectorToSort.begin() + midIndex, vectorToSort.end());

    // STEP 2: sort each half
    mergeSort(left);
    mergeSort(right);

    // STEP 3: merge the sorted halves
    size_t currentLeftIndex  = 0;
    size_t currentRightIndex = 0;

    for (size_t currentSortedIndex = 0; currentSortedIndex < vectorToSort.size();
            ++currentSortedIndex) {

        // sortedLeft's first element comes next
        // if it's less than sortedRight's first
        // element or if sortedRight is exhausted
        if (currentLeftIndex < left.size()
                && (currentRightIndex >= right.size()
                || left[currentLeftIndex] < right[currentRightIndex])) {
            vectorToSort[currentSortedIndex] = left[currentLeftIndex];
            ++currentLeftIndex;
        }
        else {
            vectorToSort[currentSortedIndex] = right[currentRightIndex];
            ++currentRightIndex;
        }
    }
}
```
The $log_{2}{n}$ comes from the number of times we have to cut n in half to get down to subvectors of just 1 element (our base case). The additional n comes from the time cost of merging all n items together each time we merge two sorted subvectors.

## Logarithms in Binary Trees

In a binary tree, each node has two or fewer children,

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/binary_tree__depth_5.svg?bust=210" />
</p>

The tree above is a special case because each "level" of the tree is full. We call such a tree "perfect". 

One question we might ask is, if there are n nodes in total, what is the tree's height (h) or how many levels does it have?

If we count the number of nodes on each level, we notice that it doubles as we go. Which brings us back to the question: **"How many times must we double 1 before we get to $n$"?** 

The exact formula for the number of nodes on the last level is $(n+1)/2$. Leading to the height roughly being around $h \approx  log_2((n+1)/2)$ which simplified becomes $h = log_2(n+1)$

---
[Logarithms | Interview Slice](https://www.interviewcake.com/article/cpp/logarithms?course=fc1&section=algorithmic-thinking)