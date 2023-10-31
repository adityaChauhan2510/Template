#include<bits/stdc++.h>
#define int long long int
using namespace std;

//This is binary multiplication.
/*
a^b = a.a.a.a.a.a.a.a..(b times)
a*b = a+a+a+a+a+a+a...(a added b times)




*/

long long multiply(int a, int b, int c) {

	long long res = 0;
	while (b) {
		if (b & 1) res = res + a, res %= c;
		a +=a; a %= c;
		b >>= 1;
	}
	return res;
}

int32_t main()
{
	
	cout << multiply(3, 7, 1e9 + 7);
	return 0;
}