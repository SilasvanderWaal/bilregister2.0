#pragma once 

#include "../headers/constants.h"
#include "../headers/functions.h"
#include "../headers/libraries.h"

typedef struct person
{
    char name;
    int age;
}person;

typedef struct vehicle
{
    char type;
    char brand;
    char regNumber;
    struct person owner;
}vehicle;

typedef struct vehicleRegister
{
    vehicle *vehicleArray[10];
}vehicleRegister;


