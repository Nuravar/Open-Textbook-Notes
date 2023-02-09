#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct array { //structure to store min and max value
    int arr[2];
};

struct array maxMinRecursive(vector<int> A, int n){
    static int minValue = INT32_MAX; //max integer possible to compare
    static int maxValue = INT32_MIN; //min integer possible to compare
    struct array arr; 
    int item = A[n];
    //cout << "the current item is: " << item << " with n being: " << n << endl;
    if(n==0){ //for the first (last) item do the following commands
        minValue = min(item, minValue); //check if its a min value 
        maxValue = max(item,maxValue); //check if it is a max value
        arr.arr[0] = minValue; //assign min and max value
        arr.arr[1] = maxValue;
        minValue = INT32_MAX; //reset the static variables
        maxValue = INT32_MIN;
        return arr;
    }
    minValue = min(item, minValue); //check if the min and max are true
    maxValue = max(item,maxValue);
    //cout << "the min max is: " << minValue << " " << maxValue << endl;
    return maxMinRecursive(A, n-1); //start from the last element and go towards the first
}

int main(){
    vector<int> A = {100, -20, 0, 6, 65, -7};
    int n = A.size()-1;
    struct array test = maxMinRecursive(A,n);
    cout << "Min: " << test.arr[0] << " Max: " << test.arr[1] << endl;
}
