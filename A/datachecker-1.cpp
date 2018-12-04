// data checker 1
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	assert(s.size() >= 1 && s.size() <= 15);
	int i = 0;
	while(s[i] == '0') i++;
	while(s[i] == '1') i++;
	for(int q=i; q<s.size(); q++) {
		assert(s[q] == '0');
	}
}

