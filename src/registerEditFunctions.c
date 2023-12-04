#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"
#include "../headers/structures.h"


void addvehicle()
{
    char typeIn[MAXINPUT], brandIn[MAXINPUT], regNumberIn[MAXINPUT], ownerIn[MAXINPUT], nameIn[MAXINPUT], temp[MAXINPUT];
    int ageIn, index = 0;;

    FILE* vregister;

    
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
    struct Vehicle *car;

    //Creating a array in the heap memory.
    car = malloc(sizeof(struct Vehicle));
    
    //Filling the [index] structure with the data from the user.
    strcpy(car->type, typeIn);
    strcpy(car->brand, brandIn);
    strcpy(car->regNumber, regNumberIn);
    strcpy(car->owner.name, ownerIn);
    car->owner.age = ageIn;

    //Accessing the register textfile
    vregister = fopen("vregister.txt", "a+");

    if (vregister == NULL)
    {
        printf("Filen öppnades inte, programmet kommer att stängas ner nu");
        exit;
    }else
    {
        printf("Filen öppnades\n");
    }
    
    //Prints the members of our vechile strucutre into the binary file 
    if(fwrite(car, sizeof(struct Vehicle), 1, vregister) == 0){
        printf("Data has not been stored");
    }else{
        printf("Data has been stored\n");
    }
    
    //Closes the text file and frees up the allocated space in the heap
    fclose(vregister);
    free(car);
}

void removevehicle(){
    FILE* vregister;

    struct Vehicle VehicleArray[MAXVEHICLES];
    char buff[MAXINPUT];
    int removeIndex;

    vregister = fopen("vregister.txt", "r+");

   fread(VehicleArray, sizeof(struct Vehicle), MAXVEHICLES, vregister);

    printf("Which vehicle would you like to remove?");
    fgets(buff, MAXINPUT, stdin);
    removeIndex = atoi(buff);
   
    fclose(vregister);
}
