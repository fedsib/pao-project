#include "specializedvisit.h"

double SpecializedVisit::calcPrice(){
  return (basic_price*2)+(basic_price*2)*0.3;
}
QString SpecializedVisit::typeOfVisit() const{
  return "SpecializedVisit";
}
