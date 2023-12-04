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

    long int size;

    struct Vehicle VehicleArray[MAXVEHICLES];

    vregister = fopen("vregister.txt", "r+");


   fread(VehicleArray, sizeof(struct Vehicle), MAXVEHICLES, vregister);

    fseek( vregister, 0, SEEK_END);
    size = ftell(vregister);


   for (int i; i < size; i += sizeof(struct Vehicle))
   {
        printf("%s %s %s %s %d\n", VehicleArray[i / sizeof(struct Vehicle)].brand,  VehicleArray[i / sizeof(struct Vehicle)].type, VehicleArray[i / sizeof(struct Vehicle)].owner.name, VehicleArray[i / sizeof(struct Vehicle)].regNumber, VehicleArray[i / sizeof(struct Vehicle)].owner.age);
   }
   
    fclose(vregister);
}