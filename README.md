Pointer Usage:
Pointers are used in a few places in this program. First is the names array which holds pointers to strings for each name of the students. We 

Const Usage:
Consts' are used in this program when passing vairables to functions that we dont want alterted. For example when calutation average gpa we want to acces the gpa value 
but not change them

Refrence Usage:
In addStudent we pass the size variable by refrence so that when modifying it we can perserve the updated size value without having to return it. 

Casting:
We cast our average gpa from a double to an int using static_cast<int>

Exceptions:
We use try catch blocks rapped around every function call and user input area. This could also be wrapped around our whole loop but in both cases it catches error being thrown
from the functions like having no students recorded and trying to calulate an average gpa. We throw strings in this program to be printed when an error occurs

Control Flow:
Our program mainly runs inside a do while loop which repeatdly takes a user input in the form of an integer and the then uses a switch statment to decide what to do with the 
users input and sometimes request more user inputs. It also allows for a user input to end the program. We control all values and coorliate gpas to names using parrelell 
arrays and a size integer.
