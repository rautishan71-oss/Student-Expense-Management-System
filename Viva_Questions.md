# Student Expense Management System — Viva Preparation

## 50 Short Viva Questions and Answers

1. **What is C++?**  
   C++ is a general-purpose programming language that supports procedural and object-oriented programming.

2. **What is a variable?**  
   A variable is a named memory location used to store a value.

3. **What is a data type?**  
   It specifies the kind of value a variable can store, such as `int`, `double` or `char`.

4. **Why is `double` used for money here?**  
   It can store decimal values. For production financial software, integer paise or a decimal type is safer against floating-point rounding.

5. **What is an operator?**  
   A symbol that performs an operation, such as `+`, `-`, `*` or `/`.

6. **What is an if statement?**  
   It executes a block when a condition is true.

7. **What is a switch statement?**  
   It selects one branch from multiple cases based on an expression.

8. **What is a loop?**  
   A control structure that repeats a block of code.

9. **Which loop keeps this application running?**  
   A `while` loop controlled by the `running` Boolean variable.

10. **What is a function?**  
    A reusable block of code that performs a particular task.

11. **What is a function parameter?**  
    A value supplied to a function when it is called.

12. **What is function overloading?**  
    Defining multiple functions with the same name but different parameter lists.

13. **What is an array?**  
    A fixed-size collection of elements of the same type.

14. **What is a string?**  
    An object used to store and manipulate text.

15. **What is a structure?**  
    A user-defined type that groups related data members; its members are public by default.

16. **What is a class?**  
    A user-defined blueprint containing data members and member functions.

17. **What is an object?**  
    An instance of a class.

18. **What is encapsulation?**  
    Combining data and functions in a class and controlling access to the data.

19. **Why are data members private?**  
    To prevent direct uncontrolled modification from outside the class.

20. **What is a constructor?**  
    A special member function called automatically when an object is created.

21. **What is a default constructor?**  
    A constructor that can be called without arguments.

22. **What is a parameterized constructor?**  
    A constructor that receives values to initialise an object.

23. **What is a destructor?**  
    A special member function called when an object is destroyed.

24. **What is inheritance?**  
    A mechanism by which a class can derive members from another class.

25. **Why is inheritance not forced into this project?**  
    The main entities are independent records; inheritance would add complexity without a clear benefit.

26. **What is polymorphism?**  
    The ability to use a common interface for different forms of behaviour.

27. **What is a pointer?**  
    A variable that stores the memory address of another variable or object.

28. **What is a reference?**  
    An alias for an existing variable.

29. **What is STL?**  
    The Standard Template Library provides reusable containers and algorithms.

30. **Why is `vector` used?**  
    It stores a dynamic number of records and can grow as records are added.

31. **What is file handling?**  
    Reading data from and writing data to files.

32. **What is `ofstream`?**  
    An output file stream used to write to files.

33. **What is `ifstream`?**  
    An input file stream used to read from files.

34. **What is `fstream`?**  
    A file stream class that supports both input and output operations.

35. **What does `ios::app` do?**  
    It opens a file in append mode so new data is added at the end.

36. **What does `getline()` do?**  
    It reads a complete line, including spaces, until the delimiter or newline.

37. **Why are records separated with `|`?**  
    It is a simple delimiter that separates fields in each text-file record.

38. **What is exception handling?**  
    Handling runtime errors using constructs such as `try`, `catch` and `throw`.

39. **Why is `try-catch` used when loading numbers?**  
    It prevents malformed numeric text from terminating the loading process.

40. **What is input validation?**  
    Checking user input before accepting or processing it.

41. **What is the objective of this project?**  
    To help students record income and expenses and monitor their budget.

42. **Which files store the application data?**  
    `students.txt`, `income.txt`, `expenses.txt` and `budget.txt`.

43. **How is the current balance calculated?**  
    Total income minus total expenses.

44. **How is remaining budget calculated?**  
    Monthly budget minus expenses recorded for that budget month.

45. **How does the program identify an expense?**  
    Each expense receives a numeric ID.

46. **How does update work?**  
    The program finds the ID in a vector, changes the object and rewrites the file.

47. **How does delete work?**  
    It removes the matching vector element and rewrites the file.

48. **Does the program retain data after exit?**  
    Yes. Records are saved in text files.

49. **What is one limitation?**  
    The program is a local single-user console application without encryption or authentication.

50. **What would you improve next?**  
    Add a database, secure login, graphical interface and visual reports.

## 20 Practical Viva Questions

1. Compile the project using the provided GCC command.
2. Add a student profile and show the saved information.
3. Add an income record with a source and amount.
4. Add an expense in the Food category.
5. Display all income records.
6. Display all expense records.
7. Update an expense using its ID.
8. Delete an expense using its ID.
9. Set a monthly budget.
10. Demonstrate the budget-exceeded warning.
11. Search using a category name.
12. Search using a description.
13. Enter an invalid amount and show validation.
14. Enter an invalid date format and show validation.
15. Exit and restart to demonstrate file persistence.
16. Open `expenses.txt` and explain its fields.
17. Explain why `ios::app` is used for new transactions.
18. Explain how the next ID is generated.
19. Demonstrate the monthly summary.
20. Explain what happens if a requested ID does not exist.

## 10 Architecture Questions

1. **Why is the application divided into classes?** To keep related data and operations together.
2. **What is the role of `main.cpp`?** It displays the menu and coordinates operations.
3. **What is the role of `FileManager`?** It centralises file input and output.
4. **Why are model classes separate from file operations?** This separates data representation from persistence.
5. **Why are vectors used?** The number of transactions changes at runtime.
6. **Why are IDs used?** They uniquely identify records for update and delete operations.
7. **Why are there separate files?** Each file stores one type of information.
8. **How is monthly data selected?** The first seven characters of a transaction date are compared with `YYYY-MM`.
9. **What is the application flow?** Load data, show menu, perform an operation, return to menu, exit.
10. **How could it support multiple users?** Add authentication and associate every transaction with a user ID.

## 10 Source-Code Questions

1. **Why use `const` in getter functions?** It promises not to modify the object.
2. **Why pass strings by `const string&`?** It avoids an unnecessary copy and prevents modification.
3. **What does `static_cast<unsigned char>` help with in `tolower`?** It avoids undefined behaviour for negative signed-char values.
4. **What does `find_if` do?** It searches a range for the first element satisfying a condition.
5. **What does `erase` do?** It removes an element from a vector.
6. **What does `stringstream` do?** It allows a string to be processed like a stream.
7. **Why check whether a file opened?** File operations can fail due to missing permissions or paths.
8. **What does `fixed << setprecision(2)` do?** It displays floating-point values with two digits after the decimal point.
9. **Why use `stoi` and `stod`?** They convert strings to integer and double values.
10. **Why is `ios::app` used?** To preserve previous records when adding a new record.

## 10 Project Demonstration Questions

1. What problem does your project solve?
2. Who is the intended user?
3. What are the main modules?
4. How do you add an expense?
5. How do you update and delete an expense?
6. How do you calculate the balance?
7. How do you know if the budget is exceeded?
8. Where is the data stored?
9. What happens after restarting the application?
10. What are the current limitations and future improvements?

## Suggested 3–5 Minute Demonstration

1. Start the program and show the main menu.
2. Add or display student details.
3. Add one income record.
4. Add two expenses in different categories.
5. Display income and expense history.
6. Set a monthly budget lower than the expenses and show the warning.
7. Open the financial summary and monthly summary.
8. Search for a category or description.
9. Update one expense, then delete another.
10. Exit, restart and show that records remain saved.
