#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;


vector<string> f(int n){

    if(n==1){
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        return v;
    }

    vector<string> prevAns = f(n-1);
    vector<string> ans;

    for(int i=0; i<prevAns.size(); i++){
        ans.push_back("0" + prevAns[i]);
    } 
    for(int i=prevAns.size()-1; i>=0; i--){
        ans.push_back("1" + prevAns[i]);
    }

    return ans;
}

int main(){
    int n; cin>>n;
    vector<string> ans = f(n);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}