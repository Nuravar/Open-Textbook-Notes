# Data Structures

## Random Access Memory (RAM)
Variables are stored in RAM:

Think of RAM like a really tall bookcase with billions of numbered shelves, this number being the shelf's address. 
<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__ram_empty_with_indices.svg?bust=210" />
</p>

Each shelf holds 8 bits. A **bit** is a tiny electrical switch that can be turned on or off, we call it a 1 or a 0.

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__ram_bits.svg?bust=210" />
</p>

8 bits is called a byte and each address in the memory can only hold 1 byte of memory storage. We also have the **processor** that does all of the real work inside of our computer.
+ this processor is connected to a **memory controller**. The memory controller does all of the actual reading and writing to and from the RAM. It has a direct connection to each shelf of RAM

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__ram_memory_controller.svg?bust=210" />
</p>

That *direct communication* is important as we can access each individual shelf without needing to climb up and down the bookcase. 
>That is why we call it random access memory (RAM) since we can *access* the bits at any random address in memory.

Even though the memory controller can jump between far apart memory addresses it prefers to access memory that is nearby. **Computers are tuned to take less time to access memory addresses that are near each other**. The way that this works is: 
+ The processor has a cache where it stores a copy of the the stuff that it has read recently from the RAM

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__ram_cache.svg?bust=210" />
</p>

+ this cache is much faster to read from than RAM, so the preprocessor saves time whenever it can read something from cache instead of going out to RAM.

**When the processor asks for the contents of a given memory address, the memory controller also sends the contents of a handful of nearby memory addresses** which is then put into the cache. 

## Binary Numbers

To understand Base2 Binary numbers, we need to take a closer look at how decimal numbers work. Take the number "101" in decimal: $$101$$

We have two "1"s but they mean different things based on their order. In base 10, this tells us that we have 1 hundred, 0 tens, and 1 one.

The places in *binary* are sequential in powers of 2:
+ $2^0 = 1$
+ $2^1 = 2$
+ $2^2 = 4$
+ $2^3 = 8$
+ etc.

So the same number "101" in base two would be 1 fours, 0 twos, and 1 ones giving us a value of 5.

Here are some more examples:
Decimal | Binary
--- | ---
0 | 0000
1 | 0001
2|0010
3|0011
4|0100
55|0101
6|0110
7|0111
8|1000
9|1001
10|1010
11|1011
12|1100

So far we have been talking about **unsigned integers**  which means a non-negative, whole number. But other types of numbers are:
+ fractions
    + Store two numbers the numerator and denominator 
+ decimals
    + Stores two numbers, the number without the decimals and the position where the decimal places go 
+ negative numbers
    + Reserves the leftmost bit for expressing the sign of the number, 0 for positive and 1 for negative

---
### Fixed-width Integers
Most Integers are fixed-width meaning the number of bits that they take up usually does not change. In big O notation, we say fixed-width integers take up constant space or O(1) space. 
+ And since they have a constant number of bits, most simple operations on fixed-width integers take constant time
    + the trade-off for the space efficiency and time efficiency is that fixed-width integers have limited values to a specific max

---

## Arrays
1. Each item in the array is the same size
2. the array is uninterrupted (contiguous) in memory

The constraint of an array is that:
+ the array items all have to be the same
+ there need to be a lot of free interrupted memory for the array to be stored 

##Pointers

If we wanted to create an array of string that each individually had different length we would be out of luck right? Since that would violate the rule of allotted memory that all items in an array need to the be the same size.

What we can do is instead of storing the strings right inside our array, we can just place the strings wherever we can in memory. Then we will have each element in our array hold the address in memory of its corresponding string. With each address being an integer, we would have an array of integers that we call **pointers** since it points to another spot in memory. 

This fixes two disadvantages of arrays:
1. The items don't have to be the same length - each string can be as long or as short as we want 
2. We don't need enough uninterrupted free memory to store all our strings next to each other - we can instead place them separately, wherever there is space in RAM

But this creates a new problem:
Since the memory controller send the contents of nearby memory addresses to the processor with each read as we are using pointers that are not sequential to each other. The trade-off is that an array of pointers is not **cache friendly or fast with close by items**.
+ as a result it is not as fast as a normal array

## Dynamic Arrays
**When we allocate an array in a low-level language like C++ or C, we have to specify upfront how many indices we want our array to have**

The reason for this specification is that the computer has to reserve space in memory for the array and commit to not letting anything else use up that space. 

Compared to a set size of a string a **dynamic array** is an array that can resize itself when it runs out of space. 

When you allocate a dynamic array, your dynamic array makes an underlying static array who's size depends on the implementation. 


If you append 4 items to you dynamic array:
<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__dynamic_arrays_10_indices.svg?bust=210" />
   <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__dynamic_arrays_dear.svg?bust=210"/>
</p>

We would say that this array has a size of 4 but a capacity of 10. The dynamic array stores an end_index, which in this case would be at 3, to keep track of where the dynamic array ends.

Eventually if you keep appending at some point you will use up all 10 slots of capacity. This is when a few things will occur:

1. **Make a new, bigger array**
2. **Copy each element from the old array into the new array**
3. **Free up the old array**
4. **Append your new item**

We could call these appends "doubling" appends since they require us to make a new array that is usually double the size of the old array. 

Appending an item to an array is usually O(1) time operation, but a single doubling append is an O(n) time operation since we have to copy all n items from the original array.

But while the time cost of each special O(n) doubling append doubles each time the number of O(1) appends you get until the next doubling also doubles. This cancels out the time usage from the append which allows us to say that each append has an average cost or amortized cost of O(1).

> In an interview, if we were worried about that O(n)-time worst case cost of appends, we might try to use a normal, non-dynamic array. 

**The advantage of a dynamic array over arrays is that you do not have to specify he size ahead of time but the disadvantage is that some appends can be expensive.

## Linked Lists

Can we build a data structure that can store a string, has fast appends, and does not require you to say how long the string will be ahead of time?

What if each *character* in our string were a two-index array with:
+ the character itself
+ a pointer to the next character

