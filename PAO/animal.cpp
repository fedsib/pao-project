#include "animal.h"

Animal::Animal(){}
Animal::Animal(const unsigned int, const AnimalData data, const PaoContainer&){} //TODO

unsigned int Animal::getAnimalID() const{
  return animalID;
}

AnimalData& Animal::getAnimalData() const{
  return const_cast<AnimalData&>(this->animalInfo);
}
