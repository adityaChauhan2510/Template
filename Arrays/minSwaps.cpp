#include<bits/stdc++.h>
using namespace std;

//minimum swpas to make arrays equal when both have same distinct elements at different positions.

int minSwaps(vector<int> &b, vector<int> a) {
    int n = a.size();
    vector<int> pos(n+1);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            int j = pos[b[i]];
            swap(a[i], a[j]);
            swap(pos[a[i]], pos[a[j]]);
            ++ans;
        }
    }
    return ans;
}

