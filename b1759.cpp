#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<char> passwordv;
int vowel = 0;
int consonant = 0;
int passwordL;
int password_visited[16] = {0,};
int isVowel[26] = {0,};

void getPassword(int cnt, int idx, string password){
	if (cnt == passwordL+1){
		if (vowel < 1 || consonant < 2) return;
		else {
			cout << password << endl;
			return;
		}
	}

	for (int i = idx; i < passwordv.size(); i++){
		if (!password_visited[i]){
			password_visited[i] = 1;

			if (isVowel[passwordv[i]-'a']) vowel++;
			else consonant++;

			getPassword(cnt+1, i+1, password + passwordv[i]);

			if (isVowel[passwordv[i]-'a']) vowel--;
			else consonant--;
			password_visited[i] = 0;
		}
	}
}

int main(){
	int n;
	cin >> passwordL >> n;
	
	for (int i = 0; i < n; i++){
		char tmp;
		cin >> tmp;
		passwordv.push_back(tmp);
	}

	sort(passwordv.begin(),passwordv.end());

	isVowel['a'-'a'] = 1;
	isVowel['e'-'a'] = 1;
	isVowel['i'-'a'] = 1;
	isVowel['o'-'a'] = 1;
	isVowel['u'-'a'] = 1;

	getPassword(1,0,"");
}