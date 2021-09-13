#include <algorithm>
#include <iostream>

using namespace std;

int ground[51][51] = {0,};
int ground_visited[51][51] = {0,};
int robotAnswer = 1;
int dx_robot[4] = {-1,0,1,0}; // 북(상)->동(우)->남(하)->서(좌)
int dy_robot[4] = {0,1,0,-1};
int robot_n, robot_m;


void b14503_dfs(int x, int y, int dir, int cleanNum){
	
	for (int i = 0; i < 4; i++) {
		int nd = (dir+3-i)%4;
		int nx = x + dx_robot[nd];
		int ny = y + dy_robot[nd];

		if (ground[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= robot_n || ny >= robot_m)
			continue;

		// a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (!ground_visited[nx][ny] && ground[nx][ny] == 0){ 
			ground_visited[nx][ny] = 1;
			b14503_dfs(nx, ny, nd, cleanNum+1);		
		}
		// else 
		// b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	}

	// c. 네 방향 모두 청소가 이미 되어있는 경우 한 칸 후진
	int backDir = dir-2 < 0 ? dir+2 : dir-2;
	int bnx = x + dx_robot[backDir];
	int bny = y + dy_robot[backDir];
	if (bnx < 0 || bny < 0 || bnx > robot_n || bny > robot_m)
		return;
	else { 
		if (ground[bnx][bny] == 0) 	
			b14503_dfs(bnx, bny, dir, cleanNum);
		else {
			cout << cleanNum;
			exit(0);
		}
	}
}

int main(){
	cin >> robot_n >> robot_m;
	int r, c, dir;
	cin >> r >> c >> dir;

	for (int i = 0; i < robot_n; i++) {
		for (int j = 0; j < robot_m; j++) {
			cin >> ground[i][j];
		}
	}

	ground_visited[r][c] = 1;
	b14503_dfs(r,c,dir,1);

}
