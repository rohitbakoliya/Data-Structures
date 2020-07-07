#include<bits/stdc++.h>
using namespace std;
vector<long long int> arr , size;

void initialize(long long int n) {
    for(long long int i = 0 ; i < n ; i++) {
        arr[i] = i;
        size[i] = 1;
    }
}

long long int root(long long int i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

bool find(long long int a, long long int b) {
    return root(a) == root(b);
}

void unionfun(long long int a , long long int b) {
    long long int root_a = root(a);
    long long int root_b = root(b);
    if(size[root_a] < size[root_b]) {
        arr[root_a] = root_b;
        size[root_b] += size[root_a];
    }
    else {
        arr[root_b] = root_a;
        size[root_a] += size[root_b];
    }
}

int main() {
    long long int n , i;
    cin >> n;
    arr = vector<long long int> (n+1);
    size = vector<long long int> (n+1);
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
            unionfun(a , b);
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