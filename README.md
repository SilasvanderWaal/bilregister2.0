Vehicle Register Database
This project is a simple car register database that allows users to manage information about vehicles. The program provides a set of functionalities to interact with the vehicle register efficiently. Here are the key features:

Functions
Add a New Vehicle to the Register:

Users can add a new vehicle to the database by providing relevant information such as brand, model, and registration details.
Delete a Vehicle from the Register:

The program allows users to delete a vehicle from the register based on specified criteria, such as registration number or other identifiers.
Sort the Register Alphabetically:

Users can sort the vehicle register alphabetically, primarily using the brand as the sorting criterion. This facilitates easy retrieval and management of data.
Print a Range of Vehicles:

Users have the option to print out details of a specific vehicle by providing a range (e.g., 1-10) within the register. This function aids in quick access to information.
Print the Entire Vehicle Register:

This function prints out the complete vehicle register, providing a comprehensive view of all vehicles stored in the database.
Build Instructions
The project includes a Makefile with the following options:

Build:

To compile and build the program, execute the command: make build
Clean:

To remove compiled files and clean the project directory, use the command: make clean
Usage
To interact with the program, users can execute the compiled executable resulting from the build process. The executable provides a command-line interface where users can input commands corresponding to the defined functionalities.

Example Usage:
bash
Copy code
# Build the program
make build

# Run the program
./vehicle_register

# Use the program functionalities
1. Add a new vehicle
2. Delete a vehicle
3. Sort the register
4. Print a specific range of vehicles
5. Print the entire vehicle register

# Clean up (optional)
make clean
