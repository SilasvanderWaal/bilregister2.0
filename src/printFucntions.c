#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

void printMenu()
{
    printf("1. Lägg till ett fordon\n");
    printf("2. Ta bort ett fordon\n");
    printf("3. Sortering efter bilmarke\n");
    printf("4. Skriv ut information om ett fordon\n");
    printf("5. Skriv ut hela fordonsregistret\n");
    printf("0. Avsluta programmet\n");
}

void printvehicle()
{

}

void printAllvehicles()
{
    FILE* vregister;
    struct Vehicle read_car;

    //Opening our safefile
    vregister = fopen("vregister.txt", "ab+");

    //Set the pointer to the beginning of the file
    rewind(vregister);

    fread(&read_car, sizeof(struct Vehicle), 1, vregister);

    printf("%s %s %s %s %d\n", read_car.brand,  read_car.type, read_car.owner.name, read_car.regNumber, read_car.owner.age);
}