/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
#include<stack>

int* stockSpan(int *price, int size);
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}

int* stockSpan(int *price, int size)  {
	// Write your code here
    int *arr=new int[size]; 
    stack<int> s;
    s.push(0);
    arr[0]=1;
    for(int i=1;i<size;i++){
        while(!s.empty() && price[s.top()]<price[i])
            s.pop();
       arr[i]=(s.empty()) ? (i+1) : (i-s.top());
        s.push(i);
    }
    return arr;
}
