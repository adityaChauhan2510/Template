#include<bits/stdc++.h>
using namespace std;
#define ll long long

// O(log(b))

/*
1) Check if last bit of 'b' is set or not. If set multiply a into res.
2) right-shift b
3) do a=a^2


*/
ll powr(ll a, ll b) {
	ll res = 1;
	while (b>0) {
		if (b & 1) res *= a;
		a *= a;
		b = b >> 1;
	}
	return res;
}

int main()
{

	cout << powr(2, 20);
	return 0;
}