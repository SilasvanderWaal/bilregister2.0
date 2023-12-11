#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

void printMenu()
{
    printf("\n");
    printf("1. Lägg till ett fordon\n");
    printf("2. Ta bort ett fordon\n");
    printf("3. Sortering efter bilmarke\n");
    printf("4. Skriv ut information om ett fordon\n");
    printf("5. Skriv ut hela fordonsregistret\n");
    printf("0. Avsluta programmet\n");
}

void printvehicle(struct vregister *vregister)
{
    int index;
    char temp[MAXINPUT];
    int input;

    index = findIndex(vregister);

    if(index == 0){
        printf("There is no vehicle in the register yet, add a vehicle to use this function!\n");
    }

    printf("What vehicle would you like to see? You can choose from 1 - %d\n", index);

    fgets(temp, MAXINPUT, stdin);
    if(temp[strlen(temp) - 1] != '\n') 
    {
        clearStdin();
        printf("Error! Input is too long!\n");
        return;
    }

    for (int i = 0; temp[i] != '\n'; i++)
    {
        if(isdigit(temp[i]) == 0)
        {
            printf("Your input contains something more than numbers!\n");
            return;
        }
    }

    input = atoi(temp);

    if(input < 0 || input > index ){
        printf("That is not a valid input!\n");
        return;
    }
    printf("---------------------------------------------------------------------------");
    printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",input ,  vregister->VehicleArray[input -1].brand,  vregister->VehicleArray[input -1].type, vregister->VehicleArray[input -1].regNumber, vregister->VehicleArray[input -1].owner.name, vregister->VehicleArray[input -1].owner.age);
    printf("---------------------------------------------------------------------------\n");
    return;
}

void printAllvehicles(struct vregister *vregister)
{
    int index = findIndex(vregister);
    //Print all the vehicles data

    if(index == 0)
    {
        printf("The register is empty, you will need to add a vehicle first!\n");
        return;
    }

    printf("---------------------------------------------------------------------------");
    for (int i = 0; i < index; i++)
    {
        printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",i + 1 ,  vregister->VehicleArray[i].brand,  vregister->VehicleArray[i].type, vregister->VehicleArray[i].regNumber, vregister->VehicleArray[i].owner.name, vregister->VehicleArray[i].owner.age);
    }
    printf("---------------------------------------------------------------------------\n");

    return;
}