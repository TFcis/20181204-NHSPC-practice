// data checker 1
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	assert(n <= 8);

	assert(n <= 100000);
	assert(k <= 256);
	assert(k < n);
}

