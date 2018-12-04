// data checker 4
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n;
	assert(n <= 1000);

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		assert(1<=t && t<=1000000);
	}
}
