#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

void printMenu()
{
    //Prints out the main menu
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

    //Using the next free spot to get the length of the array
    index = findIndex(vregister);

    //Making sure we have something to print out 
    if(index == 0){
        printf("There is no vehicle in the register yet, add a vehicle to use this function!\n");
    }

    //Asking the user which car the would like to see
    printf("What vehicle would you like to see? You can choose from 1 - %d\n", index);
    fgets(temp, MAXINPUT, stdin);

    //Making sure their input is valid
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

    //converting the string to a number so we can use it as an int
    input = atoi(temp);

    //Once again, making sure the input is still valid
    if(input < 0 || input > index ){
        printf("That is not a valid input!\n");
        return;
    }

    //printing out the car the user would like to see
    printf("---------------------------------------------------------------------------");
    printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",input ,  vregister->VehicleArray[input -1].brand,  vregister->VehicleArray[input -1].type, vregister->VehicleArray[input -1].regNumber, vregister->VehicleArray[input -1].owner.name, vregister->VehicleArray[input -1].owner.age);
    printf("---------------------------------------------------------------------------\n");
    
    return;
}

void printAllvehicles(struct vregister *vregister)
{
    //Using the next free spot to get the length of the array
    int index = findIndex(vregister);
   
    //Cheking so the string is not ampty
    if(index == 0)
    {
        printf("The register is empty, you will need to add a vehicle first!\n");
        return;
    }

    //Printing out the enitre register, one car at the time.
    printf("---------------------------------------------------------------------------");
    for (int i = 0; i < index; i++)
    {
        printf("\nCar %d\nMärke: %sTyp: %sRegistreringsnummer: %sÄgare: %sÄgarens ålder: %d\n",i + 1 ,  vregister->VehicleArray[i].brand,  vregister->VehicleArray[i].type, vregister->VehicleArray[i].regNumber, vregister->VehicleArray[i].owner.name, vregister->VehicleArray[i].owner.age);
    }
    printf("---------------------------------------------------------------------------\n");

    return;
}