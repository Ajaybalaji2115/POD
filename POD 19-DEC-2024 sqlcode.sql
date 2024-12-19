# You are using MYSQL
create table products
(
product_id INT ,
product_name varchar(100),
price decimal(10,2),
quantity_in_stock int,
PRIMARY KEY(product_id)
);
create table Orders(
order_id INT,
customer_name varchar(100),
order_date Date,
total_order_amount Decimal (10,2),
PRIMARY KEY(order_id)
);
create table Order_Details(
order_id INT,
product_id INT,
quantity_ordered INT,
price_per_unit Decimal(10,2),
PRIMARY KEY (order_id,product_id),
FOREIGN KEY(order_id)REFERENCES Orders(order_id),
FOREIGN KEY(product_id) REFERENCES Products(product_id)
);
select p.product_id,p.product_name,p.price,p.quantity_in_stock,o.order_id,
o.customer_name,o.order_date,o.total_order_amount,orr.quantity_ordered,orr.price_per_unit
 from products p join order_details orr
 on p.product_id=orr.product_id join orders o on orr.order_id=o.order_id;
/*
Problem Statement



Create a query to manage tables for a retail store. The database should have the following tables:



Products: Contains information about each product sold by the store, including the product ID, product name, price, and quantity in stock.

Orders: Contains information about each order placed by a customer, including the order ID, customer name, order date, and total order amount.

Order Details: Contains information about the products ordered in each order, including the order ID, product ID, quantity ordered, and price per unit.



The structure of the tables is shown below:





Input format :
There is no console input.

Output format :
The output should display the description of the tables as shown below.



Field	Type	Null	Key	Default	Extra
product_id	int	YES		NULL	
product_name	varchar(100)	YES		NULL	
price	decimal(10,2)	YES		NULL	
quantity_in_stock	int	YES		NULL	
Field	Type	Null	Key	Default	Extra
order_id	int	YES		NULL	
customer_name	varchar(100)	YES		NULL	
order_date	date	YES		NULL	
total_order_amount	decimal(10,2)	YES		NULL	
Field	Type	Null	Key	Default	Extra
order_id	int	YES		NULL	
product_id	int	YES		NULL	
quantity_ordered	int	YES		NULL	
price_per_unit	decimal(10,2)	YES		NULL
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0*/
