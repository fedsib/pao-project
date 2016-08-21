#include "paocontainer.h"

PaoContainer::PaoContainer() : container_size(0){}

/*node*/
PaoContainer::node::node(): count_ref(0) {}

PaoContainer::node::node(const AbstractVisit& visit, const smartPointer& sp): info(visit), next(sp), count_ref(0) {}

/*smartPointer*/
PaoContainer::smartPointer::smartPointer(node* n) : punt(n){
  if(punt)
    punt->count_ref++;
}

PaoContainer::smartPointer::smartPointer(const smartPointer& sp): punt(p.punt){
  if (punt != 0)
    punt->count_ref++;
}

PaoContainer::smartPointer& PaoContainer::smartPointer::operator=(const smartPointer& sp){
  if (this != &sp){
    node* tmp = punt;
    punt = p.punt;
    if (punt)
      punt->count_ref++;
      if (tmp){
        tmp->count_ref--;
        if (tmp->_count_ref == 0)
          delete tmp;
        }
    }
  return *this;
}

PaoContainer::smartPointer::~smartPointer(){
  if(punt){
    punt->count_ref--;
    if (punt->count_ref == 0)
      delete punt;
    }
}

bool PaoContainer::smartPointer::operator ==(const smartPointer& sp) const{
  return punt == sp.punt;
}

bool PaoContainer::smartPointer::operator !=(const smartPointer& sp) const{
  return punt != sp.punt;
}

class PaoContainer::node& PaoContainer::smartPointer::operator *() const{
  return *punt;
}

class PaoContainer::node* PaoContainer::smartPointer::operator ->() const{
  return punt;
}
