#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"



int main()
{
    int chosenNumber = 1;
    char temp[MAXINPUT];
    bool acceptableNumber;

    //Creating the array we are going to store our vehicles in
    struct vregister *vregister;
    vregister = malloc(MAXVEHICLES * sizeof(struct Vehicle));

    //Removing junk data from the brand member, we do this to find empty spots when adding vehicles.
    for (int i = 0; i < MAXVEHICLES; i++)
    {
        strcpy(vregister->VehicleArray[i].brand, "\0");
    }
     
    FILE* vregisterFile = fopen("vregisterFile.txt", "a+");
    fread(vregister->VehicleArray, sizeof(struct Vehicle), MAXVEHICLES, vregisterFile);
    fclose(vregisterFile);

    printMenu();

        while (chosenNumber != 0)
        {
            acceptableNumber = true;
                
            fgets(temp, MAXINPUT, stdin);

            if(temp[strlen(temp) - 1] != '\n') 
            {
                clearStdin();
                printf("Error! Input is too long!\n");
                chosenNumber = GOTODEFAULT;
                acceptableNumber = false;
            }else
            {
                for (int i = 0; temp[i] != '\n'; i++)
                {
                    if(isdigit(temp[i]) == 0)
                    {
                        printf("Your input contains something more than numbers!\n");
                        chosenNumber = GOTODEFAULT;
                        acceptableNumber = false;
                    }
                }
            }
            
            if(acceptableNumber == true)
            {
                chosenNumber = atoi(temp);
            }
            

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
                vregisterFile = fopen("vregisterFile.txt", "w+");
                fwrite(vregister->VehicleArray, sizeof(struct Vehicle), MAXVEHICLES, vregisterFile);
                free(vregister);
                printf("ss");
                return 0;
                
            default:
                printf("Please choose a number between 0-5\n");
                break;
            }

            printMenu();
    }
    

    return 0;
}

