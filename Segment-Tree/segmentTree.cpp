/*
To build--------->  nlogn
To update--------> logn
To ans a query---------> logn



if array size is 'n' then corresponding size of segment tree array is 4n
*/

//STATIC RANGE MINIMUM QUERY



#include<bits/stdc++.h>
using namespace std;


int segTree[4*200005];
int a[200005];

void build(int idx, int l, int r){

    if(l==r){
        segTree[idx] = a[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*idx+1, l, mid);
    build(2*idx+2, mid+1, r);
    segTree[idx] = min(segTree[2*idx+1], segTree[2*idx+2]);
    
}


void update(int idx, int l, int r, int pos, int newVal){

    if(l==r){
        segTree[idx] = newVal;
        return;
    }

    int mid = (l+r)/2;

    if(pos <= mid){
        update(2*idx+1, l, mid, pos, newVal);
    }else{
        update(2*idx+2, mid+1, r, pos, newVal);
    }

    segTree[idx] = min(segTree[2*idx+1], segTree[2*idx+2]);

}



int getAns(int low, int high, int qs, int qe, int idx){
    
    if(low>=qs && high<=qe)  return segTree[idx]; //completely lies
    if(high<qs || low>qe) return INT_MAX;  //does not lie

    int mid=(low+high)/2;

    int lVal = getAns(low, mid, qs, qe, 2*idx+1);
    int rVal = getAns(mid+1, high, qs, qe, 2*idx+2);

    return min(lVal, rVal);
}


void solve(){
    int n,q; cin>>n>>q;
    for(int i=0; i<n; i++) cin>>a[i];
    
    build(0,0, n-1);  //nlogn


    while(q--){
        int x,ql, qr;
        cin>>x>>ql>>qr;

        if(x==1){
            //update qr at index ql-1
            update(0, 0, n-1, ql-1,qr);
        }else{
            cout << getAns(0, n-1, ql-1, qr-1,0) <<endl; //logn
        }

        
    }
}


int main(){
    solve();
}