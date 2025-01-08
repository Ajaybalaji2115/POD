/*Problem Statement



In a multinational company named "GlobalTech," the finance department conducts a detailed analysis of expenses for specific departments. The finance team is particularly interested in finding the total money spent in the "Accounting" department to ensure accurate financial reporting.



The following table has already been created, and the records are inserted into the table.

Table name: Employee





Using the SUM aggregate function, write a query to calculate the total money spent in the "Account" department based on purchase records.



Note:

Table names are case sensitive.

Alias name: TotalAmount

Input format :
The input table is already created, and records are already prepopulated, as mentioned in the problem statement.

Alias Name: TotalAmount

Output format :
The output displays the total amount spent for Account department as shown below.



Department TotalAmount

Account 95000



Refer to the sample output for the column headers.

Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
# You are using MYSQL*/
select DEPARTMENT as Department,sum(SALARY) AS TotalAmount
from    Employee where DEPARTMENT="Account";
