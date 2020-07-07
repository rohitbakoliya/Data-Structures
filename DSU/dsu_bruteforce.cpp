#include<bits/stdc++.h>
using namespace std;
vector<long long int> arr;

void initialize(long long int n) {
    for(long long int i = 0 ; i < n ; i++) {
        arr[i] = i;
    }
}

bool find(long long int a , long long int b) {
    return arr[a] == arr[b];
} 

void unionfun(long long int n , long long int a , long long int b) {
    long long int temp = arr[a];
    for(long long int i = 0 ; i < n ; i++) {
        if(arr[i] == temp) {
            arr[i] = arr[b];
        }
    }
}

int main() {
    long long n , i;
    cin >> n;
    arr = vector<long long int> (n+1);
    initialize(n);
    long long int a , b , choice; 
    p:
    cout << "1. union\n 2. find\n 3. stop\n";
    cout << "Enter the choice: ";
    cin >> choice;
    while(1) {
        if(choice == 1) {
            cout << "Enter two numbers : ";
            cin >> a >> b;
            unionfun(n , a , b);
            goto p;
        }
        else if(choice == 2) {
            cout << "Enter two numbers : ";
            cin >> a >> b;
            cout << find(a , b) << "\n";
            goto p;
        }
        else {
            break;
        }
    }

}
