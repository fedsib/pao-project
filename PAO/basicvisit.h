#ifndef BASICVISIT_H
#define BASICVISIT_H

/*The simplest type of Visit available in PAO*/

#include"abstractvisit.h"

class BasicVisit : public AbstractVisit{

  public:
    BasicVisit(const QDate& , const QString&, const unsigned int, QString="", double=20);
    BasicVisit(const QJsonObject&);
    virtual double calcPrice() const;
    virtual QString typeOfVisit() const;

    virtual void saveObj(QJsonObject&) const;
};

#endif // BASICVISIT_H
