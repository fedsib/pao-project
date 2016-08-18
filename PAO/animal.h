#ifndef ANIMAL_H
#define ANIMAL_H

#include<animaldata.h>
#include<vector>

class Animal{
  private:
    unsigned int animalID;
    AnimalData animalInfo;
    //vector<Visita> clinicalSheet;

  public:
    Animal();
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal()=0;

};

#endif // ANIMAL_H
