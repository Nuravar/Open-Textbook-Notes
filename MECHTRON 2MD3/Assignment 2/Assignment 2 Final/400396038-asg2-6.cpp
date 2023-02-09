#include <iostream>
#include <string>
#include <vector>
using namespace std;
int newValue;
int minValue(int **arr, int value, int index, int x){ //since the list is ordered the first num will be the greatest min max value
    //cout << "the value is: " <<value << " x is: " << x << " the value of next is"<< index << endl;
    if (value >= x){ //checks if the number is greater
        return value;
    }
    if (index == -1){ return -1; } //end condition
    minValue(arr, arr[index-1][0], arr[index-1][1], x); //resets for next node in the linked list
}

int main(){
    // line 1
    int n, first, x;
    cin >> n >> first >> x;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    for(int i = 0; i<n;i++){
        int num1, num2;
        cin >> arr[i][0] >> arr[i][1];
    }
    int num = minValue(arr, arr[first-1][0], arr[first-1][1], x);
    cout <<num << endl;
} 
/*
5 3 80
97 -1
58 5
16 2
81 1
79 4
Output:
81
*/
