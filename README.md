#                                         push\_swap
## Objective:
The primary goal of the push_swap project is to create a sorting algorithm that sorts a given set of integers using two stacks and a limited set of operations.

## Constraints:
Stacks: Two stacks are provided: Stack A (initially containing the input integers) and Stack B (initially empty).
Operations: A limited set of operations is allowed:
sa: Swap the first two integers at the top of Stack A.
sb: Swap the first two integers at the top of Stack B.
ss: Equivalent to performing sa and sb simultaneously.
pa: Push the top integer from Stack B to the top of Stack A.
pb: Push the top integer from Stack A to the top of Stack B.
ra: Rotate Stack A (shift all integers up by one, moving the top integer to the bottom).
rb: Rotate Stack B.
rr: Equivalent to performing ra and rb simultaneously.
rra: Reverse rotate Stack A (shift all integers down by one, moving the bottom integer to the top).
rrb: Reverse rotate Stack B.
rrr: Equivalent to performing rra and rrb simultaneously.
## Sorting Algorithm:
must design an algorithm that sorts the integers in Stack A using the provided operations while adhering to the following principles:

Minimize the total number of operations.
Utilize Stack B as an auxiliary stack strategically to optimize the sorting process.
Handle various edge cases efficiently.
## Approach:
Input Parsing: Read the integers from the input and initialize Stack A with them.
Sorting Algorithm: Design an algorithm to sort Stack A using the allowed operations.
This algorithm may vary in complexity and efficiency. Common approaches include:
Variants of quicksort or insertion sort adapted for stack operations.
Strategies to minimize the number of operations, such as minimizing data movement or identifying patterns for optimization.
Output: Output the sequence of operations required to sort Stack A.
## Optimization and Testing:
Optimization: Optimize the sorting algorithm to minimize the number of operations. This may involve analyzing different sorting strategies, considering edge cases, and fine-tuning the algorithm.
Testing: Thoroughly test the sorting algorithm with various input sizes and edge cases to ensure correctness and efficiency.
## Code Quality and Documentation:
Adhere to the coding standards and guidelines provided by 42, including proper documentation, variable naming conventions, and code organization.
Ensure clarity, readability, and maintainability of the codebase.
Consider peer review as part of the evaluation process.
