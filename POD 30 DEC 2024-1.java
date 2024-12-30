/*Single File Programming Question
Problem Statement



Joseph is working on improving data centre efficiency. He manages a grid of servers as a 2D matrix, where each cell is either operational (non-zero integer) or non-operational (zero). When a server becomes non-operational (zero), it causes all servers in its row and column to also become non-operational. 



Joseph needs a program to automate this process.

Input format :
The first line of input contains two integers r and c, representing the number of rows and columns of the matrix, respectively.

The next r lines each contain c integers, representing the matrix elements.

Output format :
The output should be the modified matrix, printed row by row, where the necessary rows and columns have been set to non-operational (zero).



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ r, c ≤ 10

0 ≤ matrix elements ≤ 100

Sample test cases :
Input 1 :
3 3
1 1 1
1 0 1
1 1 1
Output 1 :
1 0 1 
0 0 0 
1 0 1 
Input 2 :
3 2
4 0
8 6
1 2
Output 2 :
0 0 
8 0 
1 0 
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.*/
import java.util.*;
class Main
{
    public static void main(String args[])
    {
        Scanner t=new Scanner(System.in);
        int m=t.nextInt();
        int n=t.nextInt();
        int arr[][]=new int [m][n];
        int p=0,q=0;
        Vector<Integer>v=new Vector<>();
        Vector<Integer>v1=new Vector<>();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=t.nextInt();
                if(arr[i][j]==0)
                {
                   v.add(i);
                   v1.add(j);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
if(v.contains(i) || v1.contains(j))
{
   System.out.print("0 ");
    
}
else
{
    System.out.print(arr[i][j]+" ");
}
            }
            System.out.println();
        }
      
    }
}
