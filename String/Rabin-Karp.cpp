/*
RABIN-KARP(PATTERN MATChashSING)

2 strings s & t. Find whashSereever t occurs in s/count hashSow many times t occur in s

s = "abcbcc"
t = "bc"


*/
#include<bits/stdc++.h>
using namespace std;

int const p=31;
int const mod =  1e9+7;

vector<int> solve(){
    string s; cin>>s;
    string t; cin>>t;

    int S = s.size(), T = t.size();

    vector<long long> pre_pow(max(S, T)); 
    pre_pow[0] = 1; 
    for (int i = 1; i < (int)pre_pow.size(); i++) 
        pre_pow[i] = (pre_pow[i-1] * p) % mod;


    vector<long long> hashS(S + 1, 0); 
    for (int i = 0; i < S; i++)
        hashS[i+1] = (hashS[i] + (s[i] - 'a' + 1) * pre_pow[i]) % mod; 


    long long hashT = 0;
    for (int i = 0; i < T; i++) 
        hashT = (hashT + (t[i] - 'a' + 1) * pre_pow[i]) % mod; 


    vector<int> ans;
    for (int i = 0; i + T - 1 < S; i++) {
        long long currHashS = (hashS[i+T] + mod - hashS[i]) % mod;
        if (currHashS == hashT * pre_pow[i] % mod)
            ans.push_back(i);
    }
    return ans;




}

int main(){
    vector<int> ans = solve();
    
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]<< " ";
    }
    cout << '\n';
}