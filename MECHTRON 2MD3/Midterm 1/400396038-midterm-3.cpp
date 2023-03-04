#include <iostream>
#include <string>
#include <vector>

//using namespace std;

class Deque {
    private:
        int n; //size
        int f; //front
        int r; //rear
        int N; //max size
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
    f = (f + 1 + N) % N;
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
    return ADT[(r-1+N)%N];

}
int Deque::size(){
    return n;
}
bool Deque::empty(){
    return n == 0;
}



int main(){
    Deque dq(3);
    std::cout << "Deque is empty: " << dq.empty() << std::endl;
    dq.insertFront("hello");
    std::cout << "Deque size is: " << dq.size() << std::endl;
    std::cout << "Deque front is: " << dq.front() << std::endl;
    std::cout << "Deque back is: " << dq.back() << std::endl;
    dq.eraseFront();
  std::cout << "Deque size is: " << dq.size() << std::endl;
    std::cout << "Deque is empty: " << dq.empty() << std::endl;
    dq.insertFront("world");
    dq.insertFront("hello");
   dq.insertFront("help");
    std::cout << "Deque size is: " << dq.size() << std::endl;
    std::cout << "Deque is empty: " << dq.empty() << std::endl;
    std::cout << "Deque front is: " << dq.front() << std::endl;
    std::cout << "Deque back is: " << dq.back() << std::endl;
    return 0;
}