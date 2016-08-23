#include "basicvisit.h"

virtual double BasicVisit::calcPrice() override{
  return basic_price;
}
virtual QString BasicVisit::typeOfVisit() const override{
  return "BasicVisit";
}
