// data checker 4
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	assert(n <= 2000);
	assert(k <= 10);

	assert(n <= 100000);
	assert(k <= 256);
	assert(k < n);
}

