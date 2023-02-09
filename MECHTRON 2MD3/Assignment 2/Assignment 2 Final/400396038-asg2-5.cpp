#include <cstdlib>
#include <iostream>

typedef std::string Elem;
using namespace std;

class DNode {  // doubly linked list node
 private:
  Elem name;                 // node element value
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
  void addFront(const Elem& name);  // add to front of list
  void addBack(const Elem& name);   // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
  DNode* getHeader();
  bool UpdateScore(std::string name, int score);
  void Print();
  DLinkedList(DLinkedList& dll);
  DLinkedList & operator=(DLinkedList& dll);
  //----------------------------------------------
  int Size();
  void AddScoreInOrder(std::string name, int score);
  void RemoveScore(int index);
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;

 protected:                           // local utilities
  void add(DNode* x, const Elem& name, int score);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {  // constructor
  header = new DNode;         // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
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

void DLinkedList::add(DNode* x, const Elem& name, int score) {
  DNode* newNode = new DNode;
  newNode->name = name;
  newNode->score = score;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
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


DNode* DLinkedList::getHeader(){
    return header;
}

int DLinkedList::Size(){      
    static DNode* cur = header->next; 
    if (cur == NULL){
        cur = header->next; 
    }
    if (cur -> next == trailer){
        cur = NULL; 
        return 1; 
    }
    cur = cur->next; 
    return 1 + Size(); 
}



void DLinkedList::AddScoreInOrder(std::string name, int score) {
  DNode* temp = header; //current node
  if (header->next==trailer){  //if you have a 0 item list
    add(header, name, score); // add it after header
  }else{
    while (temp->next->score > score && temp->next != trailer){ //check for the score order and if it is not at the end
      temp = temp->next; // go to that position in order
    }
    add(temp, name, score); //add the node in the correct score position
  }
}

void DLinkedList:: RemoveScore(int index){
    DNode* current = header->next;
    if(current == trailer){ //if 0 item list do nothing
        return;
    }
    if(index<0 || index >= Size()){ //if index is out of bounds do nothing
        return;
    }
    for(int i =0; i<index;i++){ //go to the index
        current = current->next;
    }
    remove(current); //remove it
}


bool DLinkedList:: UpdateScore(std::string name, int score){
    DNode* current = header->next;
    while (current->name != name && current!=trailer){ //go the score with the name
        current  = current->next;
    }
    if(current == trailer){ //if it does not exist return false
        return 0;
    }
    current->score = score; //else if you change it 
    return 1; //return true
}

void DLinkedList:: Print(){
    static DNode* current = header->next;
    if (current == NULL){ //once you reach the end of the list reset the static variable
        current = header->next; 
    }
    if(current->next==trailer){ //change the print statment for the last element
        cout << '{' << current->name << ',' << current->score << '}' << endl; 
        current = NULL; 
        return; 
    }
    std::cout << '{' << current->name << ',' << current->score << "}->"; //print element
    current = current->next;
    Print();
}

DLinkedList::DLinkedList(DLinkedList& dll) { //copy constructor
  header = new DNode;
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL; //this entire section was the same as the contructor for Dll
  DNode* current = dll.header->next;
  while(current != dll.trailer){ //copies over everything in the current linked list to the new one
    AddScoreInOrder(current->name, current->score);
    current = current->next;
  }
}

DLinkedList & DLinkedList::operator=(DLinkedList& dll) { //same code as the copy constructor but used the overload operator
  header = new DNode;
  trailer = new DNode;
  header->next = trailer;  
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
  DNode* current = dll.header->next;
  while(current != dll.trailer){
    AddScoreInOrder(current->name, current->score);
    current = current->next;
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
    scores.Print();
    cout << "Number of scores is " << scores.Size() << endl;
   
    // Test remove function
     //scores.RemoveScore(0);
     //cout << "Number of scores is now " << scores.Size() << endl;
     //scores.Print();
    // // Test update function
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
    //scores_copy_2.OrderByName();
    //scores_copy_2.Print();
}
