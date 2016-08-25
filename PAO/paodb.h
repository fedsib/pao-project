#ifndef PAODB_H
#define PAODB_H

/*Represent the main database in PAO*/

#include<QMap>
#include <QFile>
#include <QJsonObject>
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
    QMap<unsigned int, Animal*> animals;
    PaoContainer visits;
    void readUsers(const QJsonObject&);
    void readAnimals(const QJsonObject&);
    void readVisits(const QJsonObject&);

    void writeUsers(QJsonObject&) const;
    void writeAnimals(QJsonObject&) const;
    void writeVisits(QJsonObject&) const;

  public:

    //PaoDB();
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

    void removeUser(const QString&);
    void removeAnimal(const unsigned int);
    void removeVisit(const QDateTime&, const unsigned int);

    QMap<QString, AbstractOwner*> getUserList() const;
    QMap<unsigned int, Animal*> getAnimalList() const;
    //PaoContainer getContainer() const;

};

#endif // PAODB_H
