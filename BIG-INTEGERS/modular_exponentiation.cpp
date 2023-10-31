#include<bits/stdc++.h>
#define int long long int 
using namespace std;

/*
a^b = a.a.a.a.a.......
(a*b)%mod = ((a%mod)*(b%mod))%mod


pow(2,200) is not equal to 2^200 but instead it is equal to (2^200)%1e9+7
*/


//TC----->O(log(b))




const int mod = 1e9 + 7;

long long powr(int a, int b) {
	long long res = 1;
	while (b) {
		if (b & 1) res *= a, res %= mod;
		a *= a; a %= mod;
		b >>= 1;
	}
	return res;
}

int32_t main()
{
	cout << powr(2, 2000);
	return 0;
}