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
        printf("There is no vehicle in the register yet, add a vehicle to use this function!");
    }

    printf("What vehicle would you like to see? You can choose from 0 - %d\n", index - 1);

    fgets(temp, MAXINPUT, stdin);
    input = atoi(temp);

    if(input < 0 || input > index - 1){
        printf("That is not a valid input!");
        return;
    }

    printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",input ,  vregister->VehicleArray[input].brand,  vregister->VehicleArray[input].type, vregister->VehicleArray[input].regNumber, vregister->VehicleArray[input].owner.name, vregister->VehicleArray[input].owner.age);

    return;
}

void printAllvehicles(struct vregister *vregister)
{
    int index = findIndex(vregister);
    //Print all the vehicles data
    for (int i = 0; i < index; i++)
    {
        printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",i ,  vregister->VehicleArray[i].brand,  vregister->VehicleArray[i].type, vregister->VehicleArray[i].regNumber, vregister->VehicleArray[i].owner.name, vregister->VehicleArray[i].owner.age);
    }

    return;
}