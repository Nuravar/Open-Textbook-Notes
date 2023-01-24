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

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__linked_lists_sample.svg?bust=210" />
</p>

We would call each of these two-item arrays a node and these node will form to create a linked list that is connected through the pointers to the next node. 

> The first node of a linked list is usually called the head while the last node is usually called the tail. 

It is important to have a pointer variable referencing the head of a list - otherwise we would be unable to find our way back to the start of the list. 

Lets say for example in the above picture we want to add a `S` to the end of the string `DEAR`, in the diagram all we would need to do is make the pointer in the `R` node point to `S`! 

This leaves us with a function that has O(1) time which compared to a dynamic array would have cost O(n) time. 

**Linked lists have worst case O(1) appends, which is better than the worst case O(n) time of dynamic arrays**. This is intriguing as technically dynamic arrays have the same overall time append of O(1) when you consider other factors. 

On the other hand, adding a character at the start or middle of an array still has a time complexity of O(1) compared the the O(n) of dynamic arrays.

So if linked lists are so great what is the trade off?
>The ability to lookup an index in an array has a time complexity of O(1). While in a linked list the time complexity is O(n) as you have to painstakingly navigate through each node until you get the value that you want. 

>Additionally, walking down a linked list is not cache-friendly as the next node could be anywhere in memory. 

So the trade-off with linked lists is that they have faster prepends and faster appends than dynamic arrays, but they have slower lookups. 

## Hash Tables

Quick lookups are often really important. For that reason, we tend to use arrays more often than linked lists. 

For example: if we wanted to count how many times each ASCII character appears in Romeo and Juliet. How would we store these counts?

One simple way would just be to use an array where each index is the relative ASCII number:

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_chars_to_ints.svg?bust=210" />
</p>

But this array is not just a list of values. It is storing two things, the ASCII character number and the counts.

**So we can think of an array as a table with two columns... except you don't really get to pick the values in the indices column since they are always 0, 1, 2, 3, etc.**

But what if we wanted to be able to edit that column? Would it create a faster overall array?

Suppose the problem shifted and we wanted to count the number of times each **word** appears in Romeo and Juliet. Translating a character into an array index was easy. But we will have to do something more clever to translate a word into an array index.

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_lies_key_unlabeled.svg?bust=210" />
</p>

One way that we could do it is that in the word `lies` we could add up the values of the ASCII letters: $$108+105+101+115=429$$

The result is the number 429 but having an array with arbitrary indexes for each letter with a wide variety of slots blank would not make a whole lot of sense. 
+ Lets say that we only had 30 slots in our array. We could force the number into our array through the modulus operator (%). $$ 429 \% 30 = 9 $$

This data structure is called a **hash table** or **hash map**. In our hash table, the counts are the values and the words are the keys. The process we used to translate a key to an array index is called a hashing function. 

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_lies_key_labeled.svg?bust=210" />
</p>

But what if we have two words that add up to the some number like `lies` and `foes` with a value of 429? Since our hash function gives us the same value of 9 for both words, the overlap would be called a hash collision. There are a few different strategies for dealing with them:

The common one is instead of storing the actual values in our array, we can have each array slow hold a pointer to a linked list holding the counts for all the words that a hash to that index. 

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_hash_collision.svg?bust=210" />
</p>

One problem is how would we know each count is for `lies` and the other for `foes`, the answer would simply be creating a new linked list node:

<p align="center">
  <img src="https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_hash_collision_key_val.svg?bust=210" />
</p>

>Now lookups in our hash table take O(n) time in the worst case since we have to walk down a linked list! That is true, but the actual worst case scenario would be that *every* key would create a hash collision creating just a linked list.

Collisions are rare enough that on average lookups in a hash table are O(1) time. That is the tradeoff for a hash table, you get fast lookups by key... except some lookups could be slow. 

---
Citations:
[Data Structures | Interview Slice](https://www.interviewcake.com/article/cpp/data-structures-coding-interview?course=fc1&section=algorithmic-thinking)