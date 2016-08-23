#include "vaccinevisit.h"

virtual double VaccineVisit::calcPrice() override{
  return (basic_price*2)+(basic_price*2)*0.3;
}
virtual QString VaccineVisit::typeOfVisit() const override{
  return "VaccineVisit";
}
