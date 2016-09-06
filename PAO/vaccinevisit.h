#ifndef VACCINEVISIT_H
#define VACCINEVISIT_H

#include"abstractvisit.h"

class VaccineVisit : public AbstractVisit{
  public:
    VaccineVisit(const QDate& , const QString&, const unsigned int, QString="", double=20);
    VaccineVisit(const QJsonObject&);

    virtual double calcPrice() const;
    virtual QString typeOfVisit() const;
    virtual void saveObj(QJsonObject&) const;
};
#endif // VACCINEVISIT_H
