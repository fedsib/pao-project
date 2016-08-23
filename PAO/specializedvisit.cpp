#include "specializedvisit.h"

virtual double SpecializedVisit::calcPrice() override{
  return (basic_price*2)+(basic_price*2)*0.3;
}
virtual QString SpecializedVisit::typeOfVisit() const override{
  return "SpecializedVisit";
}
