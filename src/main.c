#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"



int main()
{
    int chosenNumber = 1;
    char temp[MAXINPUT];

    //Creating the array we are going to store our vehicles in
    struct vregister *vregister;
    vregister = malloc(MAXVEHICLES * sizeof(struct Vehicle));

    //Removing junk data from the brand member, we do this to find empty spots when adding vehicles.
    for (int i = 0; i < MAXVEHICLES; i++)
    {
        strcpy(vregister->VehicleArray[i].brand, "\0");
    }
    

    printMenu();

    while (chosenNumber != 0)
    {
        fgets(temp, MAXINPUT, stdin);
        chosenNumber = atoi(temp);

        switch (chosenNumber)
        {
        case 1:
            addvehicle(vregister);
            break;
        case 2:
            removevehicle(vregister);
            break;
        case 3:
            sortVehicles(vregister);
            break;
        case 4:
            printvehicle(vregister);
            break;
        case 5:
            printAllvehicles(vregister);
            break;
        case 0:
            free(vregister);
            return 0;
            
        default:
            printf("That is not an option");
            break;
        }

        printMenu();
    }
    

    return 0;
}