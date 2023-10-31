#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

/*
        a b c
         
        0 0 0----->""------>""
        0 0 1----->c------>a
        0 1 0----->b------>b
        0 1 1----->bc------>ab
        1 0 0----->a------>c
        1 0 1----->ac------>ac
        1 1 0----->ab------>bc
        1 1 1----->abc------>abc

        3----> 2^3=8
              (0...........7)

*/
vector<string> subsequences;

void getAllSubsequences(string s, int n){
    
    for(int i=0; i<(1<<n); i++){
        
        string str="";
        for(int j=0; j<n; j++){
            int jthbit = i & (1<<j);
            if(jthbit){
                str += s[j];
            }

        }
        subsequences.push_back(str);
    }
}


int main(){
    string s; cin>>s;
    int n = s.size();

    getAllSubsequences(s, n);
    
    cout << subsequences.size() << endl;
    for(int i=0; i<subsequences.size(); i++){
        cout << subsequences[i] << endl;
    }
    
}