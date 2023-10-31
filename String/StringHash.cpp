#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

/*
POLYNOMIAL ROLLING HASHING

HASH(s) = (s[0] + p.s[1] + p^2.s[2] + p^3.s[2] + .......... p^(n-1).s[n-1]) % mod

*/

long long getHash(string & s){
    long long h = 0;
    long long pow = 1;
    const int p = 31;
    for(char ch : s){
        h = (h + (ch-'a'+1)*pow)%mod;
        pow = (pow*p)%mod;
    }

    return h;
}

/* 
prefix Hashes
s = "abcd"

hash("cd") = hash("abcd") - hash("ab")
           = p[3] - p[1]
           = 30784, which is clearly not hash of "cd"

    CORRECTION
s = "abcd"
p =  [1,63, 2946, 122110]  <------ prefixHashes

i=2, j=3
calculate hash of string from s(i.......j)

hash("cd") = (p[j] - p[i-1]) / 31^(i)
31^(i) * hash("cd") = (p[j] - p[i-1])



*/
            

int main(){

    string str; cin>> str;
    cout << getHash(str) <<endl;
    cout << 31810 - 33*31*31;
}