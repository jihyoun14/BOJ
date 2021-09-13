#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;


int b3085_n;
char candy[51][51];

int candy_check(int x, int y){
	int res = 0;

	// 행
	char ch = candy[x][0];
	int num = 0;
	for (int i = 0; i < b3085_n; i++) {
		if (ch == candy[x][i]){
			num++;
		}
		else {
			res = max(res, num);
			ch = candy[x][i];
			num = 1;
		}
	}
	res = max(res, num);
	
	// 열
	ch = candy[0][y];
	num = 0;
	for (int i = 0; i < b3085_n; i++) {
		if (ch == candy[i][y]){
			num++;
		}
		else {
			res = max(res, num);
			ch = candy[i][y];
			num = 1;
		}
	}
	res = max(res, num);

	return res;
}

int main(){
	int answer = 0;
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};

	cin >> b3085_n;

	for (int i = 0; i < b3085_n; i++) {
		for (int j = 0; j < b3085_n; j++) 
			cin >> candy[i][j];
	}

	//모든 칸의 오른쪽, 아래쪽 체크

	for (int x = 0; x < b3085_n; x++) {
		for (int y = 0; y < b3085_n; y++) {
			for (int k = 0; k < 4; k++) {
				int nx = x+dx[k];
				int ny = y+dy[k];

				if (nx < 0 || ny < 0 || nx >= b3085_n || ny > b3085_n)
					continue;

				swap(candy[nx][ny], candy[x][y]);
				answer = max(answer,candy_check(x,y));
				swap(candy[nx][ny], candy[x][y]);
			}
		}
	}

	cout << answer;
}