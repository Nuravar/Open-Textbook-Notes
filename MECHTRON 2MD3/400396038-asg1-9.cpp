#include <cstdlib>
#include <iostream>
using namespace std;

class Progression {  //  a generic progression
 public:
  Progression(long f = 0)  // constructor
      : first(f), cur(f) {}
  virtual ~Progression(){};      // destructor
  void printProgression(int n);  // print the first n values
 protected:
  virtual long firstValue();  // reset
  virtual long nextValue();   // advance
 protected:
  long first;  // first value
  long cur;    // current value
};

void Progression::printProgression(int n) {  // print n values
  cout << firstValue();                      // print the first
  for (int i = 2; i <= n; i++)               // print 2 through n
    cout << ' ' << nextValue();
  cout << endl;
}

long Progression::firstValue() {  //  reset
  cur = first;
  return cur;
}
long Progression::nextValue() {  // advance
  return ++cur;
}

class AProg : public Progression {
    public:
        AProg(long f = 2, long s = 200);  // constructor
    protected:
        virtual long firstValue();  // reset
        virtual long nextValue();   // advance
    protected:
        long second;  // second value
        long prev; 
    
}; 

AProg::AProg(long f, long s)
    : Progression(f), second(s), prev(first) {}

long AProg::firstValue() {  
  cur = second;
  prev = first;  
  return cur;
}

long AProg::nextValue() {  // advance
  long temp = prev;
  prev = cur;
  cur -= temp; // subtraction of previous
  cur = abs(cur); //absolute progression
  return cur;
}

/** Test program for the progression classes */
int main() {
  Progression* p;
  cout << "Absolute progression with default constructor:" << endl;
  p = new AProg();
  p->printProgression(10);
  cout << "Absolute progression with custom constructor:" << endl;
  p = new AProg(4, 400);
  p->printProgression(10);
  return 0; 
}