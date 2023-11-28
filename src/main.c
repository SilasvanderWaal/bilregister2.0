#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"


int main(){
    int chosenNumber;
    char temp[2];

    printMenu();

    fgets(temp, 2, stdin);
    chosenNumber = atoi(temp);


    switch (chosenNumber)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 0:
        return 0;
        
    default:
        printf("That is not an option");
        break;
    }

    return 0;
}