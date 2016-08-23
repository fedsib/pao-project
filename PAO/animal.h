#ifndef ANIMAL_H
#define ANIMAL_H

/*Describe a generic PAO's Animal.
 * Every Animal must be associated with an Owner.
 * Every Animal has a clinicalSheet (a PaoContainer of AbstractVisits*) associated */

#include"animaldata.h"
#include"abstractvisit.h"
#include"paocontainer.h"

class Animal{
  private:
    unsigned int animalID;
    AnimalData animalInfo;
    PaoContainer clinicalSheet;

  public:
    Animal();
    Animal(const unsigned int, const AnimalData data, const PaoContainer&);

    unsigned int getAnimalID() const;

    QString getName() const;
    QString getSize() const;
    QDate getDateOfBirth() const;
    QDate getLastMovement() const;
    QString getSex() const;
    QDate getIDApplication() const;
    unsigned short int getWeight() const;

    void setName(const QString&);
    void setSize(const QString&);
    void setDateOfBirth(const QDate&);
    void setLastMovement(const QDate&);
    void setSex(const QString&);
    void setIDApplication(const QDate&);
    void getWeight(unsigned short int);

    virtual QString typeOfAnimal() const =0;
};

#endif // ANIMAL_H
