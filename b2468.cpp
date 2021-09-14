#include <algorithm>
#include <iostream>

using namespace std;

int rainyGround[101][101];
int rainyGround_origin[101][101];
int rainy_visited[101][101] = {0,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void b2468_dfs(int x, int y, int n){
	rainy_visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!rainy_visited[nx][ny] && rainyGround[nx][ny] > 0)
			b2468_dfs(nx,ny,n);
	}

	return;
}

int main(){
	int n;
	int m = 0;
	int answer = 0;
	cin >> n;

	// 입력, 내릴 수 있는 비의 최댓값 (max) 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> rainyGround_origin[i][j];
			m = max(m,rainyGround_origin[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		copy(rainyGround_origin[i],rainyGround_origin[i]+n,rainyGround[i]);
	}

	// 비를 1~max까지 내리게 하면서 안전한 영역 개수 체크하기
	for (int rain = 0; rain < m; rain++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				rainyGround[i][j] = rainyGround[i][j] - rain < 0 ? 0 : rainyGround[i][j] - rain;
			}
		}

		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!rainy_visited[i][j] && rainyGround[i][j] > 0){
					b2468_dfs(i,j,n);
					tmp++;
				}
			}
		}
		answer = max(answer, tmp);

		//init
		for (int i = 0; i < n; i++) {
			fill_n(rainy_visited[i],n,0);
			copy(rainyGround_origin[i],rainyGround_origin[i]+n,rainyGround[i]);
		}
	}

	cout << answer;
}
