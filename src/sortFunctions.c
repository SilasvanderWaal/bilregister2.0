#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

void sortVehicles(struct vregister *vregister)
{
    int index;
    struct Vehicle buff;

    index = findIndex(vregister);

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++) 
        {
            if((int)tolower(vregister->VehicleArray[j].brand[0]) > (int)tolower(vregister->VehicleArray[j + 1].brand[0]))
            {
            buff = vregister->VehicleArray[j + 1];
            vregister->VehicleArray[j + 1] = vregister->VehicleArray[j];
            vregister->VehicleArray[j] = buff;
            }
        }
    }
    
}
