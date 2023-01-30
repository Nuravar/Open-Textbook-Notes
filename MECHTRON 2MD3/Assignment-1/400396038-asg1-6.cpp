#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

int experiment(int n){
    std::vector<int> list;
    srand(time(NULL));
    int count =0;
    bool check = false; 
    for(int i =0;i<100;i++){
        for(int j =0;j<n;j++){
            list.push_back(1 + (rand() % 365)); 
        }
        for(int k=0;k<n;k++){
            for(int l=k+1;l<n;l++){
                if(list[k]==list[l]){
                    check = true;
                }
            }
        }
        if(check== true){
            count++;
        }
        list.clear();
        check = false;
    }
    return count;
}

double probability(int num){
    int e = 100;
    double measurement = num/e;
    return measurement;
}

int main(){
    int n = 10;
    int counter = experiment(n);
    double prob = (double)counter/100;
    std::cout<< n << "," << counter << "," << prob << std::endl;

}