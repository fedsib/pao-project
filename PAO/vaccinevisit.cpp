#include "vaccinevisit.h"

double VaccineVisit::calcPrice(){
  return (basic_price*2)+(basic_price*2)*0.3;
}
QString VaccineVisit::typeOfVisit() const{
  return "VaccineVisit";
}
