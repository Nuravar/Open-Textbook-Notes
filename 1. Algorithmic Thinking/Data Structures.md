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


