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
vector<bool> isPrime(N, true);
vector<int> lp(N, 0);
vector<int> hp(N, 0);

void getPrimes(){
    //sieve Algo to check if number is prime when queries are given.
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i<N; i++){
        if(isPrime[i]==true){

            lp[i] = hp[i] = i;

            for(int j=2*i; j<N; j+= i){
                isPrime[j] = false;
                hp[j] = i; 

                if(lp[j] == 0){
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