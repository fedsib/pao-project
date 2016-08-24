#ifndef PAODB_H
#define PAODB_H

/*Represent the main database in PAO*/

#include<QMap>
#include<vector>
#include"paocontainer.h"

#include"abstractowner.h"
#include"animal.h"
class PaoDB{
  private:
    QMap<QString, AbstractOwner*> users;
    QMap<unsigned int, Animal*> animals;
    PaoContainer visits;

  public:
    PaoDB();

};

#endif // PAODB_H
