#ifndef ABSTRACTVISIT_H
#define ABSTRACTVISIT_H

/*Represent a generic Visit
 * animalID is a non negative number < of 4.294.967.295
 */

#include<QDateTime>
#include<QJsonObject>

class AbstractVisit{
  private:
    QDateTime date;
    QString IDVet;
    QString note;
    unsigned int AnimalID;

  protected:
    double basic_price;

    AbstractVisit(const QJsonObject&);
    void saveAbsVisit(QJsonObject&) const;

  public:
    AbstractVisit();
    AbstractVisit(const QDateTime& , const QString&, const QString&, unsigned int=0, double=20);

    QDateTime getDate() const;
    QString getIDVet() const;
    unsigned int getAnimalID() const;

    void setDate(const QDateTime&);
    void setIDVet(const QString&);
    void setAnimalID(const unsigned int);

    virtual double calcPrice() const = 0;
    virtual QString typeOfVisit() const =0;
    virtual void saveObj(QJsonObject&) const = 0;
};

#endif // ABSTRACTVISIT_H
