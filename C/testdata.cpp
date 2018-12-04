#include <bits/stdc++.h>
#include "../testlib.h"
using namespace std;


// http://www.csie.ntnu.edu.tw/~u91029/Point.html
struct Point {
	Point(long long _x, long long _y): x(_x), y(_y){};
	long long x, y;
};
long long cross(Point o, Point a, Point b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
struct Line {
	Line(Point _p1, Point _p2): p1(_p1), p2(_p2){};
	Point p1, p2;
};
bool intersect1D(long long a1, long long a2, long long b1, long long b2)
{
    if (a1 > a2) swap(a1, a2);
    if (b1 > b2) swap(b1, b2);
    return max(a1, b1) <= min(a2, b2);
}
bool intersect(Point a1, Point a2, Point b1, Point b2)
{
    return intersect1D(a1.x, a2.x, b1.x, b2.x)
        && intersect1D(a1.y, a2.y, b1.y, b2.y)
        && cross(a1, a2, b1) * cross(a1, a2, b2) <= 0
        && cross(b1, b2, a1) * cross(b1, b2, a2) <= 0;
}
// http://www.csie.ntnu.edu.tw/~u91029/Point.html

struct cmp{
    bool operator() (const Line & left, const int & right)
    {
        return left.p2.x < right;
    }
};

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	for(int q=1; q<=5; q++) {
//		if(q != 4)  continue; //
		
		long long samex = 100;
		if(q == 1) samex = 1;
		long long maxn = 40000;
		if(q == 3) maxn = 1000;
		long long maxx2 = 1000000;
		if(q == 4) {
			maxx2 = 1000;
			maxn = 10000;
		}
		
		for(int w=1; w<=20; w++) {
//			if(w != 1)  continue; //
			
			cout<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<endl;
			
			long long n = rnd.next(100LL, maxn);
			long long width = maxx2 / n * samex * 1.2;
			width = max(width, 20LL);
			cout<<"n="<<n<<" samex="<<samex<<" maxx2="<<maxx2<<" width="<<width<<endl;
			long long width2 = width / 2;
			long long leftlimit = 0;
			long long breaklimit = maxx2 * 0.99;
			long long count = 0;
			
			long long fail = 0;
			long long check = 0;
			
			vector<Line>res;
			while(count < n && leftlimit < breaklimit) {
				long long x1 = rnd.next(leftlimit, min(leftlimit + width2, maxx2-1));
				long long x2 = rnd.next(x1 + 1, min(maxx2, x1 + width));
				long long y1 = rnd.next(1LL, 1000000LL);
				long long y2;
				if(q == 2) {
					y2 = rnd.next(0LL, y1 - 1);
				} else {
					y2 = y1;
					while(y1 == y2) {
						y2 = rnd.next(0LL, 1000000LL);
					}
				}
				
				bool cross = false;
				long long bound = lower_bound(res.begin(), res.end(), x1, cmp())-res.begin();
//				cout<<count<<" ("<<x1<<","<<y1<<")("<<x2<<","<<y2<<") bound="<<bound<<" leftlimit="<<leftlimit<<endl;
				
				for(int e=bound; e<count; e++) {
//					if(res[q].p2.y > y1) continue;
//					if(res[q].p1.x < y2) continue;
					check++;
//					cout<<"checking ("<<res[e].p1.x<<","<<res[e].p1.y<<")("<<res[e].p2.x<<","<<res[e].p2.y<<")"<<endl;
					if(intersect(res[e].p1,
						res[e].p2,
						Point(x1, y1),
						Point(x2, y2))
						) {
						cross = true;
//						cout<<"cross"<<endl;
					}
				}
				
				if(cross) {
					fail ++;
					continue;
				}
				
				bound = lower_bound(res.begin(), res.end(), x2, cmp())-res.begin();
//				cout<<"insert to "<<bound<<endl;
				res.insert(res.begin()+bound, Line(Point(x1, y1), Point(x2, y2)));
				count ++;
				
//				for(Line a:res) {
//					cout<<a.p2.x<<" ";
//				}
//				cout<<endl;
				
				if(res.size() >= samex) {
					leftlimit = res[count - samex].p2.x + 1;
				}
				
//				if(count % 5 == 0) {
//					cout<<res.size()<<" "<<leftlimit<<" "<<fail<<" "<<check<<endl;
//					system("pause");
//					check=0;
//				}
				
			}
			cout<<res.size()<<endl;
			
			shuffle(res.begin(), res.end());
	
			stringstream ss;
			ss<<"testdata/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);
			f<<res.size()<<endl;
			for(auto a:res) {
				f<<a.p1.x<<" "<<a.p1.y<<" "<<a.p2.x<<" "<<a.p2.y<<endl;
			}
			f.close();
			
			cout<<"-------"<<endl;
	//		system("pause");
		}
	} 
}
