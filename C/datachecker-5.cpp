// data checker 1
 
#include <bits/stdc++.h>
using namespace std;

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
struct Dup{
	Dup(int a, int b): x(a), w(b){};
	int x;
	int w;
};
bool cmpDup(Dup a, Dup b) {
	if (a.x == b.x) {
		return a.w < b.w;
	}
	return a.x < b.x;
}


int main() {
	int n, k;
	cin>>n;
	assert(n <= 40000);

	vector<Line> line;
	vector<Dup> dup;
	int x1, y1, x2, y2;
	for(int q=0; q<n; q++) {
		cin>>x1>>y1>>x2>>y2;
		assert(0 <= x1 && x1 <= 1000000);
		assert(0 <= y1 && y1 <= 1000000);
		assert(0 <= x2 && x2 <= 1000000);
		assert(0 <= y2 && y2 <= 1000000);
		assert(x1 < x2);
		assert(y1 != y2);
		line.push_back(Line(Point(x1, y1), Point(x2, y2)));
		dup.push_back(Dup(x1, 1));
		dup.push_back(Dup(x2, -1));
	}

	sort(dup.begin(), dup.end(), cmpDup);
	int duplimittmp = 0;
	for(auto a:dup) {
		duplimittmp += a.w;
		assert(duplimittmp <= 100);
	}
	assert(duplimittmp == 0);

	for(int q=0; q<n-1; q++) {
		for(int w=q+1; w<n; w++) {
			assert(
				intersect(line[q].p1, line[q].p2, line[w].p1, line[w].p2) == false
			);
		}
	}
}
