// data checker 1
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n;
	assert(n <= 100);

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		assert(1<=t && t<=1000000);
	}
}
