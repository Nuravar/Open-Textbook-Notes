#include <iostream>
#include <string>
#include <vector>

//using namespace std;

class Deque { //deque stack that uses a circular vector
    private:
        int n; //size
        int f; //front
        int r; //rear
        int N; //max size
        std::vector<std::string> ADT; //circular vector
    public:
        Deque(int size){ //constructor
            N = size;
            f = 0;
            r = 0;
            n = 0;
            ADT.reserve(size); //reserve is used to preassign some empty space to the vector of size N, this is to make it so that there are no out of bounds errors
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

void Deque::insertFront(std::string e){ //inserts item at the "front"
    if (n == N){ //if full do nothing
        return;
    } 
    f = (f - 1 + N) % N; //changes front index to be "-1"
    ADT[f] = e; //adds the item
    n++; //increments size

}
void Deque::insertBack(std::string e){ //inserts item at the back
    if (n == N){
        return;
    } 
    ADT[r] = e; //since front changes before adding rear has to change after since nothing would be in that location
    r = (r + 1) % N; //increments rear index by "+1"
    n++; //increases size
}
void Deque::eraseFront(){
    if (n==0){ //if empty do nothing
        return;
    }
    f = (f + 1 + N) % N; //delete the front by changing the index of front to be "+1" this means that the value at the old front index will eventually be replaced
    n--; //decreases dize
}
void Deque::eraseBack(){
    if (n==0){
        return;
    }
    r = (r -1 + N) % N; //deletes back by changing index of rear to be "-1"
    n--; //decreases size
}
std::string Deque::front(){
    if (n==0){ //if empty return string
        return "error: empty deque";
    }
    return ADT[f]; //return front location
}   
std::string Deque::back(){
    if (n==0){ //if empty return string
        return "error: empty deque";
    }
    return ADT[(r-1+N)%N]; //return rear location shifted based off cicular vector

}
int Deque::size(){ //returns size counter
    return n;
}
bool Deque::empty(){ //returns bool if size counter is zero
    return n == 0;
}


