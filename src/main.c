#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"



int main()
{
    int chosenNumber;
    char temp[MAXINPUT];

    printMenu();

    fgets(temp, MAXINPUT, stdin);
    chosenNumber = atoi(temp);


    switch (chosenNumber)
    {
    case 1:
        addvehicle();
        break;
    case 2:
         removevehicle();
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        printAllvehicles();
        break;
    case 0:
        return 0;
        
    default:
        printf("That is not an option");
        break;
    }

    return 0;
}