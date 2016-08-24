#ifndef PAODB_H
#define PAODB_H

/*Represent the main database in PAO*/

#include<QMap>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include"paocontainer.h"
#include"abstractowner.h"
#include"animal.h"

class PaoDB{
  private:
    QMap<QString, AbstractOwner*> users;
    QMap<unsigned int, Animal*> animals;
    PaoContainer visits;

  public:

    bool saveUSers();
    bool loadUsers();

    bool saveAnimals();
    bool loadAnimals();

    bool saveVisits();
    bool loadVisits();

    void insertVisit(AbstractVisit*);

    QMap<QString, AbstractOwner*> getUserList() const;
    QMap<unsigned int, Animal*> getAnimalList() const;
    //PaoContainer getContainer() const;

};

#endif // PAODB_H
