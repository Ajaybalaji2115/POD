/*Single File Programming Question
Problem Statement



Ashok and Ragu are students studying in a school. Ashok is interested in calculating the geometric mean of a list of students' marks. Ragu has decided to help Ashok by creating a program using ArrayList.



Write a program that takes input for the number of students, then takes their mark points as input, calculates the geometric mean, and finally prints the result.



Example



Input:

5 

1.0 2.0 3.0 4.0 5.0

Output: 

Geometric mean of the list: 2.61

Explanation:

The geometric mean is calculated as the nth root of the product of all numbers.

Geometric Mean = (1.0 * 2.0 * 3.0 * 4.0 * 5.0)^(1/5) ≈ 2.61.



Note: Use Math.pow() to calculate the power value.

Input format :
The first line of input consists of an integer N, representing the number of students.

The second line consists of N double values, representing the mark points of each student, separated by a space.

Output format :
The output displays a "Geometric mean of the list: " followed by a double value, representing the geometric mean of the list of marks, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

1 ≤ N ≤ 10

0.0 ≤ marks ≤ 100.0

Sample test cases :
Input 1 :
5 
1.0 2.0 3.0 4.0 5.0
Output 1 :
Geometric mean of the list: 2.61
Input 2 :
3 
4.5 6.7 8.9
Output 2 :
Geometric mean of the list: 6.45
Input 3 :
2
11.2 32.4
Output 3 :
Geometric mean of the list: 19.05
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
// You are using Java
import java.util.*;
class GeometricMeanCalculator
{
    public static void main(String args[])
    {
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        ArrayList<Double>marks=new ArrayList<>();
        double product=1.0;
        for(int i=0;i<n;i++)
        {
            double mark=scanner.nextDouble();
            marks.add(mark);
            product *=mark;
        }
        double geometricMean=Math.pow(product,1.0/n);
        System.out.printf("Geometric mean of the list: %.2f",geometricMean);
        scanner.close();
    }
}
