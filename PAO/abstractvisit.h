#ifndef ABSTRACTVISIT_H
#define ABSTRACTVISIT_H

/*Represent a generic Visit */

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
    void saveAbsVisit(QJsonObject&);

  public:
    AbstractVisit();
    AbstractVisit(const QDateTime& , const QString&, const QString&, unsigned int=0, double=20);

    QDateTime getDate() const;
    QString getIDVet() const;
    unsigned int getAnimalID() const;

    void setDate(const QDateTime&);
    void setIDVet(const QString&);
    void setAnimalID(const unsigned int);

    virtual double calcPrice() = 0;
    virtual QString typeOfVisit() const =0;
    virtual void saveObj(QJsonObject&) = 0;
};

#endif // ABSTRACTVISIT_H
