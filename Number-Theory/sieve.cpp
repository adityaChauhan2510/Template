#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, 1);

//sieve of eratosthenes
//TC--->  O(n*logn(logn)) ===== O(n)

void getPrimes(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i*i<N; i++){
        if(isPrime[i]){
            for(int j=i*i; j<N; j+= i){
                isPrime[j] = 0;
            }
        }
    }
}


int main(){

    getPrimes();

    int a[] = {2, 3, 4, 5, 34, 65, 67, 29, 31, 50, 93, 63};
    int n = 12;

    for(int i=0; i<n; i++){
        cout << isPrime[a[i]] << " ";
    }


    return 0;
}

    


