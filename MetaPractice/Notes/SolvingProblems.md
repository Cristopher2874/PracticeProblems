## Steps to solve a programming problem

#### 1. Listen to the problem

* Take notes or screenshots.
* Ask questions.
* Clarify the problem.

#### 2. Draw an example

* Optional step.
* Helps to visualize the problem.
* Example of input and output.
* Look for non common patterns, not all the triangles are equilateral.
* Larger and generic cases, not special ones.

#### 3. Look up for the brute force solution

* Stupid way to do it, supposing I don't know aany algorithms
* Figure out the complexity and how to improve it.

#### 4. Optimize

* Maybe optimize before write the code.
* Take into consideration the complexity.

#### 5. Walk through algorithm.

* Make sure what are you doing.
* Make sure you are doing it correctly.
* Check the approach and the steps of the code.
* Understand what is your algorithm doing.

#### 6. Code

* Write the basics of the code.
* Write the code in a way that is easy to understand.
* Use conventions.

#### 7. Verification

* Runtime
* Test cases
* Different values manually
* Bug free at possible

## Optimize With BUD (Bottlenecks, Unnecessary work, Duplicated work)

* For bottlenecks, chek if there is a possible solution or new approach to reduce the cahrge.
* For the unnecessary work, check if there is a way to save steps in calculating details that are not used.
* For duplicated work, check if there is a way to store or access the values already calculated. Generally **Hash Table**

#### Optimize with time and space

* Scarifice the space for better run time or viceversa
* Call out this approach
* Hash Tables
* Pre-computation
* Tries
* Space complexity can't beat the time complexity, for example, create O(n) memory, will require, O(n) time.
* **Best Conceivable Time**: given the problem, what is the minimum runtime that we can get to
* As consecuence, if there is an step that requires less time than the BCT, this could be not considered and will not be considered in the final runtime.

#### optimize with DIY

* Generate the generic and large example
* Try to solve the problem with the generic example, with the logical approach
* Apply reversed engineering
* Use the tricks found