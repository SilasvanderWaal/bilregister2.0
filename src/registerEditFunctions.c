#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"


void addvehicle(struct vregister *vregister)
{
    char typeIn[MAXINPUT];
    char brandIn[MAXINPUT];
    char regNumberIn[MAXINPUT];
    char ownerIn[MAXINPUT];
    char nameIn[MAXINPUT];
    char temp[MAXINPUT];
    int ageIn, index = 0;

    //Getting the input from the user and makes sure it is valid, if not the user will be send back to the main menu.
    printf("What type of car would you like to register?\n");
    fgets(typeIn, MAXINPUT, stdin);
    if(typeIn[strlen(typeIn) - 1] != '\n')
    {
        clearStdin();
        printf("Error! Input is too long!\n");
        return;
    }

    printf("What is the brand of the car?\n");
    fgets(brandIn, MAXINPUT, stdin);
    if(brandIn[strlen(brandIn) - 1] != '\n')
    {
        clearStdin();
        printf("Error! Input is too long!\n");
        return;
    }

    printf("What is the registration number of the car?\n");
    fgets(regNumberIn, MAXINPUT, stdin);
    if(regNumberIn[strlen(regNumberIn) - 1] != '\n')
    {
        clearStdin();
        printf("Error! Input is too long!\n");
        return;
    }

    printf("What is the name of the owner?\n");
    fgets(ownerIn, MAXINPUT, stdin);
    if(ownerIn[strlen(ownerIn) - 1] != '\n')
    {
        clearStdin();
        printf("Error! Input is too long!");
        return;
    }

    printf("How old is the owner?\n");
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
    
    ageIn = atoi(temp);

    //Find the first empty spot in the array
    for (index = 0; index < MAXVEHICLES; index++)
    {
        if(vregister->VehicleArray[index].brand[0] == '\0')
        {
            break;
        }
    }

    //Makes sure the array is not full, if full the user is send back to the main menu
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

    //Finding the next empty spot
    index = findIndex(vregister);

    //Making sure the register is not empty
    if(index == 0){
        printf("You can not remove a vehicle from an empty list\n");
        return;
    }

    //Letting the user choose which vehicle they would like to remove
    printf("What Vehicle would you like to remove? You can choose between 1 - %d\n", index);
    fgets(temp, MAXINPUT, stdin);
    if(temp[strlen(temp) - 1] != '\n') 
    {
        clearStdin();
        printf("Error! Input is too long!\n");
        return;
    }

    //Making sure there input is valid
    for (int i = 0; temp[i] != '\n'; i++)
    {
        if(isdigit(temp[i]) == 0)
        {
            printf("Your input contains something more than numbers!\n");
            return;
        }
    }

    input = atoi(temp);

    if(input < 1 || input > index)
    {
        printf("That is not a valid input!\n");
        return;
    }

    //cleaning the vehicle that the user wants to remove
    strcpy(vregister->VehicleArray[input - 1].type, "\0");
    strcpy(vregister->VehicleArray[input - 1].brand, "\0");
    strcpy(vregister->VehicleArray[input - 1].regNumber, "\0");
    strcpy(vregister->VehicleArray[input - 1].owner.name, "\0");
    vregister->VehicleArray[input -1].owner.age = 0;

    //Moving every vehicle that comes after the removed vehicle, one step back
    for (int i = input -1 ;  i < index; i++)
    {
        vregister->VehicleArray[i] = vregister->VehicleArray[i + 1];

        //removing the last vehicles so the string becomes one shorter.
        if( i +1 ==  index)
        {
            strcpy(vregister->VehicleArray[i].type, "\0");
            strcpy(vregister->VehicleArray[i].brand, "\0");
            strcpy(vregister->VehicleArray[i].regNumber, "\0");
            strcpy(vregister->VehicleArray[i].owner.name, "\0");
            vregister->VehicleArray[i].owner.age = 0;
        }
    }
    
    return;
}

//Function that gives us the first empty spot in the vehicleArray
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

//Function that clears stdin
void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
