#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"


void addvehicle(struct vregister *vregister)
{
    char typeIn[MAXINPUT], brandIn[MAXINPUT], regNumberIn[MAXINPUT], ownerIn[MAXINPUT], nameIn[MAXINPUT], temp[MAXINPUT];
    int ageIn, index = 0;

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

    //Find empty spot
    for (index = 0; index < MAXVEHICLES; index++)
    {
        if(vregister->VehicleArray[index].brand[0] == '\0')
        {
            break;
        }
    }

    if(index == MAXVEHICLES)
    {
        printf("You can not store more than 10 vehicles!\n");
        return;
    }
    

    //Filling the vregister structure with the data from the user.
    strcpy(vregister->VehicleArray[index].type, typeIn);
    strcpy(vregister->VehicleArray[index].brand, brandIn);
    strcpy(vregister->VehicleArray[index].regNumber, regNumberIn);
    strcpy(vregister->VehicleArray[index].owner.name, ownerIn);
    vregister->VehicleArray[index].owner.age = ageIn;

    return;
}

void removevehicle(struct vregister *vregister){
    int input, index;
    char temp[MAXINPUT];

    index = findIndex(vregister);

    if(index == 0){
        printf("You can not remove a vehicle from an empty list");
        return;
    }

    printf("What Vehicle would you like to remove? You can choose between 0 - %d", index - 1);
    fgets(temp, MAXINPUT, stdin);
    input = atoi(temp);

    if(input < 0 || input > (index -1))
    {
        printf("That is not a valid input!");
        return;
    }

    strcpy(vregister->VehicleArray[input].type, "\0");
    strcpy(vregister->VehicleArray[input].brand, "\0");
    strcpy(vregister->VehicleArray[input].regNumber, "\0");
    strcpy(vregister->VehicleArray[input].owner.name, "\0");
    vregister->VehicleArray[input].owner.age = 0;

    return;
}

int findIndex(struct vregister *vregister){
    for (int index = 0; index < MAXVEHICLES; index++)
    {
        if(vregister->VehicleArray[index].brand[0] == '\0')
        {
            return index;
        }
    }

    return MAXVEHICLES;
}
