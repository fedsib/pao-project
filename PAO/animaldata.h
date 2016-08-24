#ifndef ANIMALDATA_H
#define ANIMALDATA_H

#include<QDate>
#include<QJsonObject>


/*Describe the basic data of a PAO's Animal*/

class AnimalData{
  private:
    QString name;
    QString size;
    QDate dateofBirth;
    QDate lastMovement;
    QString sex;
    QDate IDApplication;
    unsigned short int weight;      //measured in Kg

  public:
    AnimalData();
    AnimalData(const QString&, const QString&, const QDate&, const QDate&,
            const QString&, const QDate&, unsigned short int);
    AnimalData(const QJsonObject&);

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
    void setWeight(unsigned short int);

    void saveAnimalDataToFile(QJsonObject&);
};

#endif // ANIMALDATA_H
