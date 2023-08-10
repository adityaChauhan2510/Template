/*
    24 -> 2*2*2*3
    15 -> 3*5    
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

            }
        }
    }
}

int main(){

    int n; cin>>n;
    unordered_map<int, int> primes;

    //function call for preComputation
    getPrimes();

    while(n > 1){
        int primeFactor = hp[n];
        //here we can use lp also

        while(n % primeFactor == 0){
            n /= primeFactor;
            primes[primeFactor]++;

        }
    }

    //TC - O(logn)
    for(auto it : primes){
        cout << it.first <<" " << it.second << endl;
    }
    cout << endl;
}