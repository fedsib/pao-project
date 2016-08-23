#include "animal.h"

Animal::Animal(){}

Animal::Animal(const unsigned int aID, const AnimalData& data, const PaoContainer& pc) : animalID(aID), animalInfo(data), clinicalSheet(pc){}
