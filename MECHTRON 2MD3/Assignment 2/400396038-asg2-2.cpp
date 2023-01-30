#include <iostream>

int ReverseArray(int* A, int i, int j){
    if(i < j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        ReverseArray(A, i+1, j-1);
    } else {
        return 0;
    }
}

int main(){
    int array[] = {4,3,6,2,5};
    ReverseArray(array, 0, 4);
    for(int i =0; i < sizeof(array)/sizeof(int); i++){
        std::cout << array[i] << std::endl;
    } 
}




