#pragma once

#include "constants.h"
#include "libraries.h"
#include "structures.h"


void printMenu();
void addvehicle(struct vregister *vregister);
void removevehicle(struct vregister *vregister);
void sortVehicles(struct vregister *vregister);
void printvehicle(struct vregister *vregister);
void printAllvehicles(struct vregister *vregister);
int findIndex(struct vregister *vregister);
void clearStdin();