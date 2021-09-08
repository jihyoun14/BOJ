#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int b9095_answer;
void b9095_dfs(int num, int sum){
	int answer = 0;
	
	if (sum == num){
		b9095_answer ++;
		return;
	}
	else if (num < sum) {
		return;
	}

	b9095_dfs(num,sum+1);
	b9095_dfs(num,sum+2);
	b9095_dfs(num,sum+3);
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		b9095_answer = 0;

		b9095_dfs(num,0);
		cout << b9095_answer << "\n";
	}
}