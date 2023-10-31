#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

void allBits(vector<int>& sum, int x){
    for(int i=0; i<32; i++){
        int ithbit = x & (1<<i);
        if(ithbit){
            sum[i]++;
        }
    }
}

void f(vector<int> v){
    vector<int> sum(32,0);

    for(int x : v){
        allBits(sum, x);
    }

    int num=0;
    for(int i=0; i<32; i++){
        int s = sum[i] % 3; //ith bit of number
        num += (s * (1<<i));
    }
    cout << num << endl;
}


int main(){
    vector<int> v = {1,2,1,1,2,4,2,5,4,4,6,5,5};
    f(v);
}