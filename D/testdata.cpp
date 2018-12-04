#include <bits/stdc++.h>
#include "../testlib.h"
using namespace std;

bool x[1000000];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
	vector<int> plist;
	memset(x, 0, sizeof(x));
	for(int q=2; q<1000000; q++) {
		if(x[q] == false) {
			plist.push_back(q);
//			cout<<q<<" ";
			for(int w=q*2; w < 1000000; w+=q) {
				x[w] = 1;
			}
		}
	}
//	cout<<plist.size()<<endl;
	
	for(int q=1; q<=5; q++) {
//		if(q != 5)  continue; //
		
		long long maxn = 100000;
		if(q == 1) maxn = 100;
		else if(q == 4) maxn = 1000;
		
		long long maxv = 1000000;
		if(q == 2) maxv = 128;
		
		long long maxp = 1000000;
		if(q == 3) maxp = 128;
		
		for(int w=1; w<=20; w++) {
//			if(w != 1)  continue; //
			
			cout<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<endl;
			
			long long n = rnd.next(10LL, maxn);
			cout<<"n="<<n<<" "<<endl;
			
			set<int> numbers;
			for(auto a:plist) {
				if(a > maxv || a > maxp) break;
				numbers.insert(a);
			}
			
			vector<int> res;
			
			for(int e=rnd.next(0, 5); e>0; e--) {
				res.push_back(1);
			}
			
			while(res.size() < n && numbers.size() > 0) {
//				cout<<"numbers.size="<<numbers.size()<<endl;
				set<int> tempset;
				int pickcnt = rnd.wnext(4, 2)+1;
				for(int e=0; e<pickcnt && numbers.size()>0; e++) {
					double t = pow(numbers.size(), 1.0/pickcnt);
					int a = 0;
					if(e!=0) a = pow(t, e);
					a = min(a, (int)numbers.size()-1);
					int b = numbers.size() - 1;
					if(e != pickcnt -1) b = pow(t, e+1);
					b = min(b, (int)numbers.size()-1);
//					cout<<a<<" "<<b<<endl;
					int picki = rnd.next(a, b);
					set<int>::iterator it = numbers.begin();
					advance(it, picki);
					
//					cout<<"got="<<(*it)<<" "<<picki<<" "<<numbers.size()<<endl; 
					tempset.insert(*it);
					numbers.erase(it);
				}
//				cout<<"pick=";
//				for(auto a:tempset) cout<<a<<" ";
//				cout<<endl;
				
				for(int e=rnd.wnext(5, 2); e>0; e--) {
					long long v = 1;
					for(int r=rnd.next(1, (int)tempset.size()); r>0; r--) {
						int picki = rnd.wnext(tempset.size(), -2);
						set<int>::iterator it = tempset.begin();
						advance(it, picki);
						
						v *= (*it);
						if(v > 1000000) {
							v /= (*it);
							break;
						}
//						cout<<*it<<"*";
					}
//					cout<<"="<<v<<endl;
					if(v <= maxv) {
						res.push_back(v);
					} else {
						e++;
					}
				}
				
//				system("pause");
			}
			
			
			shuffle(res.begin(), res.end());
			
			stringstream ss;
			ss<<"testdata/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);
			
			f<<res.size()<<endl;
			
			bool space = false;
			for(auto a:res) {
				if(space) f <<" ";
				f<<a;
				space = true;
			}
			f<<endl;
			
			f.close();
			
			cout<<"-------"<<endl;
	//		system("pause");
		}
	} 
}
