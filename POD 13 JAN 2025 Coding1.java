/*Single File Programming Question
Problem Statement



Yashna is creating a program to analyze a 2D grid, identifying prime numbers and printing their coordinates. The input consists of the grid's dimensions and elements. The program's output displays the coordinates of each prime number found in the grid, aiding in the exploration of numerical patterns.



Can you assist Yashna in creating the program?

Input format :
The first line of input consists of two space-separated integers N and M, representing the number of rows and columns respectively.

The following N lines consist of M space-separated integers, representing the grid elements.

Output format :
The output prints the prime numbers present in the 2D array in each line in the format "Element at (i, j) is a prime number." where (i, j) represents the row and column indices of that element.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N, M ≤ 10

1 ≤ elements ≤ 100

Sample test cases :
Input 1 :
3 2
1 2 
4 5 
7 8 
Output 1 :
Element at (0, 1) is a prime number.
Element at (1, 1) is a prime number.
Element at (2, 0) is a prime number.
Input 2 :
2 2
1 2 
7 11 
Output 2 :
Element at (0, 1) is a prime number.
Element at (1, 0) is a prime number.
Element at (1, 1) is a prime number.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Fill your code here
Java (11)
theme
instruction

*/
// You are using Java
import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner t=new Scanner(System.in);
        int m=t.nextInt();
        int n=t.nextInt();
        int arr[][]=new int[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=t.nextInt();
                int count=0;
                for(int z=1;z<=arr[i][j];z++)
                {
                    if(arr[i][j]%z==0)
                    count++;
                }
                if(count==2)
                {
                    System.out.println("Element at ("+i+", "+j+") is a prime number.");
                }
            }
        }
    }
}
