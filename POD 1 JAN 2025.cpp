/*ot dogs



Raju has an l-length hot dog that he wants to chop in an efficient manner so that he can share it with as many friends as possible. Based on the chopped length product the maximum served friends are calculated.



Example



Input:

4



Output:

Maximum friends served = 4



Explanation:

1, 3      (1 × 3) = 3

2, 2      (2 × 2) = 4

3, 1      (3 × 1) = 3

1, 1, 2     (1 × 1 × 2) = 2

1, 2, 1     (1 × 2 × 1) = 2

2, 1, 1     (2 × 1 × 1) = 2

1, 1, 1, 1   (1 × 1 × 1 × 1) = 1

Input format :
The input corresponds to the length of the hot dog (l).

Output format :
The output prints the maximum number of friends served as an output.

Sample test cases :
Input 1 :
4
Output 1 :
Maximum friends served 4
Input 2 :
5
Output 2 :
Maximum friends served 6
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Fill your code here
C++ (17)
theme
instruction*/



/*Single File Programming Question
Alice's Experiment



Alice is doing an experiment on forces acting in a straight line with equal strength. There is n number of objects set up in a straight line, and he initially placed the objects at rest. In the beginning, he simultaneously pushes some of the objects with constant force either to the left or to the right.



After each second, each object that is moving to the left pushes the adjacent object on the left. Similarly, the objects falling to the right push their adjacent objects standing to the right. When an object has objects falling on it from both sides, it stays in the same position because the same strength of force is applied on both sides.



You are given a string representing the initial state of those objects:

If the string[i] = ‘L’, it means that a particular object is moving on the left side.

If the string[i] = ‘R’, it means that a particular object is moving on the right side.

If the string[i] = ‘.’, it means there is no force acting on the object, and it's at rest.

Print a string that represents the final state of the objects after all the forces have been applied to them.



Note: Consider that a moving object doesn't add any additional force to an adjacent or already moving object.



Example:

Input:

.LR.

Output:

LLRR

Explanation:

The second object will push the first object to the left. Similarly, the third object will push the fourth object to the right side.

Input format :
The input consists of a string representing the initial state.

Output format :
The output prints a string representing the final state.

Refer to the sample input and output.

Code constraints :
1 < String length < 100001

Sample test cases :
Input 1 :
.LR.
Output 1 :
LLRR
Input 2 :
.L.R.L
Output 2 :
LL.R.L
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/

