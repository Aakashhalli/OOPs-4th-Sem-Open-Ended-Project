# Belagavi Car Rental System


1.1	Problem Statement
    The modern car rental industry faces challenges in efficiently managing car listings, handling rental transactions, and maintaining accurate records for both owners 
    and lessees. Manual processes often lead to inefficiencies, errors, and a poor user experience. There is a significant need for an automated system to streamline 
    these operations and enhance the overall efficiency and satisfaction of both car owners and renters.


1.2	Features of Application

    1. User Authentication:
       - Secure login and signup for both car owners and lessees.
       - Password-based authentication for user accounts.
    
    2. Owner Management:
       - Owners can list cars for rent with detailed information including name, make, year, and price per day.
       - Owners can view and manage their listed cars.
       - Option to remove cars from the listing.
       - Display message when no cars are listed or available for removal.
    
    3. Lessee Management:
       - Lessees can view available cars for rent.
       - Lessees can rent a car by specifying the number of days.
       - Lessees can return rented cars.
       - Option to view currently rented cars.
       - Display message when no cars are available for rent or rented yet.
    
    4. Car Management:
       - Each car has a unique ID, name, make, year, price per day, availability status, and owner information.
       - Track the availability and rental status of cars.
       - Display detailed information about each car.
    
    5. Transaction Management:
       - Calculate rental costs based on the number of days rented.
       - Handle payments from lessees to owners upon car return.
       - Generate receipts for completed transactions.
    
    6. File Management:
       - Store and retrieve user details (owners and lessees) from files.
       - Maintain separate files for owner and lessee credentials and details.
    
    7. User Interface:
       - Text-based menu-driven interface for owners and lessees.
       - Clear prompts and feedback messages for user actions.
       - Option to logout and return to the main menu.
    
    8. Error Handling:
       - Validate user inputs for car IDs and other fields.
       - Handle incorrect inputs and provide appropriate error messages.
    
    9. Static UID Generation:
       - Generate unique IDs for each car using a static function to ensure no duplication.


2.1	Class Diagram
<br>
![image](https://github.com/user-attachments/assets/991cba42-9054-4c9e-a8ce-de4d653d4ff2)

<pre>
2.2 Class Description 
    1. Person:
        A base class that holds common attributes for users, including name, email, username, age, and phone number. It provides methods to get and set these details, 
        and check if they are empty.
    2. Owner:
        Inherits from Person. Represents a car owner, with additional functionality to manage a list of cars they have listed for rent. It includes methods to add, remove,
        and retrieve listed cars.
    3. Lessee:
        Inherits from Person. Represents a lessee who rents cars. It includes additional attributes like a driving license and a list of rented car IDs. Methods are provided
        to manage these rented cars and the lessee's license.
    4. Car:
        Represents a car available for rent. It includes attributes such as name, make, year, price per day, availability status, and the username of the person renting it. 
        Methods include displaying car information, checking availability, and setting rental status.
    5. Payment:
        A utility class that handles payment transactions between lessees and owners. It includes static methods to make payments and generate receipts for completed 
        transactions.
</pre>
