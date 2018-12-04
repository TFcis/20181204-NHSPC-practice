#include <bits/stdc++.h>
#include "../testlib.h"
using namespace std;

const char signroad = '.';
const char signwall = '#';


// http://www.bo-song.com/how-to-generate-a-maze-with-c/
class Solution{
public:
    void maze(vector<vector<char>>& map){
        for (int i = 0; i < map.size(); ++i)
        {
            for (int j = 0; j < map[0].size(); ++j)
            {
                map[i][j] = signwall;
            }
        }
        _maze(map, 0, 0);
    }
 
    void showMaze(vector<vector<char>>& map){
        for (int i = 0; i < map.size(); ++i)
        {
            for (int j = 0; j < map[0].size(); ++j)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    void _maze(vector<vector<char>>& map, int i, int j){
        int direct[][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int visitOrder[] = {0,1,2,3};
        if(i < 0 || j < 0 || i >= map.size() || j >= map[0].size()) return ;
        #ifdef DEBUG
        cout<<"("<<i<<", "<<j<<")"<<endl;
        #endif
        if(map[i][j] == signroad) return ;
 
        if(countVisitedNeighbor(map, i, j) > 1) return ;
 
        map[i][j] = signroad;
 
        shuffle(visitOrder, 4);
        
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + direct[visitOrder[k]][0];
            int nj = j + direct[visitOrder[k]][1];
            _maze(map, ni, nj);
        }
    }
 
    int countVisitedNeighbor(vector<vector<char>>& map, int i, int j){
        int direct[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int count = 0;
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + direct[k][0];
            int nj = j + direct[k][1];
            if(ni < 0 || nj < 0 || ni >= map.size() || nj >= map[0].size()) continue;
            if(map[ni][nj] == signroad) count++;
        }
        return count;
    }
    void shuffle(int a[], int n){
        for (int i = 0; i < n; ++i)
        {
            swap(a[i], a[rnd.next(n)]);
        }
    }
    void swap(int & a, int &b){
        int c = a;
        a = b;
        b = c;
    }
};
// http://www.bo-song.com/how-to-generate-a-maze-with-c/


int direct[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
char signdoor[] = "RGBY";
char signkey[] = "rgby";

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	for(int q=1; q<=5; q++) {
//		if(q != 5)  continue; //
		
		for(int w=1; w<=20; w++) {
//			if(w != 1)  continue; //
			
			cout<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<endl;
			
			int r = 1;
			int c = 1;
			while(r < 10 && c < 10) {
				r = rnd.next(5, 100);
				c = rnd.next(5, 100);
			}
			
			cout<<"r="<<r<<" c="<<c<<endl;
			
			Solution s;
		    int height = r;
		    int width = c;
		    
		    vector<char> row(width);
		    vector<vector<char>> map;
		    for (int i = 0; i < height; ++i)
		    {
		        map.push_back(row);
		    }
		    s.maze(map);
		    
			int sr = rnd.next(r);
			int sc = rnd.next(c);
			
			while(map[sr][sc] == signroad) {
				sr = rnd.next(r);
				sc = rnd.next(c);
			}
			cout<<"s="<<sr<<" "<<sc<<endl;
			map[sr][sc] = '*';
			
			int ecnt = 1;
			if(q == 2 || q == 3) ecnt = rnd.next(1, 5);
			if(q == 4 || q == 5) ecnt = rnd.next(0, 5);
			cout<<"ecnt="<<ecnt<<endl;
			for(int e=0; e<ecnt; e++) {
				int er = rnd.next(r);
				int ec = rnd.next(c);
				while(map[sr][sc] == signroad) {
					sr = rnd.next(r);
					sc = rnd.next(c);
				}
				cout<<"e="<<er<<" "<<ec<<endl;
				map[er][ec] = 'X';
			}
			
			int doorcnt = 0;
			if(q == 3) doorcnt = 1;
			else if(q == 4 || q == 5) doorcnt = rnd.next(2, 10);
			
			if(doorcnt) {
				vector<pair<int,int> > path;
				queue<pair<int,int> > neg;
				vector<vector<char>> map2 = map;
				
				int nowr = sr, nowc = sc;
				neg.push(make_pair(nowr, nowc));
				
				while(neg.size()) {
					nowr = neg.front().first;
					nowc = neg.front().second;
					neg.pop();
					map2[nowr][nowc] = signwall;
					
			        for (int k = 0; k < 4; ++k)
			        {
			            int nr = nowr + direct[k][0];
			            int nc = nowc + direct[k][1];
			            if(nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
			            if(map2[nr][nc] != signwall) {
			            	neg.push(make_pair(nr, nc));
			            	if (map2[nr][nc] == signroad) {
			            		path.push_back(make_pair(nr, nc));
							}
						}
			        }
				}
				
				for(int e=0; e<doorcnt; e++) {
					int pidoor = rnd.next(1, (int)path.size()-1);
					int pikey = rnd.next(0, pidoor-1);
					int doori = rnd.next(4);
					
					if(map[path[pidoor].first][path[pidoor].second] != signroad
							|| map[path[pikey].first][path[pikey].second] != signroad) {
						e--;
						continue;
					}
					map[path[pidoor].first][path[pidoor].second] = signdoor[doori];
					if(q != 5 || rnd.next(5) != 0) {
						map[path[pikey].first][path[pikey].second] = signdoor[doori];
					}
				}
			}
			
//		    s.showMaze(map);

			
//			shuffle(res.begin(), res.end());
			
			stringstream ss;
			ss<<"testdata/"<<setfill('0')<<setw(2)<<q<<setw(2)<<w<<".in";
			fstream f;
			f.open(ss.str().c_str(), ios::binary|ios::out);
			
//			f<<res.size()<<endl;
			f<<r<<" "<<c<<endl;
			for (int i = 0; i < map.size(); ++i)
	        {
	            for (int j = 0; j < map[0].size(); ++j)
	            {
	                f<<map[i][j];
	            }
	            f<<endl;
	        }
			
			f.close();
			
			cout<<"-------"<<endl;
	//		system("pause");
		}
	} 
}
