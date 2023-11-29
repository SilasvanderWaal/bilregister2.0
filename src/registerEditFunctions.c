#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"


void addvehicle()
{
    char typeIn[MAXINPUT], brandIn[MAXINPUT], regNumberIn[MAXINPUT], ownerIn[MAXINPUT], nameIn[MAXINPUT], temp[MAXINPUT];
    int ageIn, index = 0;;
    
    //Getting the input from the user.
    printf("What type of car would you like to register?\n");
    fgets(typeIn, MAXINPUT, stdin);
    printf("What is the brand of the car?\n");
    fgets(brandIn, MAXINPUT, stdin);
    printf("What is the registration number of the car?\n");
    fgets(regNumberIn, MAXINPUT, stdin);
    printf("What is the name of the owner?\n");
    fgets(ownerIn, MAXINPUT, stdin);
    printf("How old is the owner?\n");
    fgets(temp, MAXINPUT, stdin);
    ageIn = atoi(temp);

    //Getting our structure.
    struct Vehicle *carArray;

    //Creating a array in the heap memory.
    carArray = malloc(MAXVEHICLES * sizeof(struct Vehicle));
    
    //Filling the [index] structure with the data from the user.
    strcpy(carArray[index].type, typeIn);
    strcpy(carArray[index].brand, brandIn);
    strcpy(carArray[index].regNumber, regNumberIn);
    strcpy(carArray[index].owner.name, ownerIn);
    carArray[index].owner.age = ageIn;

    //free(carArray)? Will remove our array, but not free the space will cause memory leaks.
}
