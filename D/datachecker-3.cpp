// data checker 3
 
#include <bits/stdc++.h>
using namespace std;

bool x[1000000];
int main() {
	vector<int> plist;
	memset(x, 0, sizeof(x));
	for(int q=2; q<1000000; q++) {
		if(x[q] == false) {
			plist.push_back(q);
			for(int w=q*2; w < 1000000; w+=q) {
				x[w] = 1;
			}
		}
	}

	int n, k;
	cin>>n;
	assert(n <= 100000);

	int t;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		for (int i = 0; plist[i] <= 128 && i < plist.size(); ++i)
		{
			while (t%plist[i] == 0) t /= plist[i];
		}
		assert(t == 1);
	}
}
