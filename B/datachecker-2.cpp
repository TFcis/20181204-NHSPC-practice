// data checker 2
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	assert(k == n-1);

	assert(n <= 100000);
	assert(k <= 256);
	assert(k < n);
}

