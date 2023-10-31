/*
    10 - > 2*5
    lowest Prime = 2
    highest Prime = 5

    18 -> 2*3*3
    lowestPrime = 2
    highestPrime = 3    
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, -1);
vector<int> hp(N, -1);

void getPrimes(){
    
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i*i<N; i++){
        if(isPrime[i]){

            lp[i] = hp[i] = i;

            for(int j=i*i; j<N; j+= i){
                isPrime[j] = 0;
                hp[j] = i; 

                if(lp[j] == -1){
                    lp[j] = i;
                }
            }
        }
    }
}

int main(){

    getPrimes();

    for(int i=2; i<100; i++){
        cout << lp[i] << " " <<hp[i] << endl;
    }
}