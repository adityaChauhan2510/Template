#include<bits/stdc++.h>
using namespace std;

// ye 1e5 tak chalega
const int N = 1e5+10;
vector<int> divisors[N]; //array of vectors

void getDivisors(){
    
    for(int i=2; i<N; i++){
        
        for(int j=i; j<N; j+= i){
            divisors[j].push_back(i);
        }
        
    }
}


int main(){
    getDivisors();

    for(int i=2; i<=10; i++){
        for(int div : divisors[i]){
            cout << div << " ";
        }
        cout << endl;
    }
}