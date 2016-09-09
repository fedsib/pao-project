#ifndef ANIMAL_H
#define ANIMAL_H

/*Describe a generic PAO's Animal.
 * Every Animal must be associated with an Owner.
 * animalID is a non negative number < of 4.294.967.295
 */

#include"animaldata.h"

class Animal{
  private:
    QString animalCode;
    QString ownerID;
    unsigned int animalID;
    AnimalData animalInfo;
    void setAnimalCode();

  protected:
    void saveAbsAnimal(QJsonObject&);

  public:
    Animal(const QString&, const unsigned int);
    Animal(const QString&, const unsigned int, const AnimalData& data);
    Animal(const QJsonObject&);

    QString getOwnerID() const;
    QString getAnimalCode() const;
    unsigned int getAnimalID() const;
    AnimalData& getAnimalData() const;

    virtual QString typeOfAnimal() const =0;
    virtual void saveObj(QJsonObject&) = 0;

    void setOwnerID(const QString&);
    void setAnimalID(const unsigned int);
    void setAnimalData(const AnimalData&);
};

#endif // ANIMAL_H
