#include "paocontainer.h"

/*PaoContainer*/

PaoContainer::PaoContainer() : container_size(0){}

/*node*/
PaoContainer::node::node(): count_ref(0) {}

PaoContainer::node::node(AbstractVisit* visit, const smartPointer& sp): info(visit), next(sp), count_ref(0) {}

/*smartPointer*/
PaoContainer::smartPointer::smartPointer(node* n) : punt(n){
  if(punt)
    punt->count_ref++;
}

PaoContainer::smartPointer::smartPointer(const smartPointer& sp): punt(sp.punt){
  if (punt != 0)
    punt->count_ref++;
}

PaoContainer::smartPointer& PaoContainer::smartPointer::operator=(const smartPointer& sp){
  if (this != &sp){
    node* tmp = punt;
    punt = sp.punt;
    if (punt)
      punt->count_ref++;
      if (tmp){
        tmp->count_ref--;
        if (tmp->count_ref == 0)
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

bool PaoContainer::smartPointer::operator==(const smartPointer& sp) const{
  return punt == sp.punt;
}

bool PaoContainer::smartPointer::operator!=(const smartPointer& sp) const{
  return punt != sp.punt;
}

class PaoContainer::node& PaoContainer::smartPointer::operator*() const{
  return *punt;
}

class PaoContainer::node* PaoContainer::smartPointer::operator->() const{
  return punt;
}

/*iterator*/

bool PaoContainer::iterator::operator==(iterator iter) const{
  return it == iter.it;
}

bool PaoContainer::iterator::operator!=(iterator iter) const{
  return it != iter.it;
}

AbstractVisit& PaoContainer::iterator::operator*() const{
  return *(it.punt->info); //friendship
}

PaoContainer::iterator& PaoContainer::iterator::operator++(){
  if (it.punt)
    it = it->next;
    return *this;
}

PaoContainer::iterator PaoContainer::iterator::operator++(int){
  iterator aux = *this;
  if(it.punt)
    it = it->next;
    return aux;
}

/*const_iterator*/

bool PaoContainer::const_iterator::operator==(const_iterator iter) const{
  return it == iter.it;
}

bool PaoContainer::const_iterator::operator!=(const_iterator iter) const{
  return it != iter.it;
}

const AbstractVisit& PaoContainer::const_iterator::operator*() const{
  return *(it.punt->info);
}

PaoContainer::const_iterator& PaoContainer::const_iterator::operator++(){
  if(it.punt)
    it = it->next;
  return *this;
}

PaoContainer::const_iterator PaoContainer::const_iterator::operator++(int){
  const_iterator aux = *this;
  if(it.punt)
    it = it->next;
  return aux;
}
