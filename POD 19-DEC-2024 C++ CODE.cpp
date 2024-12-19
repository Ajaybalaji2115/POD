#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<pair<int, int>> q;  // Queue to store the parking spot and car number
    int z = 0;  // Keeps track of the number of parked cars
    const int MAX_SPOTS = 10;  // Maximum number of parking spots
    
    while(true) {
        int num;
        cin >> num;  // Read the user choice
        
        if(num == 1) {  // Park a car
            int carNumber;
            cin >> carNumber;
            if(z >= MAX_SPOTS) {  // Check if parking lot is full
                cout << "Parking lot is full." << endl;
            } else {
                cout << "Car " << carNumber << " parked in spot " << z << "." << endl;
                q.push({z, carNumber});  // Push the car into the queue
                z++;
            }
        } 
        else if(num == 2) {  // Retrieve a car
            if(q.empty()) {  // Check if parking lot is empty
                cout << "Parking lot is empty." << endl;
            } else {
                cout << "Car " << q.front().second << " retrieved from spot " << q.front().first << "." << endl;
                q.pop();  // Remove the car from the parking lot
                z--;
            }
        } 
        else if(num == 3) {  // Exit
            break;
        } 
        else {  // Invalid choice
            cout << "Invalid choice." << endl;
        }
    }
}
/*
A company is designing an automated parking system for a multi-level parking garage. The system should be able to park cars in an available spot and also retrieve cars from the garage. The parking garage has a limited number of spots, so the system should be able to keep track of which spots are available and which ones are occupied. The company wants to implement this using a circular queue.



We can implement this using a circular queue data structure where each node in the queue represents a parking spot. Initially, all the spots will be empty, and as cars are parked, the nodes in the queue will be updated to indicate that the spot is occupied. When a car leaves, the node will be updated to indicate that the spot is empty.



Implement a menu-driven program. The menu options are:

Park a car
Retrieve a car.
Exit
default: invalid choice
Input format :
The input consists of a series of commands to either park or retrieve cars from a parking lot.



Each command is represented by an integer indicating the action to be performed:

1: Park a car. For parking a car (1), an additional integer representing the car number is provided.

2: Retrieve a car

3: Exit the program

Output format :
The output consists of messages indicating the status of the parking lot after each command.



For parking a car (1), the output message is in the format: Car [carNumber] parked in spot [spot].

For retrieving a car (2), the output message is in the format: Car [carNumber] retrieved from spot [spot].

If the parking lot is full when attempting to park a car, the message is: Parking lot is full.

If the parking lot is empty when attempting to retrieve a car, the message is: Parking lot is empty.

For an invalid choice, the message is: "Invalid choice."



Refer to the sample output for the formatting specifications.

Code constraints :
The maximum number of empty spots is set to 10.

Sample test cases :
Input 1 :
1
123
1
456
2
3
Output 1 :
Car 123 parked in spot 0.
Car 456 parked in spot 1.
Car 123 retrieved from spot 0.
Input 2 :
2
3
Output 2 :
Parking lot is empty.
Input 3 :
1
153
1
156
5
3
Output 3 :
Car 153 parked in spot 0.
Car 156 parked in spot 1.
Invalid choice.
Input 4 :
1
131
1
132
1
133
1
134
1
135
1
136
1
137
1
138
1
139
1
140
1
3
Output 4 :
Car 131 parked in spot 0.
Car 132 parked in spot 1.
Car 133 parked in spot 2.
Car 134 parked in spot 3.
Car 135 parked in spot 4.
Car 136 parked in spot 5.
Car 137 parked in spot 6.
Car 138 parked in spot 7.
Car 139 parked in spot 8.
Car 140 parked in spot 9.
Parking lot is full.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
