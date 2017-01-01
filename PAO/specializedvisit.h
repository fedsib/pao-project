#ifndef SPECIALIZEDVISIT_H
#define SPECIALIZEDVISIT_H

/*The most expensive visit. Price is the twice of the basic plus a 30%*/
#include"abstractvisit.h"

class SpecializedVisit : public AbstractVisit{
  public:
    SpecializedVisit(const QDate& , const QString&, const unsigned int, QString="", double=20);
    SpecializedVisit(const QJsonObject&);

    virtual double calcPrice() const;
    virtual QString typeOfVisit() const;
    virtual void saveObj(QJsonObject&) const;
};

#endif // SPECIALIZEDVISIT_H
