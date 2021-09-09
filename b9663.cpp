#include <algorithm>
#include <iostream>

using namespace std;
int queen_n;
int queen = 0;
int queenArr[15] = {0,}; // 각 행에서 Queen이 위치한 열값

bool possibleQueen(int row){
	for (int i = 0; i < row; i++){
		if (queenArr[i] == queenArr[row] || abs(queenArr[i] - queenArr[row]) == abs(i-row)) 
			return false;
	}

	return true;
}

void getQueen(int row){
	if (row == queen_n){
		queen++;
		return;
	}

	for (int col = 0; col < queen_n; col++) {
		queenArr[row] = col;

		if (possibleQueen(row))
			getQueen(row+1); 
		// 한 행에는 한 개의 queen만 놓을 수 있음
		// 따라서 한 번이라도 if를 통과하지 못한다면 실패한 경우라고 할 수 있음
		// else -> 다음 경우를 살피기 위해 재귀하지 않고 다음 열로 바로 넘어감
	}
}


int main(){
	cin >> queen_n;

	getQueen(0);

	cout << queen;
}