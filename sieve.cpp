#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, true);

void getPrimes(){
    //sieve Algo to check if number is prime when queries are given.
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i<N; i++){
        if(isPrime[i]==true){

            for(int j=2*i; j<N; j+= i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){

    getPrimes();

    int a[] = {2, 3, 4, 5, 34, 65, 67, 29, 31, 50, 93, 63};
    int n = 12;

    for(int i=0; i<n; i++){
        cout << isPrime[a[i]] << endl;
    }


    return 0;
}

    


