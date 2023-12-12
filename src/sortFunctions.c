#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

void sortVehicles(struct vregister *vregister)
{
    int index;
    struct Vehicle buff;

    //Using the next free spot to get the length of the array
    index = findIndex(vregister);

    //Making sure we have atleast 2 vehicles in the array, sorting with less is meaningless
    if (index < 2)
    {
        printf("You need a register of atleast 2 vehicles in order to sort!\n");
    }

    //Bubblesort
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++) 
        {
            //Sorting alphabetically
            if((int)tolower(vregister->VehicleArray[j].brand[0]) > (int)tolower(vregister->VehicleArray[j + 1].brand[0]))
            {
                //structs switching places
                buff = vregister->VehicleArray[j + 1];
                vregister->VehicleArray[j + 1] = vregister->VehicleArray[j];
                vregister->VehicleArray[j] = buff;
            }
        }
    }
    
}
