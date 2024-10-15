## Efficiency of the code

* Meaning that the code is using resources and how much space and time it will consume.

* **Important for the optimization of the code**

* The Big O scale tells the programmer what happens when the data becomes larger and larger

* The idea is to compare the efficiency of the code when the information is larger.

Types:

* Constant: O(1)
* Linear: O(n)
* Logarithmic: O(log n)
* Quadratic: O(n^2)
* Cubic: O(n^3)
* Exponential: O(2^n)
* Factorial: O(n!)

O means *"Order of..."* and the expression.

Define what **n** means for the algorithm, depending of the definition the complexity could be changed.

The complexity pull out the constants, for example: **O(3n) = O(n)** because the complexity is affected by the larger size of operations.
The importance is how the **runtime** scales.

Depending on the variables and number of loops or consults, it is possible to assing a max value to the execution time.

For example, for an array of size n, with numbers, if we print the even numbers until the found even number, the complexity
could be expressed as O(n*k), where k represents the largest value of the largest even number, with that, we approximate the 
time complexity for the program.

The product is used to express different variables relationships and operations.

### Main tips
1. Include all the sections of code, function calls, loops, recursion, etc, the idea is to not leave out any call or cicle
for example, in a O(n) function that calls another funciton, it is necessary to include the complexity of this new funtion.
2. Use names and meanings in the variable names for expressing the complexity of the runtime.
3. Define the variables that are needed depending on the quantity of runs that the code presents.
4. Add the runtimes for each step taken in the code process, for example, step 1 takes O(n) time, step 2 takes O(n) times, then 
the step 3 takes O(d) times, the final complexity is *O(n + n + d)*, which is traduced to *O(2n + d)*. It is also possible to multiply, 
when the steps are calling other steps in the execution, addition is for isolated runtimes and product is for nested calls.
5. Drop constants of the runtime.
6. Use Big O for the space complexity depending on the call stack of the code and the extra variables and structures created.
7. Drop the non dominant terms as constants. For example in a complexity *O(a + a2)*, the final complexity would be **O(a2)**.

### Extra

When using Big O, there is necessary to consider the space and time complexity. Not in all cases the O(n) function is faster than
the O(n2) function, the complexity means that for larger data sets, the runtime will be more efficient, but does not relate to the 
small cases for runtime. O(n) is faster when the data is larger enough.

#### the complexity depends on the scale!