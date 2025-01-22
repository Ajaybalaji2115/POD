/*Single File Programming Question
Problem Statement



Prakash is implementing a program to manage k distinct queues within a single array for a college library system. The program should support efficient enqueue and dequeue operations for each queue, ensuring no overlap and optimal use of array space.



Assist Prakash in completing the program.

Input format :
The first line consists of two integers, k and n, representing the number of queues and the total size of the array respectively.

Then, the input consists of inputs for enqueue and dequeue operations.

For each operation:

If 'operation' is 1 (enqueue), it takes two more integers representing the item and queue number to enqueue the item into the specified queue each separated by a space.
If 'operation' is 2 (dequeue), it takes one more integer representing the queue number to dequeue an element from the specified queue each separated by space.
If 'operation' is 0 (exit), the program exits which is a mandatory input to end the program.

Output format :
The output prints the following corresponding to the specified operations:

Enqueue Operation:

If the specified queue is full, the output prints: "Queue X overflow" where X is the queue number.
If the enqueue operation is successful: nothing will be printed.
Dequeue Operation:

If the specified queue is empty, the output prints: "Queue X underflow" where X is the queue number.
If the dequeue operation is successful, the output prints: "Dequeued element from queue X is Y," where X is the queue number and Y is the dequeued item.
Exit Operation: Nothing will be printed in the console.



Refer to the sample inputs and outputs for a better understanding.

Code constraints :
The given test cases fall under the formatting specifications:

0 ≤ k ≤ 100

0 ≤ n ≤ 10000

0 ≤ queue number < k (queue number starts from 0)

Sample test cases :
Input 1 :
3 10
1 10 0
1 20 0
1 30 1
1 40 1
1 50 2
1 60 2
2 0
2 1
2 2
0
Output 1 :
Dequeued element from queue 0 is 10
Dequeued element from queue 1 is 30
Dequeued element from queue 2 is 50
Input 2 :
2 10
1 10 0
1 20 1
1 30 1
2 0 
2 0
2 1 
0
Output 2 :
Dequeued element from queue 0 is 10
Queue 0 underflow
Dequeued element from queue 1 is 20
Input 3 :
2 5
1 10 0
1 20 0
1 30 0
1 40 0
1 50 1
1 60 1
2 0
2 1
0
Output 3 :
Queue 1 overflow
Dequeued element from queue 0 is 10
Dequeued element from queue 1 is 50
Input 4 :
2 2
1 10 0
1 20 1
1 50 0
1 30 1
2 0
2 1
0
Output 4 :
Queue 0 overflow
Queue 1 overflow
Dequeued element from queue 0 is 10
Dequeued element from queue 1 is 20
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
*/// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n;
    cin>>k>>n;
    int m;
    int count=0;
    vector<queue<int>>q(n);
    while(cin>>m)
    {
        if(m==1)
        {
            int a,b;
            cin>>a>>b;
            count++;
            if(count>n)
            {
                cout<<"Queue "<<b<<" overflow"<<endl;
            }
            else
            q[b].push(a);
        }
        else if(m==2)
        {
            int c;
            cin>>c;
            if(q[c].empty())
            cout<<"Queue "<<c<<" underflow"<<endl;
            else
            {
            cout<<"Dequeued element from queue "<<c<<" is "<<q[c].front()<<endl;
            q[c].pop();
            }
        }
        else
        {
            break;
        }
        
    }
}
