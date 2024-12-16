/*Bob wants to develop a score-tracking application for a gaming tournament. Each player's score is stored in a HashMap with the player's name as the key and the score as the value. 



Write a program to assist Bob that takes user input to enter player scores, calculates the maximum score from the HashMap, and prints the player with the highest score.

Input format :
The input consists of strings representing player details in the format ''playerName:score''.

The input is terminated by entering "done".

Output format :
The output displays a string, representing the player's name who scored the maximum.

If the value is not numeric, print "Invalid input".

If any special characters other than ':' are given, print "Invalid format".



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ Length of the Player's Name ≤ 20

1 ≤ score ≤ 100

Sample test cases :
Input 1 :
Alice:15
Bob:56
done
Output 1 :
Bob
Input 2 :
Karan:21
Lathika:52
Sandhiya:30
done
Output 2 :
Lathika
Input 3 :
Sachin:Ten
Dhoni:10
done
Output 3 :
Invalid input
Input 4 :
Pandya-15
Gill-3
Krunal:10
done
Output 4 :
Invalid format
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
import java.util.HashMap;
import java.util.Scanner;

public class ScoreTracker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, Integer> scores = new HashMap<>();
        String input;

        while (true) {
            input = scanner.nextLine();
            
            if (input.equals("done")) {
                break;
            }

            // Check for the correct format
            if (!input.contains(":") || input.split(":").length != 2) {
                System.out.println("Invalid format");
                return;
            }

            String[] parts = input.split(":");
            String playerName = parts[0];
            String scoreStr = parts[1];

            // Validate player name length
            if (playerName.length() < 1 || playerName.length() > 20) {
                System.out.println("Invalid format");
                return;
            }

            // Validate score is numeric
            try {
                int score = Integer.parseInt(scoreStr);
                
                // Check score constraints
                if (score < 1 || score > 100) {
                    System.out.println("Invalid input");
                    return;
                }

                scores.put(playerName, score);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input");
                return;
            }
        }

        // Find the player with the highest score
        String topPlayer = null;
        int maxScore = -1;

        for (HashMap.Entry<String, Integer> entry : scores.entrySet()) {
            if (entry.getValue() > maxScore) {
                maxScore = entry.getValue();
                topPlayer = entry.getKey();
            }
        }

        // Output the result
        if (topPlayer != null) {
            System.out.println(topPlayer);
        }
    }
}
