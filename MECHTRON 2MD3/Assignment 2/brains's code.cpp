#include <cstdlib>
#include <iostream>
using namespace std;
typedef std::string Elem;

class DNode {  // doubly linked list node
 private:
  Elem elem;                 // node element value
  int score;
  DNode* prev;               // previous node in list
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                 // constructor
  ~DLinkedList();                // destructor
  bool empty() const;            // is list empty?
  const Elem& front() const;     // get front element
  const Elem& back() const;      // get back element
  void addFront(const Elem& e);  // add to front of list
  void addBack(const Elem& e);   // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
  DNode * getHead();
  int Size(DNode* head);
  void AddScoreInOrder(std::string name, int score);
  void Print();
  void RemoveScore(int index);
  bool UpdateScore(std::string name, int score);
  void OrderByName();
  DLinkedList(DLinkedList& newlist);
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;

 protected:                           // local utilities
  void add(DNode* v, const Elem& e);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList(DLinkedList& newlist){
  header = new DNode;
  trailer = new DNode;
  header->prev = NULL;
  header->next = trailer;
  trailer->next = NULL;
  trailer->prev = header;
  DNode * temp = newlist.header->next;
  while (temp != newlist.trailer) {
    AddScoreInOrder(temp->elem, temp->score);
    temp = temp -> next;
  }
}

void DLinkedList::OrderByName(){
  int size = Size(getHead());
  for (int i = 0; i <size-1; i++){
    DNode * temp = getHead()->next;
    for (int j = 0; j<(size-i-1); j++){
      if (temp->elem.compare(temp->next->elem) > 0){
        std::string name = temp->elem;
        int score = temp->score;
        temp->elem = temp->next->elem;
        temp->score = temp->next->score;
        temp->next->elem = name;
        temp->next->score = score;
      }
      temp = temp->next;
    }
  }
}

bool DLinkedList::UpdateScore(std::string name, int score){
  DNode * temp = getHead()->next;
  while (temp->elem != name && temp != trailer){
    temp = temp->next;
  }
  if (temp == trailer){
    return false;
  }
  temp->score = score;
  return true;
}

void DLinkedList::RemoveScore(int index){
  DNode * temp = getHead()->next;
  if (header->next == trailer){
    return;
  }
  if (index<0 || index>=Size(header)){
    return;
  }
  for (int i = 0; i<index;i++){
    temp = temp->next;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete(temp);
}

void DLinkedList::Print(){
    static DNode* temp = header->next;
    if (temp == NULL){
        temp = header->next; 
    }
    else if (temp->next == trailer){ 
        std::cout << '{' << temp->elem << ',' << temp->score << '}' << endl; 
        temp = NULL; 
        return; 
    }
    std::cout << '{' << temp->elem << ',' << temp->score << "}->";
    temp = temp->next; 
    Print(); 
}

void DLinkedList::AddScoreInOrder(std::string name, int score) {
  DNode* newNode = new DNode;
  DNode* temp = getHead();
  newNode->elem=name;
  newNode->score=score;
  if (header->next==trailer){
    header->next = newNode;
    trailer->prev = newNode;
    newNode->next = trailer;
    newNode->prev = header;
  }
  else{
    while (temp->next->score > newNode->score && temp->next != trailer){
      temp = temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next = newNode;
    newNode->next->prev = newNode;
  }
}

DNode * DLinkedList::getHead(){
    return header;
}

DLinkedList::DLinkedList() {  // constructor
  header = new DNode;         // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
}

int DLinkedList::Size(){
    static DNode* current = header->next;
    if (head->next == trailer){
        return 0;
    }
    return  1 + Size();
}

DLinkedList::~DLinkedList() {  // destructor
  while (!empty()) {
    removeFront();  //  remove all but sentinels
  }
  delete header;  //  remove the sentinels
  delete trailer;
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

const Elem& DLinkedList::front() const {  // get front element
  return header->next->elem;
}

const Elem& DLinkedList::back() const {  // get back element
  return trailer->prev->elem;
}

void DLinkedList::add(DNode* x, const Elem& value) {
  DNode* newNode = new DNode;
  newNode->elem = value;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
}

void DLinkedList::addFront(const Elem& e) {  // add to front of list
  add(header, e);
}

void DLinkedList::addBack(const Elem& e) {  // add to back of list
  add(trailer->prev, e);
}

void DLinkedList::remove(DNode* v) {  // remove node v
  DNode* u = v->prev;                 // predecessor
  DNode* w = v->next;                 // successor
  u->next = w;                        // unlink v from list
  w->prev = u;
  delete v;
}

void DLinkedList::removeFront() {  // remove from font
  remove(header->next);
}

void DLinkedList::removeBack() {  // remove from back
  remove(trailer->prev);
}

void listReverse(DLinkedList& L) {  // reverse a list
  DLinkedList T;                    // temporary list
  while (!L.empty()) {              // reverse L into T
    Elem s = L.front();
    L.removeFront();
    T.addFront(s);
  }
  while (!T.empty()) {  // copy T back to L
    Elem s = T.front();
    T.removeFront();
    L.addBack(s);
  }
}

int main() {
DLinkedList scores;
scores.AddScoreInOrder("Jeff", 7);
scores.AddScoreInOrder("Jen", 9);
scores.AddScoreInOrder("Ilya", 3);
scores.AddScoreInOrder("Sara", 10);
scores.AddScoreInOrder("Sam", 11); 
// Test size function
cout << "Number of scores is " << scores.Size(scores.getHead()) << endl;
scores.Print();
// Test remove function
scores.RemoveScore(3);
cout << "Number of scores is now " << scores.Size(scores.getHead()) << endl;
scores.Print();
// Test update function
//cout << "yes" <<endl;
if (scores.UpdateScore("Jeff",6)) 
scores.Print(); 
// Test copy construcor
DLinkedList scores_copy_1(scores);
scores.UpdateScore("Jen",5);
scores.Print();
scores_copy_1.Print();
// Test assignment operator overload
DLinkedList scores_copy_2 = scores_copy_1; 
scores_copy_1.UpdateScore("Jen",5);
scores_copy_1.Print();
scores_copy_2.Print();
// Test OrderByName function
scores_copy_2.OrderByName();
scores_copy_2.Print();//*/
}