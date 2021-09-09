#include <algorithm>
#include <iostream>

using namespace std;
int queen_n;
int queen = 0;
int queenArr[15] = {0,}; // �� �࿡�� Queen�� ��ġ�� ����

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
		// �� �࿡�� �� ���� queen�� ���� �� ����
		// ���� �� ���̶� if�� ������� ���Ѵٸ� ������ ����� �� �� ����
		// else -> ���� ��츦 ���Ǳ� ���� ������� �ʰ� ���� ���� �ٷ� �Ѿ
	}
}


int main(){
	cin >> queen_n;

	getQueen(0);

	cout << queen;
}