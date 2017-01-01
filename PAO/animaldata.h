#ifndef ANIMALDATA_H
#define ANIMALDATA_H

#include<QDate>
#include<QJsonObject>


/*Describe the basic data of a PAO's Animal
 * weight is a non negative number < of 65.535
*/

class AnimalData{
  private:
    QString name;
    QDate dateofBirth;
    QString sex;
    QDate IDApplication;
    unsigned short int weight;      //measured in Kg

  public:
    AnimalData();
    AnimalData(const QString&, const QDate&, const QString&, const QDate&, unsigned short int);
    AnimalData(const QJsonObject&);

    QString getName() const;
    QDate getDateOfBirth() const;
    QString getSex() const;
    QDate getIDApplication() const;
    unsigned short int getWeight() const;

    void setName(const QString&);
    void setDateOfBirth(const QDate&);
    void setSex(const QString&);
    void setIDApplication(const QDate&);
    void setWeight(unsigned short int);

    void saveAnimalDataToFile(QJsonObject&);
};

#endif // ANIMALDATA_H
