/*Single File Programming Question
Problem Statement



You are given a positive integer num. Your task is to find a palindrome by performing the following operations:



Add num to its reverse.
Check whether the sum obtained in Step 1 is a palindrome or not. If it's a palindrome, stop and return it. If not, repeat the process by adding the sum to its reverse.


Write a program that takes an integer num as input and finds the palindrome following the above procedure.



Example



Input:

195



Output:

9339



Explanation



In this test case, the input number is 195. step by step to understand how the code calculates the final output.



reverse (195) = 591
sum = 195 + 591 = 786
reverse(786) = 687
Check if the reverse of the sum is equal to the palindrome; if not, continue to the next step.
sum = 786 + 687 = 1473
reverse (1473) = 3741
Check if the reverse of the sum is equal to the palindrome; if not, continue to the next step.
Repeat steps 5-7 until the reverse of the sum is equal to the palindrome.
Finally, the reverse of the sum remains the same: reverse (9339) = 9339


Since the reverse of the sum (9339) is equal to the sum itself, we have reached a palindrome. Therefore, the final output is 9339.

Input format :
The input consists of an integer n.

Output format :
The output consists of a palindromic value, which is the final palindrome obtained by repeatedly adding the number and its reverse.



Refer to the sample output for format specifications.

Code constraints :
1 ≤ n ≤ 105

Sample test cases :
Input 1 :
124
Output 1 :
545
Input 2 :
195
Output 2 :
9339
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
  // You are using Java
import java.util.*;
class Main
{
    public static  int reverse(int a)
    {
        int b=0;
        while(a!=0)
        {
            b=b*10+a%10;
            a=a/10;
        }
       return b;
    }
  
    public static void main(String args[])
    {
        Scanner t=new Scanner(System.in);
        int a=t.nextInt();
        int b=0;
        int count=0;
        while(true)
        {
            b=reverse(a);

            if(a==b)
            {
                break;
            }
      else
      {
          a+=b;
      }
      count++;
        }
        System.out.println(a);
    }
}
