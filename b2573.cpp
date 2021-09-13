#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int iceberg[301][301];
int iceberg_tmp[301][301];
int iceberg_visited[301][301] = {0,};

void b2573_dfs(int x, int y, int n, int m){

	iceberg_visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {				
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		if (!iceberg_visited[nx][ny] && iceberg[nx][ny] > 0) {
			b2573_dfs(nx,ny,n,m);
		}
	}
}

bool checkIceberg(int n, int m){
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!iceberg_visited[i][j] && iceberg[i][j] > 0){
				 b2573_dfs(i,j,n,m);
				 answer ++;
			}
		}
	}

	if (answer >= 2) return true;
	else return false;
}

int main(){
	int n, m;
	cin >> n >> m;

	//queue<pair<pair<int,int>,int>> q; // 빙상이 있는 칸의 좌표
	
	int iceberg_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iceberg[i][j];
			if (iceberg[i][j] != 0) iceberg_num++;
		}
	}
	
	if (checkIceberg(n,m) || iceberg_num < 2) {
			cout << 0;
			return 0; 
	}

	// init visited
	for (int i = 0; i < n; i++) {
		fill_n(iceberg_visited[i],m,0);
	}

	int year = 1;
	while (true){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (iceberg[i][j] == 0)
					 continue;

				int melt = 0;
				for (int l = 0; l < 4; l++) {
					int nx = i + dx[l];
					int ny = j + dy[l];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (iceberg[nx][ny] == 0) melt++;
				}

				if (iceberg[i][j] - melt <= 0)
					iceberg_tmp[i][j] = 0;
				else {
					iceberg_tmp[i][j] = iceberg[i][j] - melt;
					iceberg_num++;
				}
			}
		}
		
		if (iceberg_num < 2) {// 빙산이 하나만 남을 경우 0 출력
			cout << 0;
			break; 
		}
		else iceberg_num = 0;

		//iceberg_num = 0;

		for (int t = 0; t < n; t++)
			copy(iceberg_tmp[t],iceberg_tmp[t]+m,iceberg[t]);

		if (checkIceberg(n,m)) {
			cout << year;
			break;
		}
		else year++;

		// init visited
		for (int i = 0; i < n; i++) {
			fill_n(iceberg_visited[i],m,0);
		}
	}
}