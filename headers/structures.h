#pragma once 

#include "constants.h"
#include "functions.h"
#include "libraries.h"

struct Person
{
    char name[MAXINPUT];
    int age;
};

struct Vehicle
{
    char type[MAXINPUT];
    char brand[MAXINPUT];
    char regNumber[MAXINPUT];
    struct Person owner;
};

