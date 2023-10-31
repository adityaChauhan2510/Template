/*
    24 -> 2*2*2*3
    15 -> 3*5    
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, -1);

void getPrimes(){
    
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i*i<N; i++){
        if(isPrime[i]){

            lp[i] = i;

            for(int j=i*i; j<N; j+= i){
                isPrime[j] = 0; 
                if(lp[j] == -1){
                    lp[j] = i;
                }

            }
        }
    }
}

int main(){

    int n; cin>>n;
    vector<int> primeFactors;

    //function call for preComputation
    getPrimes();

    while(n > 1){
        int x = lp[n];
        primeFactors.push_back(x);
        n /= x;
    }

   
   
    for(auto it : primeFactors){
        cout << it << " ";
    }
    cout << endl;
}