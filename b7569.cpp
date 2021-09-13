#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int tomato2[101][101][101];
int dx_[6] = {0,1,0,-1,0,0};
int dy_[6] = {1,0,-1,0,0,0};
int dh_[6] = {0,0,0,0,1,-1};

int main(){
	int m, n, h;
	int answer = 0;
	queue<pair<pair<int,int>,int>> q;
	int rest_tomato = 0;

	cin >> m >> n >> h;

	
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf(" %d", &tomato2[k][i][j]);
				if (tomato2[k][i][j] == 1)
					q.push(make_pair(make_pair(i,j),k));
				else if (tomato2[k][i][j] == 0) rest_tomato++;
			}
		}
	}


	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx_[i];
			int ny = y + dy_[i];
			int nh = z + dh_[i];

			if (nx < 0 || ny < 0 || nh < 0 || nx >= n || ny >= m || nh >= h) continue;

			if (tomato2[nh][nx][ny] == -1 || tomato2[nh][nx][ny] == 1) continue;

			else if (tomato2[nh][nx][ny] == 0) {
				tomato2[nh][nx][ny] = tomato2[z][x][y] + 1;
				q.push(make_pair(make_pair(nx,ny),nh));
				rest_tomato--;
			}

			if(rest_tomato == 0) break;
		}
	}

	

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (tomato2[k][i][j] == 0) {
		            cout << -1;
		            return 0;
		        }
				if (tomato2[k][i][j] > answer) answer = tomato2[k][i][j];
			}
		}
	}
    
    cout << answer - 1;	

}