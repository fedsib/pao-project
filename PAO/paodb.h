#ifndef PAODB_H
#define PAODB_H

/*Represent the main database in PAO*/

#include<QMap>
#include <QFile>
//#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include"paocontainer.h"
#include"owner.h"
#include"pet.h"
#include"basicvisit.h"
#include"vaccinevisit.h"
#include"specializedvisit.h"

class PaoDB{
  private:
    QMap<QString, AbstractOwner*> users;
    QMap<QString, Animal*> animals;
    PaoContainer* visits;
    void readUsers(const QJsonObject&);
    void readAnimals(const QJsonObject&);
    void readVisits(const QJsonObject&);

    void writeUsers(QJsonObject&) const;
    void writeAnimals(QJsonObject&) const;
    void writeVisits(QJsonObject&) const;


  public:
    PaoDB();
    bool saveUsers();
    bool loadUsers();

    bool saveAnimals();
    bool loadAnimals();

    bool saveVisits();
    bool loadVisits();

    void insertUser(AbstractOwner*);
    void insertAnimal(Animal*);
    void insertVisitFront(AbstractVisit*);
    void insertVisitBack(AbstractVisit*);

    bool containVisit(QString) const;
    AbstractVisit* obtainVisit(int);
    void editVisit(const QString, QString,QString,double);

    void removeUser(const QString&);
    void removeAnimal(QString);
    void removeVisit(QString);

    QMap<QString, AbstractOwner*> getUserList();
    QMap<QString, Animal*> getAnimalList() const;
    PaoContainer* getVisitList() const;

};

#endif // PAODB_H
