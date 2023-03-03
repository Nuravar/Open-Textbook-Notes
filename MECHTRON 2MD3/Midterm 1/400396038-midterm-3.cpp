#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>    // std::rotate



class Deque {
    private:
        int n; //size
        int f; //front
        int r; //rear
        int N;
        std::vector<std::string> ADT; //circular vector
    public:
        Deque(int size){
            N = size;
            f = 0;
            r = 0;
            n = 0;
            ADT.reserve(size); 
        }
        void insertFront(std::string e);
        void insertBack(std::string e);
        void eraseFront();
        void eraseBack();
        std::string front();
        std::string back();
        int size();
        bool empty();
};

void Deque::insertFront(std::string e){
    if (n == N){
        return;
    } 
    f = (f - 1 + N) % N;
    ADT[f] = e;
    n++;

}
void Deque::insertBack(std::string e){
    if (n == N){
        return;
    } 
    ADT[r] = e;
    r = (r + 1) % N;
    n++;
}
void Deque::eraseFront(){
    if (n==0){
        return;
    }
    f = (f - 1 + N) % N;
    n--;
}
void Deque::eraseBack(){
    if (n==0){
        return;
    }
    r = (r -1 + N) % N;
    n--;
}
std::string Deque::front(){
    if (n==0){
        return "error: empty deque";
    }
    return ADT[f];
}   
std::string Deque::back(){
    if (n==0){
        return "error: empty deque";
    }
    return ADT[r]
}
int Deque::size(){
    return n;
}
bool Deque::empty(){
    return N == 0;
}



int main(){
    Deque deque(5); // testing (A)
    deque.insertBack("2");
    deque.insertBack("3");
    deque.insertBack("4");
    deque.insertBack("5"); 
    deque.insertFront("1");
    // deque.printVector(); // testing insert front (B) and back (C)
    deque.insertBack("6");
    // deque.printVector(); // testing circular insert back (C)
    deque.insertFront("7");
    // deque.printVector(); // testing circular insert front (D)
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseFront();
    deque.eraseFront();
    std::string test1 = deque.front();
    std::string test2 = deque.back();
    // std::cout << test1 << "|" << test2 <<std::endl; //testing error for front and back
    // deque.printVector(); //testing erase back (E) and front (F)
    deque.insertBack("2");
    deque.insertBack("3");
    deque.insertBack("4");
    deque.insertBack("5"); 
    deque.insertFront("1");

}