#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <functional>
#include <iomanip>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath>



using namespace std;


void b11718(){

	string str;

	while(1){
		getline(cin,str);
		if(str == "")
			break;
		cout << str << endl;
	}
}

void b11718_2(){
	char c;

	while(scanf("%c", &c) != -1){
		printf("%c",c); // 출력 후 줄 바꿈
	}
}


void b11718_3(){
	char c[100];

	while(scanf("%s", c) != -1){
		printf("%s",c); // 출력 후 줄 안 바꿈
	}
}


void b11718_4(){
	 string str;

	while(scanf("%s", str) != -1){
		printf("%s",str); // 출력 후 줄 안 바꿈
	}
}


void b2908(){
	//방법1 : string으로 받아 reverse, stoi 함수 사용
	//방법2 : string으로 받아 뒤에서부터 숫자 비교
	//방법3 : int로 받아 자릿수 계산


	int a, b, tmp1 = 0, tmp2 = 0;
	scanf("%d %d", &a, &b);

	for (int i = 100; i > 0; i = i/10)
	{
		tmp1 += a%10 * i;
		tmp2 += b%10 * i;

		a /= 10;
		b /= 10;
	}

	 (tmp1 > tmp2) ? printf("%d", tmp1) : printf("%d", tmp2);

	//int result = (tmp1 > tmp2) ? tmp1 : tmp2;

	//cout << (tmp1 > tmp2) ? tmp1 : tmp2; 

	//printf("%d %d", tmp1, tmp2);
}

void b10951() {
	int a, b;
	while (scanf("%d %d", &a, &b) != -1){
		printf("%d\n", a+b); // 띄어쓰기 제대로  !!
	}
}

void b11719() {
	string str;

    while (getline(cin,str)){
        cout << str << endl;
	}
    	
}

bool compare(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

void b11650(){
	int n = 0, x = 0, y =0;
	
	scanf("%d", &n);

	vector<pair<int, int>> vec(n);


	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);

		vec[i].first = x;
		vec[i].second = y;

		// -> vec.push_back( make_pair(x,y) );
	}

	sort(vec.begin(), vec.end(), compare);

	for(auto elem : vec){
		printf("%d %d\n", elem.first, elem.second);
	}
}

void b1924(){
	vector<pair<int,int>> m;
	m.push_back(make_pair(0,0));
	m.push_back(make_pair(1,31));
	m.push_back(make_pair(2,28));
	m.push_back(make_pair(3,31));
	m.push_back(make_pair(4,30));
	m.push_back(make_pair(5,31));
	m.push_back(make_pair(6,30));
	m.push_back(make_pair(7,31));
	m.push_back(make_pair(8,31));
	m.push_back(make_pair(9,30));
	m.push_back(make_pair(10,31));
	m.push_back(make_pair(11,30));
	m.push_back(make_pair(12,31));


	int x = 0,y = 0, tmp = 0;
	scanf("%d %d", &x,&y);

	for(int i = 1; i <= x; i++){
		tmp += m[i-1].second;
	}
	tmp += y;

	//cout << tmp << endl;

	if(tmp%7 == 0) printf("SUN");
	if(tmp%7 == 1) printf("MON");
	if(tmp%7 == 2) printf("TUE");
	if(tmp%7 == 3) printf("WED");
	if(tmp%7 == 4) printf("THU");
	if(tmp%7 == 5) printf("FRI");
	if(tmp%7 == 6) printf("SAT");
}


void b1924_2(){
	int x = 0,y = 0;
	char *day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	scanf("%d %d", &x,&y);

	for(int i = 0; i < x; i++){
		y += mon[i];
	}

	printf(day[y%7]);
}



void b10992(){
	// 방법1 : * 개수는 if문으로 나눠서 
	//			https://travelbeeee.tistory.com/262
	//			https://hyeonbin0926algorithm.blogspot.com/2020/11/c-10992-17.html
	// 방법2 : for문 끝날 때마다 * 출력 후 바닥 따로 출력 https://lesslate.github.io/onlinejudge/Baekjoon-10992%EB%B2%88/
	
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) { // 라인수 0 1 2
		for (int j = 0; j < n-i-1; j++) // 공백수 2 1 0
			cout << " ";
		for (int j = 0; j < i*2 +1 ; j++){
			if (j+1 == i) cout << "*";
			//else if cout << " ";
		}
			

		cout << "\n";
	}
}

void b10828() {
	stack<int> stk;
	int n = 0, x = 0;
	//char c[] = "";
	string c;

	//scanf("%d", &n);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		//scanf("%s", c);
		cin >> c;
		
		if(c == "push") { 
			cin >> x;
			stk.push(x); 
		}
		if(c == "top") cout << stk.top() << "\n";
		if(c == "size") cout << stk.size() << "\n";
		if(c == "empty") cout << stk.empty() << "\n";
		if(c == "pop") { 
			if(stk.empty()) cout << "-1" << "\n"; 
			else cout << stk.top() << "\n"; 
			stk.pop();
		}
	}
	// https://www.acmicpc.net/source/19211752
	// https://www.acmicpc.net/source/19977962
}


void b10845() {
	queue<int> q;
	int n = 0, x = 0;
	string c;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		
		if(c == "push") { 
			cin >> x;
			q.push(x); 
		}
		if(c == "front") cout << q.front() << "\n";
		if(c == "back") cout << q.back() << "\n";
		if(c == "size") cout << q.size() << "\n";
		if(c == "empty") cout << q.empty() << "\n";
		if(c == "pop") { 
			if(q.empty()) cout << "-1" << "\n"; 
			else cout << q.front() << "\n"; 
			q.pop();
		}
	}


}


bool comp(string a, string b){

	/*if (a.substr(0,1) < b.substr(0,1) )
		return a < b;
	else 
		return a > b;*/
	return a < b;
}

void b11656(){
	string s;
	vector<string> v;

	//scanf("%s", s);
	cin >> s;


	for (int i = 0; i < (int)s.size(); i++)
		v.push_back(s.substr(i));

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << "\n";
}

void b10820(){ // 시간 개오래걸림
	string s;

	while (getline(cin,s)){
		int a[4] = {0};
		for (int i = 0; i < s.size(); i++)
		{
			if(s.substr(i,1) == " ") a[3]++; // 공백
			else if(s.at(i) >= 'A' && s.at(i) <= 'Z' ) a[1]++; // 대문자
			else if(s[i] >= 97 && s.at(i) <= 122 ) a[0]++; // 소문자
			//else if(stoi(s.substr(i,1)) >= 57) a[1]++; // 대문자
			else a[2]++; // 숫자

		}
		for (int i = 0; i < 4; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}

void b10820_2(){
	int a = 0, A = 0, n = 0, s = 0;
	char c;

	while (~(c = getchar()))
	{
		if(c>='a' && c<='z') a++;
		if(c>='A' && c<='Z') A++;
		if(c>='0' && c<='9') n++;
		if(c==' ') s++;
		if(c=='\n') printf("%d %d %d %d\n", a,A,n,s), a=A=n=s=0;
	}
}

void b224(){
	int a, b;
	int tmp = 0, max = 0;


	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		tmp -= a;
		tmp += b;

		if(tmp > max) max = tmp;
	}

	cout << max;


}


void b10870(){
	int n;
	cin >> n;
	int a = 0, b = 1, tmp = 0;
	for (int i = 0; i < n-1; i++)
	{
		tmp = a + b;
		a = b;
		b = tmp;
	}
	cout << tmp;
}

void b10870_2()
{
	int i,n,d[21]={0,1};
	scanf("%d",&n);

	for(i=2;i<=n;++i)
		d[i]=d[i-1]+d[i-2];

	printf("%d",d[n]);
}

int fibo(int num) {
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return fibo(num-2) + fibo(num-1);
}

void b10870_3() {
    int num;

    scanf("%d",&num);
    printf("%d",fibo(num));
}

void b2309(){
	vector<int> a;
	int tmp = 0;
	int idx1, idx2;
	for (int i = 0; i < 9; i++){
		int x;
		cin >> x;
		a.push_back(x);
		tmp += a[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if(tmp - a[i] - a[j] == 100){
				//a.erase(a.begin()+i);
				idx1 = a[i]; idx2 = a[j];
			}
		}
	}
	sort(a.begin(),a.end());

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != idx1 && a[i] != idx2)
			cout << a[i] << "\n";
		
	}
}

int b2609_gcd(int a, int b){
	int max;
	if(a > b) max = a;
	else max = b;

	int tmp = 1;
	for (int i = 1; i <= max/2; i++)
	{
		if ((a % i == 0) && (b % i == 0) && (tmp < i)) tmp = i;
	}

	return tmp;
}

void b2609(){
	int a,b;
	cin >> a >> b;

	cout << b2609_gcd(a,b) << " " << a*b / b2609_gcd(a,b);

}

int gcd(int n, int m){
    while(m != 0){
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int lcm(int n, int m){
    return n * m / gcd(n,m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (n > m) swap(n,m);
    
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    
    return answer;
}

void b1978(){
	int n, x;
	cin >> n;
	int tmp = n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		
		if(x == 1) tmp--;
		else {
			for (int j = 2; j < x; j++)
			{
				if (x%j == 0) {
					tmp--;
					break;
				}
			}
		}
	}

	cout << tmp;
}


void b1978_2() { // 나누어떨어지는 약수의 개수가 2인 것 구하기
	int n,k,m,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		m=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			if(k%i==0) m++;
		}
		if(m==2) ans++;
	}
	printf("%d",ans);
}



void b2581(){ // 시간 16ms 나 걸림
	int m,n;
	int sum = 0, min = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		bool isPrime = true;

		if(i == 1) continue;
		else {
			for (int j = 2; j < i; j++)
			{
				if (i%j == 0){
					isPrime = false;
					break;
				}
			}
		}
		if(isPrime) {
			sum += i;
			if (min == 0 || min > i) min = i; 
		}
	}

	if(sum == 0) cout << "-1";
	else cout << sum << " " << min;
}



bool isPrime(int n)
{
	if(n==1) return false;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}


void b2581_2()
{
	int a, b, sum=0, min;
	scanf("%d %d", &a, &b);

	for(int i=b; i>=a; i--)
	{
		if(isPrime(i))
		{
			sum += i;
			min = i;
		}
	}
	if(sum==0)  printf("-1");
	else  printf("%d\n%d", sum, min);
}


int p42578() {
	vector<vector<string>> clothes;
    int answer = 1;
    unordered_map <string,int> map;

    for(int i = 0; i < clothes.size(); i++)
        map[clothes[i][1]]++;

    for(auto tmp = map.begin(); tmp != map.end(); tmp++)
        answer *= tmp->second + 1;

    answer--;
    
    return answer;
}

int p42578_2() {
	vector<vector<string>> clothes;
    int answer = 0;
    unordered_map<string,string> map;
    
    for (int i = 0; i < clothes.size(); i++){
        
        if(map.find(clothes[i][1]) == map.end()) 
            map[clothes[i][1]] = clothes[i][0]; // 값을 꼭 넣을 필요가 없지 수만 알면 되니까
        else {
            //map.insert({map.find(clothes[i][1]), clothes[i][0]});
        }
    }
    
    
    for (int i = 0; i < map.size(); i++){
        //cout << map[i] << " ";
    }
        
    return answer;
}

bool compare2(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}

bool compare22(pair<string,int> a, pair<string,int> b){
	return a.second > b.second;
}

void p42579(){
	vector<string> genres;
	vector<int> plays;
    vector<int> answer;

	genres.push_back("classic");
	genres.push_back("pop");
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");

	plays.push_back(500);
	plays.push_back(600);
	plays.push_back(150);
	plays.push_back(800);
	plays.push_back(2500);


    unordered_map<string,vector<pair<int,int>>> map;
    unordered_map<string,int> sum;
	vector<pair<string, int>> cnt;
    
    for(int i = 0; i < genres.size(); i++){
		map[genres[i]].push_back(make_pair(i,plays[i])); 
		sum[genres[i]] += plays[i];

		//map.insert(make_pair(genres[i], make_pair(i,plays[i]))); // 지정, 값이 하나만 들어감
		//map[genres[i]] = make_pair(i,plays[i]); 
    }
	
	for (auto it = map.begin(); it != map.end(); it++)
		sort(it->second.begin(), it->second.end(), compare2);
	
	// 위와 같은 기능을 함
	//for(auto &k : map){
	//sort(k.second.begin(),k.second.end(),compare);
	//}

	cnt.assign(sum.begin(), sum.end()); // um의 반복자는 pair 형태로 넘어감
	sort(cnt.begin(),cnt.end(),compare22);
	
	//for (auto it = sum.begin(); it != sum.end(); it++)
	//	sort(it->second, it->second, compare22);
	
	//sort(map.begin()->second, map.end()->second, compare2);
    
	for (int i = 0; i < cnt.size(); i++)
	{
		cnt[i].first;
		answer.push_back(map[cnt[i].first].begin()->first);
		if (map[cnt[i].first].size() > 1)
		{
			answer.push_back((map[cnt[i].first].begin()+1)->first);
			continue;
		}
		
	}

	unordered_map<string,pair<int,int>>::iterator it;
	/*for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << it->first << " " << it->second[] << " " << it->second.second << "\n";
	}*/

    //return answer;
}

bool compare3(const string &a, const string &b){
	//if(atoi(a.c_str()) < atoi(b.c_str())
	if(a+b < b+a)
		return a < b;
	else
		return a > b;
}

void p42746(){
	// 방법 1: 모든 조합을 만들어서 비교함
	// 방법 2: 1의 자리가 큰 숫자부터 앞으로,
	//			1의 자리가 같다면 10의 자리가 큰 숫자가 앞으로

	vector<string> vec;
	vec.push_back("1");
	vec.push_back("13");
	vec.push_back("27");
	vec.push_back("76");
	vec.push_back("59");
	vec.push_back("9");
	vec.push_back("91");
	
    sort(vec.begin(),vec.end(),compare3);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

}


void p42747(){
	vector<int> citations;

	citations.push_back(6);
	citations.push_back(6);
	citations.push_back(6);
	citations.push_back(6);
	citations.push_back(6);
	citations.push_back(1);
	//citations.push_back(8);

    int answer = 0;
    
    int h = citations.size();
    int tmp = 0;
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    for(int i = 0; i < citations.size(); i++){
        if (citations[i] >= h)
            tmp++;
        else {
            h = citations[i]; 
            tmp++;
        }
        
        if(h == tmp)
            break;
    }
        
    answer = h;
        
    /*for(int i = 0; i < citations.size(); i++){
        if (citations[i] <= i+1 && answer < i+1){
            answer = citations[i];
            break;
        }
    }*/

	cout << answer;

    return;
}

void p42626(){ // 실패 ㅋㅋ
	vector<int> scoville;

	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);


	int K = 7;
    int answer = 0;
    bool keep = true; 
    int tmp = 0;
    
    
    while (keep){
        sort(scoville.begin(), scoville.end());
        
        //if(scoville.size() < 2) {answer++; break;}

        tmp = scoville[0] + (scoville[1] * 2);
        scoville.erase(scoville.begin());
        scoville.erase(scoville.begin());
        
        scoville.push_back(tmp);
        
        answer++;
        keep = false;
        for(int i = 0; i < scoville.size(); i++){
            if(scoville[i] < K) keep = true;
        }
    }
        
}

void p42626_2(){	
	vector<int> scoville;
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);


	int K = 7;
    int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	

	while (!pq.empty())
	{
		int a = pq.top();
		int b;
		int tmp = 0;
		
		if(a < K){
			pq.pop();

			if(pq.size() == 0)
				return;

			b = pq.top();
			pq.pop();

			tmp = a + (b*2);
			pq.push(tmp);
			++answer;
		}
		else 
			return;
	}
}

void p42627(){
	vector<vector<int>> jobs;
    int answer = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    for(int i = 0; i < jobs.size(); i++)
        pq.push(jobs[i]);

	
    
	vector<int> tmp;
	tmp = pq.top();
	tmp.begin();
	tmp.end();
	


}


void p42628(){
	vector<string> operations;
	vector<int> q;
    vector<int> answer;
	
	operations.push_back("I 16");
	operations.push_back("D 1");

	for (int i = 0; i < operations.size(); i++)
	{
		string o = operations[i].substr(0,1);
		string v = operations[i].substr(2,operations[i].size()-2);
		int vv = stoi(v);

		if(o == "I") 
			q.push_back(vv);
		else if(o == "D" && vv == 1 && !q.empty()) 
			q.erase(q.begin()+q.size()-1);
			// = q.erase(--q.end());

		else if(o == "D" && vv == -1 && !q.empty())
			q.erase(q.begin());

		sort(q.begin(), q.end());
	}
	if(q.empty()){
			answer.push_back(0);
			answer.push_back(0);
		}
	else{
			answer.push_back(q.back());
			answer.push_back(q.front());
		}

	cout << answer[0] << " " << answer[1];
}

void p42628_2(){
	vector<string> operations;
	priority_queue<int,vector<int>,greater<int>> q;
    vector<int> answer;
	
	operations.push_back("I 16");
	operations.push_back("D 1");

	for (int i = 0; i < operations.size(); i++)
	{
		string o = operations[i].substr(0,1);
		string v = operations[i].substr(2,operations[i].size());
		int vv = stoi(v);

		if(o == "I")
			q.push(vv);
		else if(o == "D" && vv == 1)
			q.pop();
		else if(o == "D" && vv == -1)
			q.pop();
	}
}

void p42583(){
	int bridge_length = 100; // 다리를 지나는 트럭 개수 = 다리 길이 
	int weight = 100;
	vector<int> truck_weights;
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	truck_weights.push_back(10);
	
    int answer = 0;
	int tmp = 0;
	int time = 0;
	/*int* time = new int [truck_weights.size()];
	for (int i = 0; i < truck_weights.size(); i++)
		time[i] = weight;*/
	queue<int> q;
	int i = 0;

	while(i < truck_weights.size()){
		if(tmp != 0 && time % bridge_length == 0){
			tmp -= q.front();
			q.pop();
		}

		if(tmp + truck_weights[i] <= weight){
			q.push(truck_weights[i]);
			tmp += truck_weights[i];
			time += bridge_length;
		}
		else
			i--;

		time -= q.size();
		answer++;
		i++;
	}

	while (time > 0)
	{
		if(tmp != 0 && time % bridge_length == 0){
			tmp -= q.front();
			q.pop();
		}
		time -= q.size();
		answer++;
	}

	cout << answer;// + time;

	//for (int i = 0; i < truck_weights.size(); i++)
	//{
	//	if(tmp != 0 && time % bridge_length == 0){
	//		tmp -= q.front();
	//		q.pop();
	//	}

	//	if(tmp + truck_weights[i] <= weight){
	//		q.push(truck_weights[i]);
	//		tmp += truck_weights[i];
	//		time += bridge_length;
	//	}
	//	else
	//		i--;

	//	time -= q.size();
	//	answer++;
	//}

	//cout << answer + time;
}


int p42583_2(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> tq;
    queue<int> q;
    
    for(int i = 0; i < truck_weights.size(); i++)
            tq.push(truck_weights[i]);
    
    int fullweight = 0;
    
    q.push(tq.front());
    fullweight += tq.front();
    tq.pop();
    answer++;
    
    while(!tq.empty()){
        if(q.size() < bridge_length){
            if(fullweight + tq.front() <= weight){
                q.push(tq.front());
                fullweight += tq.front();
                tq.pop();
                answer++;
            }
        }
        if(q.size() == bridge_length){
            q.pop();
            fullweight -= q.front();
            answer++;
            if(fullweight + tq.front() < weight){
                q.push(tq.front());
                fullweight += tq.front();
            }
        }
    }
    
    /*
    for(int i = 0; i < truck_weight.size(); i++){
        for(int j = 0; j < bridge_length; j++){
            q.push(truck_weight[i]);
        }
    }
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        answer++;
        if(tmp + q.front() < weight){
            
        }
    }
    */

    
    return answer;
}

bool isPrime2(int n){
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}


void p42839(){
	string numbers = "011";
	vector<char> v;
	vector<int> s;
	
	int answer = 0;

	for (int i = 0; i < numbers.length(); i++)
		v.push_back(numbers[i]);
		//s.insert(stoi(numbers.substr(i,1)));

	sort(v.begin(),v.end());

	do {
		string tmp = "";
		for (int i = 0; i < v.size(); i++) {
			tmp.push_back(v[i]);
			s.push_back(stoi(tmp));
		}
	} while (next_permutation(v.begin(),v.end()));
	
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(),s.end()),s.end());

	for (int i = 0; i < s.size(); i++)
	{
		if (isPrime2(s[i]))
			answer++;
	}

	cout << answer;
}










void p42842(){
	int brown = 24;
	int yellow = 24;
	vector<int> answer;
	vector<int> tmp;
	//vector<pair<int,int>> tmp;

	for (int i = 1; i <= sqrt(yellow); i++){
		if ((yellow % i == 0) && (i*2 + (yellow / i)*2 + 4 == brown) ){
			tmp.push_back(i +2);
			tmp.push_back(yellow / i +2);
			//tmp.push_back(make_pair(i +2, yellow / i +2));
		}
	}

	sort(tmp.begin(),tmp.end());

	
	cout <<"";
}

//int changeAlpahbet(char c){
//
//}


//void p42860(){
//    int answer = 0;
//	string name = "JEROEN";
//	bool name[21];
//	int tmp = 0;
//	int i = 0;
//
//	while (tmp < name.size())
//	{
//		answer += changeAlpahbet(name[i]);
//		if (65 < name[i+1] < 77 )
//			i++;
//		else
//			i--;
//	}
//
//	for (int i = 0; i < name.length(); i++)
//	{
//		if(name[i]-'A' == 0)
//			continue;
//	}
//}


void p42860_2(){
    int answer = 0;
	string name = "ABAAAAAAAAABB";
	string compare(name.size(),'A');

	int curser = 0;
	answer += name[0] - 'A';
	name[0] = 'A';
	int i = 1;

	while(1){
		
		if (name[curser] > 'M')   answer += 'Z' - name[curser] + 1;
		else   answer += name[curser] - 'A';
		name[curser] = 'A';

		if(name == compare) break;


		int minus = curser - i;
		int plus = curser + i;

		if(minus < 0) minus = name.size() - 1;

		if(name[plus] == 'A' && name[minus] > 'A'){
			curser = minus;
			answer += i;
		}
		else if(name[plus] > 'A' && name[minus] == 'A'){
			curser = plus;
			answer += i;
		}
		else if(name[plus] > 'A' || name[minus] > 'A'){

			if(name[plus] < name[minus])
				curser = plus;
			else
				curser = minus;

			answer += i;
		}
		else
			i = 1;


	}


}



void p42860_3(){
    int answer = 0;
	string name = "JEROEN";
	string compare(name.size(),'A');

	int i = 0;

	while (true) {
		compare[i] = name[i];
		name[i] - 'A' > 'Z' - name[i] + 1 ? 
			answer += 'Z' - name[i] + 1 : answer += name[i] - 'A';

		if(name == compare) break;

		for (int j = 1; j < name.size(); j++) {
			if (name[(i+j) % name.size()] != compare[(i+j) % name.size()]) {
				i = (i+j) % name.size();
				answer += j;
				break;
			}
			else if (name[(i-j + name.size()) % name.size()] != compare[(i-j + name.size()) % name.size()]) {
				i = (i-j + name.size()) % name.size();
				answer += j;
				break;
			}
		}
	}
	
}



void p42883(){
	string number = "4177252841";//"1231234";
	int k = 4;

    string answer = "";
    vector<char> v;

	for (int i = 0; i < number.size(); i++)
		v.push_back(number[i]);

	int idx = -1;
	int tmp = number.size() - k - 1;

	while(answer.size() < number.size() - k)
	{
		answer += *max_element(v.begin() + 1 + idx, v.end() - tmp);
		idx = max_element(v.begin() + 1 + idx, v.end() - tmp) - v.begin();
		tmp--;
	}
	cout << "";
}


void p42885() {
	vector<int> people; 
	int limit = 100;
	int answer = 0;

	people.push_back(70);
	//people.push_back(50);
	people.push_back(80);
	people.push_back(50);

	sort(people.begin(),people.end());

	//for (int i = 0; i <= people.size(); i++)
	while(!people.empty())
	{
		if(people.size() == 1){
			answer++;
			people.pop_back();
		}
		else if(people.front() + people[people.size()-1] > limit){
			people.pop_back();
			answer++;
		}
		else{
			people.erase(people.begin());
			people.pop_back();
			answer++;
		}
	}
	cout << answer;

}


void p42885_2() {
	vector<int> people; 
	int limit = 50;
	int answer = 0;

	people.push_back(60);
	people.push_back(50);
	people.push_back(40);

	sort(people.begin(),people.end());

	int size = people.size();
	int front = 0;
	int back = people.size()-1;

	while (front <= back)
	{
		if(people[front] + people[size-1] <= limit){
			front++;
			back--;
		}
		else
			back--;

		answer++;
	}
	cout << answer;

}


void p42861(){
	int n;
	vector<vector<int>> costs;
	int answer = 0;
}




//출처: https://mjmjmj98.tistory.com/76 [dlroW ,olleH]

int set[101];   // node의 parent를 저장하는 배열
 
int getParent(int node) {
    if(set[node] == node) return node; // 부모 노드가 없으면 (연결이 없으면) 내가 부모이자 자식 노드 나를 반환함
    return set[node] = getParent(set[node]); // 부모 노드가 있으면 부모 노드 구하기
}
 
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
 
int p42861_2() {
    int answer = 0;
	int n = 4;
	vector<vector<int>> costs;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(1);
	costs.push_back(v1);
	v2.push_back(0);
	v2.push_back(2);
	v2.push_back(2);
	costs.push_back(v2);
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(5);
	costs.push_back(v3);
	v4.push_back(1);
	v4.push_back(3);
	v4.push_back(1);
	costs.push_back(v4);
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(8);
	costs.push_back(v5);

    for(int i = 0; i < n; i++)
        set[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);  // 비용을 오름차순 정렬
 
    for(int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
 
        if(start != end) {  // 부모 노드가 같을 경우 = 연결됨
							// cycle이 만들어지지 않을 경우 다리를 추가
            answer += cost;
            set[end] = start;
        }
    }
 
    return answer;
}
 

bool cmp3(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

void p42884(){
	vector<vector<int>> routes;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
    int answer = 0;

	v1.push_back(-20);
	v1.push_back(15);
	routes.push_back(v1);
	v2.push_back(-14);
	v2.push_back(-5);
	routes.push_back(v2);
	v3.push_back(-18);
	v3.push_back(-13);
	routes.push_back(v3);
	v4.push_back(-5);
	v4.push_back(-3);
	routes.push_back(v4);

	sort(routes.begin(),routes.end(),cmp3);

    int n = 1;
    
    for(int i = 0; i < routes.size(); i++){
        if(i == 0) continue;
        if(routes[i-1][1] < routes[i][0]){
            // 포함되지 않는다면
            answer++;
            n = 0;
        }
        else{
            n++;
        }
    }
    answer += n;

}


void p42884_2(){
	vector<vector<int>> routes;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
    int answer = 1;

	v1.push_back(-20);
	v1.push_back(15);
	routes.push_back(v1);
	v2.push_back(-14);
	v2.push_back(-5);
	routes.push_back(v2);
	v3.push_back(-18);
	v3.push_back(-13);
	routes.push_back(v3);
	v4.push_back(-5);
	v4.push_back(-3);
	routes.push_back(v4);

	 sort(routes.begin(), routes.end());
    //비교를 위해 처음차가 나가는 부분 체크
    int temp = routes[0][1];
    //리스트 순회하기
    for (auto a : routes) {
        //현재 차가 나가는 부분보다 뒤에 차가 들어온다면
        if (temp < a[0]) {
            //카메라 설치
            answer++;
            //나가는 부분 정정
            temp = a[1];
        }
        //현재 차보다 뒤차가 먼저나가면 
        if (temp >= a[1])    temp = a[1];// 나가는 부분을 뒷차로 수정
    }

}



void n63(){
	int n,m;

	cin >> n >> m;

	vector<int> vec;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(),vec.end());

	vector<int> arr(m,10001);
	arr[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int i = 0; i < vec.size(); i++)
		{

		}
	}


}



void p42895(){
	int N = 5; int number = 12;
    int answer = 0;

}


void p43105(){
	vector<vector<int>> triangle;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	v1.push_back(7);
	triangle.push_back(v1);
	v2.push_back(3);
	v2.push_back(8);
	triangle.push_back(v2);
	v3.push_back(8);
	v3.push_back(1);
	v3.push_back(0);
	triangle.push_back(v3);
	v4.push_back(2);
	v4.push_back(7);
	v4.push_back(4);
	v4.push_back(4);
	triangle.push_back(v4);
	v5.push_back(4);
	v5.push_back(5);
	v5.push_back(2);
	v5.push_back(6);
	v5.push_back(5);
	triangle.push_back(v5);


    int answer = 0;
    int max = 0;
    
    int size = triangle.size();
    int i = triangle.size() - 1;
    
    for(int j = 0; j < size; j++){
        
        int tmp = j;
        max += triangle[i][tmp];

        while(1){
            if(i == 0) break;
        
            if((tmp == i) || (tmp != 0 && triangle[i-1][tmp-1] > triangle[i-1][tmp]) )
                 tmp--;
            
            i--;
            max += triangle[i][tmp];
        }
        
        if(max > answer) answer = max;
        i = triangle.size() - 1;
        max = 0;
    }
}

void p43105_2(){
	vector<vector<int>> triangle;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	v1.push_back(7);
	triangle.push_back(v1);
	v2.push_back(3);
	v2.push_back(8);
	triangle.push_back(v2);
	v3.push_back(8);
	v3.push_back(1);
	v3.push_back(0);
	triangle.push_back(v3);
	v4.push_back(2);
	v4.push_back(7);
	v4.push_back(4);
	v4.push_back(4);
	triangle.push_back(v4);
	v5.push_back(4);
	v5.push_back(5);
	v5.push_back(2);
	v5.push_back(6);
	v5.push_back(5);
	triangle.push_back(v5);

    int answer = 0;
	int max = 0;

	for (int i = triangle.size()-1; i > -1; i--) {
		for (int j = 0; j < triangle[i].size()-1; j++) {
			max =  (triangle[i][j] > triangle[i][j+1] ? triangle[i][j] : triangle[i][j+1]);
			triangle[i-1][j] += max;
		}
	}

	answer = triangle[0][0];
}


void p42898(){
	int m = 7;
	int n = 4; 
	vector<vector<int>> puddles;
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(1);
	puddles.push_back(v1);
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);
	puddles.push_back(v2);
	vector<int> v3;
	v3.push_back(2);
	v3.push_back(3);
	puddles.push_back(v3);
	vector<int> v4;
	v4.push_back(4);
	v4.push_back(2);
	puddles.push_back(v4);
	vector<int> v5;
	v5.push_back(4);
	v5.push_back(3);
	puddles.push_back(v5);
	vector<int> v6;
	v6.push_back(4);
	v6.push_back(4);
	puddles.push_back(v6);
	vector<int> v7;
	v7.push_back(6);
	v7.push_back(2);
	puddles.push_back(v7);
	vector<int> v8;
	v8.push_back(6);
	v8.push_back(3);
	puddles.push_back(v8);

	int answer = 0;
	int arr[101][101] = {0};

	for (auto elem : puddles)
		arr[elem[1]][elem[0]] = -1;

	arr[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == -1) {arr[i][j] = 0; continue; }
			int top = i != 0 ? arr[i-1][j] : 0;
			int left = j != 0 ? arr[i][j-1] : 0;

			arr[i][j] = (top + left + arr[i][j]) % 1000000007;
		}
	}
	cout << arr[n][m] % 1000000007;
}




void p42897(){
	vector<int> money;
	money.push_back(91);
	money.push_back(90);
	money.push_back(5);
	money.push_back(7);
	money.push_back(5);
	money.push_back(7);

    int max_1 = 0;
    int max_2 = 0;
	int arr_1[1001] = {0};
	int arr_2[1001] = {0};

	arr_1[0] = money[0];
	arr_1[1] = max(money[0],money[1]);
	for (int i = 2; i < money.size()-1; i++) {
		arr_1[i] = max(arr_1[i-1], arr_1[i-2] + money[i]);
        if(arr_1[i] > max_1) max_1 = arr_1[i]; 
	}

	arr_2[1] = money[1];
	arr_2[2] = max(money[1],money[2]);
	for (int i = 3; i < money.size(); i++) {
		arr_2[i] = max(arr_2[i-1], arr_2[i-2] + money[i]);
        if(arr_2[i] > max_2) max_2 = arr_2[i]; 
	}

	cout << max(max_1, max_2) << " ";
}


void p43165(){
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	int target = 3;
    int answer = 0;


}

bool dfs(vector<vector<int>> &computers, int i);

void p43162(){
	vector<vector<int>> computers;
	
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(0);
	computers.push_back(v1);
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(0);
	computers.push_back(v2);
	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(1);
	computers.push_back(v3);

	int n = 3;
    int answer = 0;
	int arr[201][201];

	for (int i = 0; i < n; i++)	{
		if (computers[i][i] && dfs(computers,i))
			answer ++;
	}

	/*stack<int> stk;
	stk.push(0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ( i != j && computers[i][j] ) stk.push(j);
		}
	}*/

}

bool dfs(vector<vector<int>> &computers, int i){
	if(!computers[i][i]) return false;
	else computers[i][i] = 0;
	for (int j = 0; j < computers.size(); j++) {
		if (computers[i][j]) dfs(computers, j);
	}

	return true;
}





bool compare_43163(string a, string b){
	// 한 글자만 다를 때 true
	int tmp = 0;
	for (int i = 0; i < a.length(); i++)
		if(a[i] != b[i]) tmp++;

	if(tmp == 1) return true;
	else return false;
}

int check[51] = {0,};

void dfs_43163(string begin, string target, vector<string> words, int count, int& answer){
	for (int i = 0; i < words.size(); i++) {
		if (compare_43163(begin, words[i]) && !check[i]) {
			if (words[i] == target && answer > count+1){
				answer = count + 1;
				return;
			}
			check[i] = 1;
			dfs_43163(words[i], target, words, count+1, answer);
			check[i] = 0;
		}
	}
}

//int dfs_43163(string target, vector<string> words, string current, int count){
//    if(current == target) {
//        return count;
//    }
//    
//    if(compare_43163(current,target)){
//        dfs();
//    }
//    
//    
//}

void p43163(){
	int answer = 100;
	string begin = "hit";
	string target = "cog";
	vector<string> words;
	words.push_back("hot");
	words.push_back("dot");
	words.push_back("dog");
	words.push_back("lot");
	words.push_back("log");
	words.push_back("cog");

	//unordered_set<string> set;

	//for (int i = 0; i < words.size(); i++)
	//	set.insert(words[i]);

	//if(set.find(target) == set.end()) cout << "0";
	//else {
	
	dfs_43163(begin, target, words, 0, answer);

	cout << answer;
}

vector<vector<int>> relate(1001);
bool visit_b1260[1001] = {false,};
bool discovered_b1260[1001] = {false,};

void dfs_b1260(int here){
	visit_b1260[here] = true;

	cout << here << " ";

	for (int i = 0; i < relate[here].size(); i++)
	{
		int next = relate[here][i];
		if(!visit_b1260[next]) dfs_b1260(next);
	}
	
	return;
}

bool compare_b1260(int a, int b){
	if(a < b)
		return true;
	else
		return false;
}

void bfs_b1260(int here, int n){
	queue<int> q;
	queue<int> order;
	q.push(here);
	discovered_b1260[here] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";

		for (int i = 0; i < relate[tmp].size(); i++)
		{
			int j = relate[tmp][i];
			if (!discovered_b1260[j]) {
				q.push(j);
				discovered_b1260[j] = true;
			}
		}
	}
}

void b1260(){
	int n;
	int m;
	int begin;

	//bool *visit = new bool [n];

	cin >> n >> m >> begin;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		relate[a].push_back(b);
		relate[b].push_back(a);
	}

	for (int i = 1; i <= n; i++){
		if(!relate[i].empty())
			sort(relate[i].begin(),relate[i].end(),compare_b1260);
	}

	// DFS
	if(!visit_b1260[begin]) dfs_b1260(begin);

	cout << "\n";

	// BFS
	bfs_b1260(begin, n);

}

void b2178(){
	int n, m;
	int arr[100][100] = {0,};
	int distance[100][100] = {-1,};
	int visited[100][100] = {false,};
	int answer = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;
			scanf(" %c",&tmp);
			arr[i][j] = tmp - '0';
		}
	}

	queue<pair<int,int>> q;

	q.push(make_pair(0, 0));

	distance[0][0] = 1;
	visited[0][0] = true;
	
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		answer ++;

			// right
		if(!visited[i][j+1] && arr[i][j+1]) {
			q.push(make_pair(i, j+1));
			visited[i][j+1] = true;
			distance[i][j+1] = distance[i][j] + 1;
		}

		// left
		if(j-1 != -1 && !visited[i][j-1] && arr[i][j-1]) {
			q.push(make_pair(i, j-1));
			visited[i][j-1] = true;
			distance[i][j-1] = distance[i][j] + 1;
		}

		// down
		if(!visited[i+1][j] && arr[i+1][j]) {
			q.push(make_pair(i+1, j));
			visited[i+1][j] = true;
			distance[i+1][j] = distance[i][j] + 1;
		}

		// top
		if(i-1 != -1 && !visited[i-1][j] && arr[i-1][j]) {
			q.push(make_pair(i-1, j));
			visited[i-1][j] = true;
			distance[i-1][j] = distance[i][j] + 1;
		}

	}		
	cout << distance[n-1][m-1];
} 



char arr_b1303[101][101];
bool visited_b1303[101][101] = {false,};
int n, m;

void dfs_b1303(int i, int j, int& num){

	num++;
	visited_b1303[i][j] = true;

	//right
	if(j+1 <= m && !visited_b1303[i][j+1] && arr_b1303[i][j] == arr_b1303[i][j+1]){
		dfs_b1303(i,j+1, num);
	}
	//left
	if(j-1 != -1 && !visited_b1303[i][j-1] && arr_b1303[i][j] == arr_b1303[i][j-1]){
		dfs_b1303(i,j-1, num);
	}
	//top
	if(i-1 != -1 && !visited_b1303[i-1][j] && arr_b1303[i][j] == arr_b1303[i-1][j]){
		dfs_b1303(i-1,j, num);
	}
	//down
	if(i+1 <= n && !visited_b1303[i+1][j] && arr_b1303[i][j] == arr_b1303[i+1][j]){
		dfs_b1303(i+1,j, num);
	}

	return;
}

void b1303(){
	int w = 0;
	int b = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf(" %c",&c);
			arr_b1303[i][j] = c;
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(!visited_b1303[i][j]) {
				int num = 0;
				dfs_b1303(i,j, num);
				if(arr_b1303[i][j] == 'W') w += num*num;
				else b += num*num;
			}
		}
	}

	cout << w << " " << b;
}

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dfs_b1303_2(int x, int y, char c){
	int sum = 1;
	visited_b1303[x][y] = true;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) 
			continue;
		if (!visited_b1303[nx][ny] && arr_b1303[nx][ny] == c) 
			sum += dfs_b1303_2(nx, ny, c);
	}

	return sum;
}

void b1303_2(){
	int w = 0;
	int b = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf(" %c",&c);
			arr_b1303[i][j] = c;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(!visited_b1303[i][j]) {
				int num = dfs_b1303_2(i,j, arr_b1303[i][j]);
				if(arr_b1303[i][j] == 'W') w += num*num;
				else b += num*num;
			}
		}
	}

	cout << w << " " << b;
}


//int dx[4] = {-1,0,1,0};
//int dy[4] = {0,1,0,-1};

bool visited_b1743[101][101] = {false,};
int arr_b1743[101][101] = {0,};
int n_b1743, m_b1743, k_b1743;

int dfs_b1743(int x, int y){

	
	//answer_b1743++;
	int sum = 1;
	
	visited_b1743[x][y] = true;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 1 || ny > n_b1743 || nx < 1 || nx > m_b1743) 
			continue;
		if (!visited_b1743[nx][ny] && arr_b1743[nx][ny] == 1) 
			sum += dfs_b1743(nx, ny);
	}

	return sum;
}

void b1743(){
	int answer = 0;
	
	cin >> n_b1743 >> m_b1743 >> k_b1743;

	for (int i = 0; i < k_b1743; i++) {
		int x, y;
		cin >> x >> y;
		arr_b1743[x][y] = 1;
	}
	int tmp;
	for (int i = 1; i <= m_b1743; i++) {
		for (int j = 1; j <= n_b1743; j++) {
			if(arr_b1743[j][i] == 1) tmp = dfs_b1743(j,i);
			if(tmp > answer) answer = tmp;
 		}
	}

	cout << answer;
}

int dfs_b1743_2(int x, int y){

	int sum = 1;
	
	visited_b1743[x][y] = true;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || ny >= m_b1743 || nx < 0 || nx >= n_b1743) 
			continue;
		if (!visited_b1743[nx][ny] && arr_b1743[nx][ny]) 
			sum += dfs_b1743(nx, ny);
	}

	return sum;
}

void b1743_2(){
	int answer = 0;
	
	cin >> n_b1743 >> m_b1743 >> k_b1743;

	for (int i = 0; i < k_b1743; i++) {
		int x, y;
		cin >> x >> y;
		arr_b1743[x-1][y-1] = 1;
	}
	int tmp;
	for (int i = 0; i < n_b1743; i++) {
		for (int j = 0; j < m_b1743; j++) {
			if(arr_b1743[i][j] && !visited_b1743[i][j]) 
				tmp = dfs_b1743(j,i);
			if(tmp > answer) answer = tmp;
 		}
	}

	cout << answer;
}

bool visited[101];

int dfs_b2606(int i, vector<vector<int>> vec){
	int ret = 1;
	visited[i] = true;
	for (int j = 0; j < vec[i].size(); j++) {
		int next = vec[i][j];
		if(!visited[next]) {
			ret += dfs_b2606(next, vec);
		}
	}
	return ret;
}

void b2606(){
	int n, m, answer = 0;
	cin >> n >> m;

	vector<vector<int>> vec(101);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	if(!visited[1]) answer = dfs_b2606(1, vec);
	cout << answer - 1;
}




int tmp[6];
int k;
void dfs_b6603(vector<int> v, int i, int count){
	if (count == 6) {// 완성된 tmp vector answer에 넣기
        for (int j = 0; j < 6; j++)
            cout << tmp[j] << " ";
        cout << "\n";
		return;
    }
	
	for (int j = i; j < k; j++)
	{
		//tmp vector에 추가
		tmp[count] = v[j];
		dfs_b6603(v, j+1, count+1);
	}
	
}


void b6603(){
	//unordered_set<int> set;

	while (true)
	{
		vector<int> v(13);	
		cin >> k;

		if(k == 0) break;

		for (int i = 0; i < k; i++)
			cin >> v[i];

		int count = 0;
		dfs_b6603(v, 0, count);
		cout << "\n";
	}

}

int tomato[1001][1001];

void b7576(){
	int n, m;
	int answer = 0;
	queue<pair<int,int>> q;
	int rest_tomato = 0;

	cin >> m >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf(" %d", &tomato[i][j]);
			if (tomato[i][j] == 1)
				q.push(make_pair(i,j));
			else if (tomato[i][j] == 0) rest_tomato++;
		}
	}


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;

			if (tomato[nx][ny] == -1 || tomato[nx][ny] == 1) continue;

			else if (tomato[nx][ny] == 0) {
				tomato[nx][ny] = tomato[x][y] + 1;
				q.push(make_pair(nx,ny));
				rest_tomato--;
			}

			if(rest_tomato == 0) break;
		}
	}

	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (tomato[i][j] == 0) {
				answer = -1;
				return;
			}
			if (tomato[i][j] > answer) answer = tomato[i][j];
		}
	}
}



void b7562(){

	int dx2[] = {-2,-1, 1, 2,2,1,-1,-2};
	int dy2[] = {-1,-2,-2,-1,1,2, 2, 1};

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		bool visited[301][301] = {false,};
		int chess[301][301] = {0,};
		queue<pair<int,int>> q;

		int n; // 체스판 한 변의 길이
		int xc, yc; // 나이트의 위치
		int xd, yd; // 이동하려고 하는 위치

		cin >> n;
		cin >> xc >> yc >> xd >> yd;

		q.push(make_pair(xc,yc));
		visited[xc][yc] = true;
		//chess[xc][yc] = 1;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int j = 0; j < 8; j++) {
				int nx = x + dx2[j];
				int ny = y + dy2[j];


				if (nx < 0 || ny < 0 || nx > n-1 || ny > n-1) continue;

				if(!visited[nx][ny]){
					chess[nx][ny] = chess[x][y] + 1;
					visited[nx][ny] = true;
					q.push(make_pair(nx,ny));
				}
				//if (chess[nx][ny] == 0) chess[nx][ny] = chess[x][y] + 1;

				//if (chess[nx][ny] > chess[x][y] + 1) 
				//	chess[nx][ny] = chess[x][y] + 1;

				//q.push(make_pair(nx,ny));
				
				//if(nx == xd && ny == yd) break;

			}
		}

		cout << chess[xd][yd] << "\n";
	}
}



void b1697(){
	bool arr[100001] = {false,};
	queue<pair<int,int>> q;

	int n, k, answer = 0;
	cin >> n >> k;

	q.push(make_pair(n,0));

	while (!q.empty()) {
		int num = q.front().first;
		int cost = q.front().second;
		q.pop();

		if(num == k){
			answer = cost;

			break;
		}

		if (num - 1 >= 0 && !arr[num - 1]) {
			arr[num - 1] = true;
			q.push(make_pair(num - 1, cost+1));
		}
		if (num + 1 <= k && !arr[num + 1]) {
			arr[num + 1] = true;
			q.push(make_pair(num + 1, cost+1));
		}
		if (num * 2 <= k+1 && !arr[num * 2]) {
			arr[num * 2] = true;
			q.push(make_pair(num * 2, cost+1));
		}
	}

	cout << answer;
}



void b12851(){
	int n, k, answer_1 = 0, answer_2 = 0;
	cin >> n >> k;

	queue<pair<int,int>> q;
	bool visited[100001] = {false,};
	bool arrived = false;

	q.push(make_pair(n,0));

	while (!q.empty()){
		int tmp = q.front().first;
		int cost = q.front().second;
		q.pop();

		visited[tmp] = true;

		//if (answer_2 && answer_1 == cost && tmp == k){
		//	answer_2++;
		//}
		//if(!answer_2 && tmp == k){
		//	answer_1 = cost;
		//	answer_2++;
		//}

		//if(tmp == k) {
		//	if (arrived && cost == answer_1)
		//		answer_2++;
		//	else if (!arrived){
		//		arrived = true;
		//		answer_1 = cost;
		//		answer_2++;
		//	}
		//}

		if(tmp == k && arrived && cost == answer_1)
			answer_2++;

		else if(tmp == k && !arrived){
			arrived = true;
			answer_1 = cost;
			answer_2++;
		}


		if(tmp - 1 >= 0 && !visited[tmp-1]){
			//visited[tmp-1] = true;
			q.push(make_pair(tmp-1,cost+1));
		}
		if(tmp + 1 <= k && !visited[tmp+1]){
			//visited[tmp+1] = true;
			q.push(make_pair(tmp+1,cost+1));
		}
		if(tmp * 2 <= k+1 && !visited[tmp*2]){
			//visited[tmp*2] = true;
			q.push(make_pair(tmp*2,cost+1));
		}
	}

	cout << answer_1 << "\n" << answer_2;
}


void b13549(){
	#define INF 999999999
	int cost[100001];

	for (int i = 0; i < 100001; i++)
		cost[i] = INF;
	queue<int> q;

	int n, k, answer = 0;
	cin >> n >> k;

	q.push(n);
	cost[n] = 0;

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if(num == k){
			answer = cost[k];
			break;
		}

		if (num - 1 >= 0 && cost[num - 1] > cost[num] + 1) {
			cost[num - 1] = cost[num] + 1;
			q.push(num - 1);
		}
		if (num + 1 <= k && cost[num + 1] > cost[num] + 1) {
			cost[num + 1] = cost[num] + 1;
			q.push(num + 1);
		}
		if (num * 2 <= k+1 && cost[num * 2] > cost[num]) {
			cost[num * 2] = cost[num];
			q.push(num * 2);
		}
	}

	cout << answer;
}


void b13913(){
	bool arr[100001] = {false,};
	int parent[100001];
	vector<int> path;
	queue<pair<int,int>> q;

	int n, k, answer = 0;
	cin >> n >> k;

	q.push(make_pair(n,0));

	while (!q.empty()) {
		int num = q.front().first;
		int cost = q.front().second;
		q.pop();

		if(num == k){
			answer = cost;

			int tmp = k;
			while (tmp != n) {
				path.push_back(tmp);
				tmp = parent[tmp];
			}
			path.push_back(n);

			break;
		}

		if (num - 1 >= 0 && !arr[num - 1]) {
			arr[num - 1] = true;
			q.push(make_pair(num - 1, cost+1));
			parent[num-1] = num;
		}
		if (num + 1 <= k && !arr[num + 1]) {
			arr[num + 1] = true;
			q.push(make_pair(num + 1, cost+1));
			parent[num+1] = num;
		}
		if (num * 2 <= k+1 && !arr[num * 2]) {
			arr[num * 2] = true;
			q.push(make_pair(num * 2, cost+1));
			parent[num*2] = num;
		}
	}
	cout << answer << "\n";
	for (int i = path.size()-1; i >= 0; i--)
		cout << path[i] << " ";
}



void b14226(){

	int s, answer = 0;
	cin >> s;

	bool visited[1001] = {false,};
	int cost[1001] = {0,};
	for (int i = 0; i < 1001; i++)
		cost[i] = 99999;

	queue<int> q;
	q.push(1);
	cost[1] = 0;
	int copy = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		visited[now] = true;
		if (now == s) break;

		//minus
		if (now - 1 > 0 && !visited[now-1] && cost[now-1] > cost[now] + 1){
			q.push(now-1);
			cost[now-1] = cost[now] + 1;
		}

		//only paste
		if (copy != 0 && now + copy <= s + 1 && !visited[now + copy] && cost[now + copy] > cost[now] + 1){
			q.push(now + copy);
			cost[now + copy] = cost[now] + 1;
		}

		if (now * 2 <= s + 1 && !visited[now*2] && cost[now*2] > cost[now] + 2){
			q.push(now*2);
			cost[now*2] = cost[now] + 2;
			copy = now;
		}
	}

	answer = cost[s];
	cout << answer;
}


void b14226_2(){

	int s, answer = 0;
	cin >> s;

	bool visited[1001][1001] = {false,};
	//int cost[1001] = {0,};
	//for (int i = 0; i < 1001; i++)
	//	cost[i] = 99999;

	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair( make_pair(1,0),0 ));

	//cost[1] = 0;
	//int copy = 0;

	while (!q.empty()) {
		int now = q.front().first.first;
		int cost = q.front().first.second;
		int clip = q.front().second;
		q.pop();

		visited[now][clip] = true;

		if (now == s) {
			answer = cost;
			break;
		}

		//delete one
		if (now - 1 > 0 && !visited[now-1][clip]){
			q.push(make_pair( make_pair(now-1,cost+1), clip ));
			//cost[now-1] = cost[now] + 1;
		}

		//copy
		if (!visited[now][now]){
			q.push(make_pair( make_pair(now,cost+1), now ));
			//cost[now + copy] = cost[now] + 1;
		}

		//paste
		if (now + clip <= s + 1 && !visited[now+clip][clip]){
			q.push(make_pair( make_pair(now+clip, cost+1), clip ));
			//cost[now*2] = cost[now] + 2;
			//copy = now;
		}
	}

	//answer = cost[s];
	cout << answer;
}


void b17086(){
	int n, m;
	int arr[51][51];
	int cost[51][51] = {0,};
	queue<pair<int,int>> q;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j]) q.push(make_pair(i,j));
		}
	}

	int dx[8] = {-1,0,1,0, -1, 1, 1, -1};
	int dy[8] = {0,1,0,-1, 1, -1, 1, -1};

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx > 0 || ny > 0 || nx <= n || ny <= m) continue;
			if(arr[nx][ny] == 1) continue;

			if(cost[nx][ny] != 0 && cost[nx][ny] < cost[x][y] + 1){
				cost[nx][ny] = cost[x][y] + 1;
				q.push(make_pair(nx,ny));
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(answer < cost[i][j]) answer = cost[i][j];
		}
	}	

	cout << answer;
}

void b17086_2(){
	int n, m;
	int arr[51][51] = {0,};
	queue<pair<int,int>> q;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j]) q.push(make_pair(i,j));
		}
	}

	int dx[8] = {-1,0,1,0, -1, 1, 1, -1};
	int dy[8] = {0,1,0,-1, 1, -1, 1, -1};

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(arr[nx][ny] == 1) continue;
			else if (arr[nx][ny] == 0) {
				if(arr[nx][ny] < arr[x][y] + 1){
					arr[nx][ny] = arr[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(answer < arr[i][j]) answer = arr[i][j];
		}
	}	

	cout << answer-1;
}



void b1789(){
	long long s;
	long long answer = 0;

	cin >> s;

	long long tmp = 0;
	for (int i = 1; i <= s; i++)
	{
		answer++;
		tmp += i;
		if(tmp > s) {
			answer--;
			break;
		}
	}

	cout << answer;
}


void b3085(){
	int n;
	int answer = 0;
	char candy[51][51];
	char candy_change[51][51];
	int dx[5] = {0,-1,0,1,0};
	int dy[5] = {0,0,1,0,-1};

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> candy[i][j];
			candy_change[i][j] = candy[i][j];
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			for(int k = 0; k < 5; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				int count_row = 0;
				int count_col = 0;
				char now_char = candy[nx][ny];
				char origin_char = candy[i][j];
				bool start_row = false;
				bool start_col = false;


				candy_change[i][j] = now_char;
				candy_change[nx][ny] = origin_char;//candy_change[i][j];


				// 행 검사
				for (int m = 0; m < n; m++) {
					if (candy_change[i][m] == now_char) {
						if(!start_row) start_row = true;
						count_row++;
					}
					else if (start_row) break;
				}

				// 열 검사
				for (int m = 0; m < n; m++) {
					
					if (candy_change[m][j] == now_char) {
						if(!start_col) start_col = true;
						count_col++;
					}
					else if (start_col) break;
				}

				// 최댓값 조사
				int tmp = count_row > count_col ? count_row : count_col;
				answer = answer > tmp ? answer : tmp;

				// 원상복귀
				candy_change[i][j] = candy[i][j];
				candy_change[nx][ny] = candy[nx][ny];
			}
		}
	}

	// k = 2
	// i = 2
	// j = 3

	cout << answer;
}





void b3085_2(){
	int n;
	int answer = 0;
	char candy[51][51];
	int dx[5] = {0,-1,0,1,0};
	int dy[5] = {0,0,1,0,-1};

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> candy[i][j];
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			
			for(int k = 0; k < 5; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				int count_row = 0;
				int count_col = 0;
				char now_char = candy[nx][ny];
				char origin_char = candy[i][j];
				bool start_row = false;
				bool start_col = false;

				
				swap(candy[i][j], candy[nx][ny]);

				// 행 검사
				for (int m = 0; m < n; m++) {
					if (candy[i][m] == now_char) {
						if(!start_row) start_row = true;
						count_row++;
					}
					else if (start_row) break;
				}

				// 열 검사
				for (int m = 0; m < n; m++) {
					
					if (candy[m][j] == now_char) {
						if(!start_col) start_col = true;
						count_col++;
					}
					else if (start_col) break;
				}

				// 최댓값 조사
				int tmp = count_row > count_col ? count_row : count_col;
				answer = answer > tmp ? answer : tmp;

				// 원상복구
				swap(candy[i][j], candy[nx][ny]);
			}
		}
	}


	cout << answer;
}



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

void b3085_3(){
	int answer = 0;
	int dx[5] = {0,1,0,-1};
	int dy[5] = {1,0,-1,0};

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





int coin[101];
int coin_num= 0;
int coin_k= 0;

int dfs_b2293(int m, int sum){
	int count = 0;

	//sum += coin[m];

	//if (sum == k)
	//	return 1;
	//else
	//	sum += dfs_b2293(m+1, sum);

	if(sum > coin_k) return 0;

	for (int i = 0; i < coin_num; i++) {

		sum += coin[i];
		if(sum != coin_k)
			count += dfs_b2293(i, sum);
		else 
			return count + 1;
	}
}


void b2293(){
	int answer = 0;
	int dp[101] = {0,};
	cin >> coin_num >> coin_k;
	for (int i = 0; i < coin_num; i++)
		cin >> coin[i];

	
	answer = dfs_b2293(0, 0);

	cout << answer;
}



void b2293_2(){
	int answer = 0;
	int n = 0;
	int k = 0;	
	int coin[101] = {0,};
	int dp[10001] = {0,};

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	dp[0] = 1;

	for (int i = 0; i < n; i++)	{
		for (int j = 1; j <= k; j++) {
			if(j - coin[i] > -1)
				dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k];
}





void b2294(){
	int answer = 0;
	int n = 0;
	int k = 0;	
	int coin[101] = {0,};
	int dp[100001];
	fill(dp,dp+100001,100001);

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	


	dp[0] = 0;
	for (int i = 0; i < n; i++)	{ // 코인 인덱스
		for (int j = coin[i]; j <= k; j++) { // 만들려고 하는 가치
			dp[j] = min(dp[j], dp[j-coin[i]]+1);
		}
	}

	dp[k] = dp[k] == 100001 ? -1 : dp[k];
	cout << dp[k];
}





void b1292(){
	int a,b;
	cin >> a >> b;
	
	int arr[1001];
	int tmp = 1;
	int j = 0;
	while (true) {


		for (int i = 0; i < tmp; i++) {
			arr[j] = tmp;
			j++;
		}
		if(j > b) break;

		tmp++;
	}

	int answer = 0;
	for (int i = a; i <= b; i++)
	{
		answer += arr[i-1];
	}

	cout << answer;
}



void b2504(){
	int answer = 0;
	int x = 0;
	int y = 0;
	string str;

	cin >> str;

	stack<char> stk_x;
	stack<char> stk_y;

	for (int i = 0; i < str.size(); i++) {
		char now = str[i];
		
		if (now == '(') stk_x.push(now);
		if (now == ')') {
			stk_x.pop();

			if (x == 0) 
				x += 2;
			else if (x != 0) 
				x *= 2;
			else if (x != 0 && y != 0){
				x = (x+y) * 2;
				y = 0;
			}
		}

		if (now == '[') stk_y.push(now);
		if (now == ']') {
			stk_y.pop();

			if (y == 0) 
				y += 3;
			else if (y != 0) 
				y *= 3;
			else if (x != 0 && y != 0){
				y = (x+y) * 3;
				x = 0;
			}
		}
	}

	answer = (!stk_x.empty() || !stk_y.empty()) ? 0 : x + y;
	cout << answer;
}





void b2504_2(){
	stack<char> stk;
	string str;
	cin >> str;

	int tmp = 1;
	int answer = 0;
	for (int i = 0; i < str.size(); i++){
		
		if (str[i] == '(') {
			tmp *= 2;
			stk.push('(');
		}
		else if (str[i] == ')') {
			if (stk.empty() || stk.top() != '('){
				cout << 0;
				exit(0);
			}
			if (stk.top() == '(') {
				if (str[i-1] == '(') 
					answer += tmp;
				tmp /= 2;
				stk.pop();
			}
		}
		else if (str[i] == '[') {
			tmp *= 3;
			stk.push('[');
		}
		else if (str[i] == ']'){
			if (stk.empty() || stk.top() != '['){
				cout << 0;
				exit(0);
			}
			if (stk.top() == '[') {
				if (str[i-1] == '[') 
					answer += tmp;
				tmp /= 3;
				stk.pop();
			}
		}
	}

	if (!stk.empty())
		cout << 0;
	else
		cout << answer;
}








void b14719(){
	int n, m;
	int answer = 0;
	int arr[501];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	int water = 0;
	int max = 0;
	int max_idx = 0;
	for (int i = 0; i < m; i++)
	{
		if (arr[i] >= max) {

			// 이전까지의 물 저장
			for (int j = max_idx; j < i; j++)
				water += max - arr[j];

			max = arr[i];
			max_idx = i;
			answer += water;
			water = 0;
		}
	}

	cout << answer;

}


void b14719_2(){
	int n, m;
	int arr[501];
	int water = 0;
	//int waterCube[501][501];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++) {

		int left_max = arr[i];
		int right_max = arr[i];

		// 왼쪽 검사
		for (int j = 0; j < i; j++)
			if (arr[j] >= left_max) 
				left_max = arr[j];

		// 오른쪽 검사
		for (int j = i+1; j < m; j++)
			if (arr[j] >= right_max) 
				right_max = arr[j];

		int max = left_max >= right_max ? right_max : left_max;

		water += max - arr[i];
	}

	cout << water;

	//https://hwan-shell.tistory.com/276
	//최대값 구하는 코드 참고하기
}


void b1062(){
	int n, k;
	vector<string> words;
	int alphabet[27] = {0,};

	cin >> n >> k;
	int able_k = k-5;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp.substr(4,tmp.size()-8));
	}
	
	int max = 0;
	for (int i = 0; i < n; i++){

		int alphabet_tmp[27] = {0,};

		for (int j = 0; j < words[i].size(); j++) {
			char tmp = words[i][j];
			if (words[i][j] == 'a' || words[i][j] == 'n' || words[i][j] == 't' || words[i][j] == 'i' || words[i][j] == 'c')
				continue;
			alphabet_tmp[ words[i][j] - 97 ] ++;
		}

		for (int j = 0; j < 27; j++) {
			if (alphabet_tmp[j] > 0) {
				alphabet[j]++;
				if (alphabet[j] > max) max = alphabet[j];
			}
		}
	}

	vector<char> vec;
	for (int i = 0; i < 27; i++) {
		//if (alphabet[i] == max) vec.push_back((char)i+97);


	}

	if (able_k)

	cout << "";
	
}

int Anta_visited[27] = {0,};
vector<char> alphabetAnta;
vector<string> wordsAnta;
int teach_k;
int able_k;
int antaAnswer = -1;

int checkAnta(){
	int res = 0;
	int antaPossible[27] = {0,};
	
	antaPossible['a' - 'a'] = 1;
	antaPossible['n' - 'a'] = 1;
	antaPossible['t' - 'a'] = 1;
	antaPossible['i' - 'a'] = 1;
	antaPossible['c' - 'a'] = 1;

	for (int i = 0; i < alphabetAnta.size(); i++){
		if (Anta_visited[i]) antaPossible[alphabetAnta[i]-'a'] = 1;
	}
	
	for (int i = 0; i < wordsAnta.size(); i++) {
		bool isPossible = true;

		for (int j = 0; j < wordsAnta[i].size(); j++) {
			if (!antaPossible[wordsAnta[i][j]-'a']) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) res++;
	}

	return res;
}

void getAnta(int cnt, int idx){
	if (cnt == able_k+1 || cnt == alphabetAnta.size()+1) {
		int tmp = checkAnta();
		if (tmp > antaAnswer) antaAnswer = tmp;
		return;
	}

	for (int i = idx; i < alphabetAnta.size(); i++) {
		if (!Anta_visited[i]) {
			Anta_visited[i] = 1;
			getAnta(cnt+1, i+1);
			Anta_visited[i] = 0;
		}
	}
}

void b1062_2(){
	int n;
	//int alphabet_num = 0;
	int alphabet[27] = {0,};
	int teach[27] = {0,};

	alphabet['a' - 'a'] = 1;
	alphabet['n' - 'a'] = 1;
	alphabet['t' - 'a'] = 1;
	alphabet['i' - 'a'] = 1;
	alphabet['c' - 'a'] = 1;
	
	cin >> n >> teach_k;
	able_k = teach_k-5;

	if (teach_k < 5) {
		cout << 0;
		return;
	}

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		wordsAnta.push_back(tmp.substr(4,tmp.size()-8));
		for (int j = 0; j < wordsAnta[i].size(); j++) {
			if (alphabet[wordsAnta[i][j] - 'a'] == 0) {
				//alphabet_num++;
				alphabetAnta.push_back(wordsAnta[i][j]);
			}
			alphabet[wordsAnta[i][j] - 'a'] = 1;
		}
	}

	if (able_k <= 0) {
		int tmp = checkAnta();
		if (tmp > antaAnswer) antaAnswer = tmp;
		cout << antaAnswer;
		return;
	}

	getAnta(1,0);


	cout << antaAnswer;
	return;
}






void b1806(){
	int n, s;
	vector<int> vec;
	int answer = 0;

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int minLen = 0x7FFFFFF;
	while (start <= end) {

		if (sum >= s) {
			minLen = min(minLen,end-start);
			sum -= vec[start];
			start ++;
		}
		else if (end == n) break;
		else {
			sum += vec[end];
			end ++;
		}
	}
	if (minLen == 0x7FFFFFF) cout << 0 << endl;
	else cout << minLen;
}



void b1806_2(){
	int n, s;
	int answer = 99999999999999999;
	cin >> n >> s;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(),v.end());

	int end = 0;
	long long sum = 0;
	for (int start = 0; start < n; start++)
	{
		while (sum <= s && end < n)
		{
			sum += v[end];
			end++;
		}

		if (sum >= s){
			if (answer > end - start) answer = end - start;
		}

		sum -= v[start];
	}
	cout << answer;
}




void b1806_3(){
	int n, s;
	int answer = 99999999;
	int arr[100001];
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;

	while (start <= end) {

		if (sum >= s) {
			answer = min(answer,end-start);
			sum -= arr[start ++];
		}
		else if (end == n) break;
		else  sum += arr[end ++];
	}

	if (answer == 99999999) cout << 0;
	else cout << answer;
}



void b1916(){
	int n, m;
	int answer = 0;
	//bool visited[1001] = {false,};
	vector<pair<int,int>> vec[100001];
	priority_queue<pair<int,int>> q;
	int dist[1001];

	fill(dist, dist+1001, 999999999);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		vec[a].push_back(make_pair(b,cost));
	}

	int start, end;
	cin >> start >> end;

	dist[start] = 0;
	q.push(make_pair(0,start));

	while (!q.empty()) {
		int cost = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (dist[node] < cost) continue;

		for (int i = 0; i < vec[node].size(); i++) {
			int next_node = vec[node][i].first;
			int next_cost = vec[node][i].second + cost;

			//if ( !visited[next_node] ) 
			if (dist[next_node] > next_cost){
				dist[next_node] = next_cost;
				q.push(make_pair(-next_cost,next_node));
			}
		}
	}

	cout << dist[end];
}


int b14888_n;
vector<int> vec(100);
//vector<int> oper;
int oper[4]; // + - * /
int tmp_sum = 0;
int b14888_min = 1e9;
int b14888_max = -1;

void b14888_bfs(int idx){

	if (idx >= b14888_n) {
		return;
	}
	else {

		if (oper[idx-1] == 0) tmp_sum += vec[idx];
		else if (oper[idx-1] == 1) tmp_sum -= vec[idx];
		else if (oper[idx-1] == 2) tmp_sum *= vec[idx];
		else if (oper[idx-1] == 3) tmp_sum /= vec[idx];
		
		if (tmp_sum < b14888_min) b14888_min = tmp_sum;
		if (tmp_sum > b14888_max) b14888_max = tmp_sum;

		for (int i = idx; i <= b14888_n; i++)
		{
			b14888_bfs(i+1);
		}
	}

}

void b14888(){

	cin >> b14888_n;
	for (int i = 0; i < b14888_n; i++)
		cin >> vec[i];
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) 
			oper[i];
	}
	//cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

	tmp_sum = vec[0];
	b14888_bfs(1);

	cout << b14888_max << endl << b14888_min;
}

void b14888_bfs_2(int res, int pls, int mim, int mul, int div, int idx){

	if (idx == b14888_n){
		if (res < b14888_min) b14888_min = res;
		if (res > b14888_max) b14888_max = res;
		return;
	}
	else {
		if (pls > 0) b14888_bfs_2(res + vec[idx], pls-1, mim, mul, div, idx+1);
		if (mim > 0) b14888_bfs_2(res - vec[idx], pls, mim-1, mul, div, idx+1);
		if (mul > 0) b14888_bfs_2(res * vec[idx], pls, mim, mul-1, div, idx+1);
		if (div > 0) b14888_bfs_2((int)(res / vec[idx]), pls, mim, mul, div-1, idx+1);
	}

	return;
}

void b14888_2(){


	cin >> b14888_n;
	for (int i = 0; i < b14888_n; i++)
		cin >> vec[i];
	cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

	b14888_bfs_2(vec[0],oper[0],oper[1],oper[2],oper[3],1);

	cout << b14888_max << endl << b14888_min;
}


void b1700(){
	int list[101];
	int tab[101];
	int n, k;
	int answer = 0;

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> list[101];

	// 일단 빈 탭에 플러그 꽂기
	for (int i = 0; i < n; i++)
		tab[i] = list[i];

	for (int i = n; i < k; i++)
	{
		bool tab_yes = false;
		for (int j = 0; j < n; j++){
			if (tab[j] == list[i]) {
				tab_yes = true;
				break;
			}
		}

		if (tab_yes) continue;
		else {
			for (int j = 0; j < n; j++) {
				int min_idx, min_val = 999999;
				for (int m = n; m < k; m++) {
					if (list[m] == tab[j]) {
						if (m < min_val) {
							min_val = m;
							min_idx = tab[j];
						}
					}
				}
			}


		}
	}
}





void b1700_2(){
	int list[101];
	int tab[101] = {0,};
	int n, k;
	int answer = 0;

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> list[i];

	for (int i = 0; i < k; i++)
	{

		bool pass = false;

		for (int j = 0; j < n; j++) {

			// 콘센트에 이미 꽂혀있으면 pass
			if (tab[j] == list[i]) {
				pass = true;
				break;
			}
		}
		if(pass) continue;

		// 빈 콘센트에 꽂기
		for (int j = 0; j < n; j++) {
			if (tab[j] == 0) {
				tab[j] = list[i];
				pass = true;
				break;
			}
		}
		if(pass) continue;

		// 비워야 할 콘센트 찾기			
		int con_num = -1;
		int tab_num;

		for (int j = 0; j < n; j++) {
			int lastUsedIdx = 0;
			for (int l = i+1; l < k; l++) {
				// 쓰는 순서가 가장 나중이거나 / 사용되지 않는 콘센트
				if (tab[j] == list[l]) {
					break;
				}
				lastUsedIdx++;
			}

			if (lastUsedIdx > con_num) {
				tab_num = j;
				con_num = lastUsedIdx;
			}
		}


		//for (int j = 0; j < n; j++) {
		//	bool used = false;
		//	for (int l = i+1; l < k; l++) {
		//		// 쓰는 순서가 가장 나중이거나 / 사용되지 않는 콘센트
		//		if (tab[j] == list[l] && con_num < l) {
		//			con_num = l;
		//			tab_num = j;
		//			used = true;
		//		}
		//	}

		//	if (!used) {
		//		tab_num = j;
		//		pass = true;
		//		break;
		//	}
		//}

		tab[tab_num] = list[i];
		answer++;
	}
	
	cout << answer;
}



void b11047(){
	int n, k;
	vector<int> coin;
	int answer = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}

	sort(coin.begin(), coin.end(), greater<int>());

	int idx = 0;

	while (k != 0) {
		answer += k / coin[idx];
		k = k % coin[idx];

		idx++;
	}

	cout << answer;
}


void b11000(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int answer = 0;
	bool used[200001] = {false,};
	vector<pair<int,int>> v;
	//priority_queue<vector<int>,vector<int>,greater<vector<int>>()> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	sort(v.begin(),v.end());

	//queue<pair<int,int>> q;

	//q.push(make_pair(v.front().first,v.front().second));
	used[0] = true;

	for (int i = 1; i < n; i++)
	{
		if (!used[i]) {

			int start = v[i].first;
			int end = v[i].second;

			for (int j = i+1; j < n; j++)
			{
				if (!used[j] && end <= v[j].first){

					used[j] = true;

					start = v[j].first;
					end = v[j].second;
				}
			}

			answer++;
		}
	}

	cout << answer;
}


void b11000_2(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int answer = 0;
	priority_queue<int,vector<int>,greater<int>> q;

	cin >> n;
	vector<pair<int,int>> v(n);
	//v.resize(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i].first >> v[i].second;

	sort(v.begin(),v.end());
	q.push(v.front().second);


	for (int i = 1; i < n; i++)
	{
		int start = v[i].first;
		int end = v[i].second;

		if (q.top() <= start) 
			q.pop();
		q.push(end);
	}

	
	//for (int i = 1; i < n; i++)
	//{
	//	
	//	int start = v[i].first;
	//	int end = v[i].second;

	//	if (q.top() <= v[i].first) {
	//		q.pop();
	//		q.push(v[i].second);
	//	}
	//}


	cout << q.size();
}



void b1946(){
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		pair<int,int> p[100001];
		int answer = 0;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> p[j].first >> p[j].second;
		}

		sort(p, p+n);

		int higher_score = 999999;
		for (int j = 0; j < n; j++) {
			if (p[j].second < higher_score) {
				answer ++;
				higher_score = p[j].second;
			}
		}

		cout << answer << endl;
	}

	
}


void b12845(){
	int n;
	//vector<int> v;
	priority_queue<int, vector<int>, less<int>> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		//v.push_back(tmp);
		q.push(tmp);
	}

	//sort(v.begin(),v.end(),greater<int>());

	int answer = 0;
	//int card = v.front();
	//q.push(v.front());
	int now_card = q.top();
	q.pop();

	while (!q.empty()) {
		int next_card = q.top();
		int gold = now_card + next_card;
		answer += gold;
		q.pop();
		
		q.push(max(now_card,next_card));
		now_card = q.top();
		q.pop();
	}

	cout << answer;
}




void b1931(){
	int n;
	int answer = 1;
	cin >> n;
	pair<int,int> p[100001];
	
	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
	}

	sort(p, p+n);

	int last_time = p[0].first;
	for (int i = 1; i < n; i++) {
		if (p[i].second >= last_time){
			answer++;
			last_time = p[i].first;
		}
	}

	cout << answer;
}



void b1969(){
	int n, m;
	string DNA[1001];
	int frequency[1001][5] = {0,}; // TGCA
	char elem[4] = {'T','G','C','A'};
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> DNA[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (DNA[i][j] == 'T') frequency[j][0]++;
			else if (DNA[i][j] == 'G') frequency[j][1]++;
			else if (DNA[i][j] == 'C') frequency[j][2]++;
			else if (DNA[i][j] == 'A') frequency[j][3]++;
		}
	}

	string answer = "";
	int Hamming_Distance = 0;
	for (int i = 0; i < m; i++) {
		int sum = 0;
		int max = -1;
		int max_idx;
		for (int j = 0; j < 4; j++) {
			sum += frequency[i][j];
			if (frequency[i][j] >= max) {
				max = frequency[i][j];
				max_idx = j;
			}
		}

		Hamming_Distance += sum - max;
		answer += elem[max_idx];
	}

	cout << answer << endl << Hamming_Distance;
}


double map_p[30][30];
bool b1405_visited[30][30];
double b1405_p[4];
int b1405_n;

void b1405_dfs(int x, int y, int cnt){	
	if (cnt == b1405_n) return;

	int dx[4] = {0,-1,0,1}; // 동 남 서 북
	int dy[4] = {1,0,-1,0};

	b1405_visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if (nx <= -30 || ny <= -30 || nx >= 30 || ny >= 30) continue;
		if (b1405_visited[nx][ny]) continue;

		else {
			map_p[nx][ny] = map_p[x][y] * b1405_p[i];
			b1405_dfs(nx,ny,cnt+1);
		}
	}
	b1405_visited[x][y] = false;
	return;
}


void b1405(){

	cin >> b1405_n;
	cin >> b1405_p[0] >> b1405_p[2] >> b1405_p[1] >> b1405_p[3];
	for (int i = 0; i < 4; i++)
		b1405_p[i] *= 0.01;
	
	//for (int i = 0; i < 15; i++)
	//	for (int j = 0; j < 15; j++)
	//		map_p[i][j] = 1;
	
	//map_p[14][14] = 1;
	//b1405_visited[14][14] = true;
	
	map_p[14][14] = 1.0;
	b1405_dfs(14,14,0);

	double answer = 0;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << (float)map_p[i][j] << " ";
			//answer += map_p[i][j];
		}
		cout << endl;
	}

	//cout << answer;
}




void b1920() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	vector<int> a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(),a.end());
	//sort(b.begin(),b.end());

	for (int i = 0; i < m; i++){
		
		int start = 0;
		int end = m-1;
		int mid;

		int exist = 0;
		
		while (start <= end) {
			mid = (start + end) / 2;

			if (a[mid] == b[i]) {
				exist = 1;
				break;
			}
			else if (a[mid] > b[i]) 
				end = mid - 1;
			else //if (a[mid] < b[i]) 
				start = mid + 1;
		}
		
		cout << exist << endl;
	}
}


int a[100001];

int b1920_2_binarySearch(int start, int end, int target){

	while (end - start >= 0) {
		int mid = (start + end) / 2;

		if (a[mid] == target) 
			return 1;
		
		else if (a[mid] > target) 
			end = mid - 1;
		else 
			start = mid + 1;
	}
	
	return 0;
}

void b1920_2() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;

	scanf("%d",&n);
	for (int i = 0; i < n; i++) 
	    scanf("%d",&a[i]);


	sort(a,a+n);
	//sort(b.begin(),b.end());
	
	scanf("%d",&m);
	for (int i = 0; i < m; i++){
		int tmp;
	    scanf("%d",&tmp);

		int answer = b1920_2_binarySearch(0,n-1,tmp);
        printf("%d\n",answer);
	}
    
}





int cards[500001];
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ybook2006&logNo=221567661537
//배열로 인한 메모리 초과시 해결방법 / test dword ptr [eax],eax ; probe page /
//전역변수로 빼버리기
void b10816(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cards[i];

	sort(cards, cards+n);

	cin >> m;

	int num;
	for (int i = 0; i < m; i++){
		cin >> num;

		auto left = lower_bound(cards,cards+n,num);
		auto right = upper_bound(cards,cards+n,num);

		cout << right - left << " ";
	}
	
	//return 0;
}


vector<long long> lan;
long long b1654_answer = -1;
void b1654_BS(int start, int end, int target){

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < (int)lan.size(); i++) // lan.size(); i++)
			sum += lan[i]/mid;

		if (sum >= target) {
			if (mid > b1654_answer) b1654_answer = mid;
			start = mid + 1;
		}
		else {// sum < target
			end = mid - 1;
		}
	}
}

void b1654(){
	//이해를 위한 테스트 케이스
	//4 11
	//831
	//743
	//457
	//539
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n, k;
	long long tmp;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		lan.push_back(tmp);
	}
	sort(lan.begin(),lan.end());

	b1654_BS(1,lan[n-1],k);

	cout << b1654_answer;

}




void b2805(){
	int n, m;
	int answer = -1;
	vector<int> tree;

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		tree.push_back(tmp);
	}

	sort(tree.begin(),tree.end());

	int start = 0;
	int end = tree[n-1];
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			//sum += tree[i] - mid;
			tree[i] - mid < 0 ? sum : sum += tree[i] - mid;

		if (sum >= m) {
			if (mid > answer) {
				answer = mid;
				start = mid + 1;
			}
		}
		else 
			end = mid - 1;
	}

	cout << answer;
}






int parent[32001];


int findParent(int x){
	if (x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}


//bool b1197_cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
//	return a.second.second < b.second.second;
//}

void b1197(){
	int v,e;
	int answer = 0;

	cin >> v >> e;
	vector<pair<int,pair<int,int>>> vv;
	for (int i = 0; i < e; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		//vv.push_back(make_pair(a,make_pair(b,c)));
		vv.push_back(make_pair(c,make_pair(a,b)));
	}

	sort(vv.begin(),vv.end());


	for (int i = 0; i <= v; i++) 
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int cost = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;

		if (findParent(a) != findParent(b)) {
			unionParent(a,b);
			answer += cost;
		}
	}

	cout << answer;
}




void b2252(){
	int n,m;
	vector<int> answer;
	vector<vector<int>> v(100001);
	int indegree[100001] = {0,};

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		answer.push_back(now);

		for (int i = 0; i < v[now].size(); i++)
		{
			indegree[v[now][i]]--;

			if (indegree[v[now][i]] == 0)
				q.push(v[now][i]);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

}


void b10818(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	//vector<int> v;
	int v[1000001];

 	cin >> n;
	for (int i = 0; i < n; i++)
	{
		//int tmp;
		//cin >> tmp;
		//v.push_back(tmp);
		cin >> v[i];
	}

	//sort(v.begin(),v.end());
	sort(v,v+n);
	//cout << v.front() << " " << v.back();
	cout << v[0] << " " << v[n-1];

}



vector<int> getPi(string ptn){

	vector<int> Pi(ptn.size(),0);

	int j = 0;

	for (int i = 1; i < ptn.size(); i++) {

		while (j > 0 && ptn[i] != ptn[j])
			j = Pi[j-1];

		if (ptn[i] == ptn[j])
			Pi[i] = ++j;
	}

	return Pi;
}


void b16916(){
    int answer = 0;
	string src, ptn;
	cin >> src >> ptn;

	vector<int> Pi = getPi(ptn);

	int j = 0;
	for (int i = 0; i < src.size(); i++) {

		while (j > 0 && src[i] != ptn[j]) 
			j = Pi[j-1];

		if (src[i] == ptn[j]) {
			if (j == ptn.size() - 1) answer = 1;
			j = Pi[j];
		}
		else j++;
	}
	
    cout << answer;

}



vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m); // partial match table

	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}



vector<int> getPi_2(string& ptn) {
	int size = ptn.size();
	vector<int> Pi(size,0);
	int i = 1 ;  // i
	int j = 0; // j

	while (i <= size) {
		if (ptn[i] == ptn[j]){
			Pi[i] = j+1;
			i++;
			j++;
		}
		else {
			if (j == 0)
				i++;
			else
				j = Pi[j-1];
		}
	}
	return Pi;
}

vector<int> makePi(string& ptn){
	vector<int> Pi(ptn.size(),0);

	int j = 0;
	for (int i = 1; i < ptn.size(); i++){
		while (j > 0 && ptn[i] != ptn[j]){
			j = Pi[j-1];
		}
		if (ptn[i] == ptn[j])
			Pi[i] == ++ j;
	}

	return Pi;
}

void b16916_2(){
	int answer = 0;
	string src, ptn;
	cin >> src >> ptn;

	vector<int> Pi = makePi(ptn);//getPi_2(ptn);
	
	
	int j = 0;
	for (int i = 0; i < src.size(); i++) {
		while (j > 0 && src[i] != ptn[j]){
			j = Pi[j-1];
		}
		if (src[i] == ptn[j]){
			if (j == ptn.size()-1){ // 모두 탐색했다면
				cout << 1;
				return;
			}
			else
				j++;
		}
	}

	cout << 0;
	return;
}




void b2693(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<int> v;
		int tmp;
		for (int i = 0; i < 10; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(),v.end(),greater<int>());

		cout << v[2] << "\n";
	}
}

void b3460(){
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		vector<int> v;

		while (tmp > 0)
		{
			int bit = tmp % 2;
			tmp = tmp/2;

			v.push_back(bit);
		}
	}
}





void p43238(){
	
	int nn = 6;
	vector<int> times;

	long long n = nn;
    long long answer = 999999999999999999;
    
    sort(times.begin(),times.end());
    
    if(n == 1){
        //return times.front();
    }
    
    long long start = 1;
    long long end = times.front() * n;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        
        long long sum = 0;
        long long time = 0;
        for (int i = 0; i < times.size(); i++){
            sum += (mid/times[i]);
            if ((mid/times[i]) * times[i] > time)
                time = (mid/times[i]) * times[i];
        }
        
        if (sum >= n) {
            if (answer > time)
                answer = time;
            end = mid-1;
        }
        else
            start = mid+1;
        
    }
    
    
    
    //return answer;
}





void p49189(){
	int n = 6;
	vector<vector<int>> edge;
    int answer = 0;

	vector<int> tmp1;
	tmp1.push_back(3);
	tmp1.push_back(6);
	edge.push_back(tmp1);

	vector<int> tmp2;
	tmp2.push_back(4);
	tmp2.push_back(3);
	edge.push_back(tmp2);

	vector<int> tmp3;
	tmp3.push_back(3);
	tmp3.push_back(2);
	edge.push_back(tmp3);

	vector<int> tmp4;
	tmp4.push_back(1);
	tmp4.push_back(3);
	edge.push_back(tmp4);

	vector<int> tmp5;
	tmp5.push_back(1);
	tmp5.push_back(2);
	edge.push_back(tmp5);

	vector<int> tmp6;
	tmp6.push_back(2);
	tmp6.push_back(4);
	edge.push_back(tmp6);

	vector<int> tmp7;
	tmp7.push_back(5);
	tmp7.push_back(2);
	edge.push_back(tmp7);
    
    vector<vector<int>> v(20001);
    queue<int> q;
    bool visited[20001] = {false,};
    int cost[20001];
    
    //cout << edge[0][0];
    
    for (int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    cost[1] = 0;
    visited[1] = true;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < v[now].size(); i++){
            int next = v[now][i];
            if (!visited[next]){
                visited[next] = true;
                
                q.push(next);
                cost[next] = cost[now] + 1;
            }
        }
    }
    
    //for (int i = 0; i < n; i++)
    //    cout << cost[i] << endl;
    
    sort(cost, cost+n, greater<int>());
    
    for (int i = 0; i < n; i++)
        if (cost[i] == cost[0]) answer++;
    
    
    //return answer;

}





void b2609_2(){
	int a, b;
	cin >> a >> b;

	int lcm = (a * b);
	int mod;

	while (b > 0)
	{
		mod = a % b;
		a = b;
		b = mod;
	}

	 lcm /= a;
	cout << a << "\n" << lcm;

}







void b2501(){
	int n, k;
	cin >> n >> k;

	vector<int> v;

	for (int i = 1; i <= n; i++)
	{
		if ( n % i  == 0 ) v.push_back(i);
	}

	if (k > v.size()) cout << 0;

	cout << v[k-1];
}




void b3460_2(){
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		//vector<int> v;
		int count = 0;

		while (n > 1)
		{
			if (n % 2 == 1) cout << count << " ";
			//v.push_back(n % 2);
			n = n / 2;
			count++;
		}
		
		//if (n % 2 == 1) cout << count;
		if (n == 1) cout << count;

		//v.push_back(n);

		cout << "\n";
	}
}




void b49191(){
	int n;
	vector<vector<int>> results;
    int answer = 0;

}






int cabbage[51][51] = {0,};
bool b1012_visited[51][51] = {false,};

void b1012_dfs(int x, int y, int n, int m){

	b1012_visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (cabbage[nx][ny] == 1 && !b1012_visited[nx][ny]){
				b1012_dfs(nx,ny,n,m);
			}
	}

}


void b1012_bfs(int x, int y, int n, int m){

	queue<pair<int,int>> q;
	q.push(make_pair(x,y));

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		b1012_visited[x][y] = true;


		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (cabbage[nx][ny] == 1 && !b1012_visited[nx][ny]){
				q.push(make_pair(nx,ny));
				b1012_visited[nx][ny] = true;
			}

		}
	}

	return;

}


void b1012(){

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int answer = 0;
		int m, n, k;

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> b >> a;
			cabbage[a][b] = 1;
		}

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (!b1012_visited[j][l] && cabbage[j][l] == 1){ 
					//b1012_bfs(j, l, n, m);
					b1012_dfs(j, l, n, m);
					answer ++;
				}
			} 
		}

		cout << answer << "\n";
	}
	
}












// 동작은 하지만 너무 오래 걸림
vector<int> b16953_arr(100000000);
void b16953_dfs(int a, int b){
	if (a > b) return;
	else {
		if (b16953_arr[a*2] < b16953_arr[a] + 1){
			b16953_arr[a*2] = b16953_arr[a] + 1;
			b16953_dfs(a*2,b);
		}

		int tmp = (a*10) + 1;
		if (b16953_arr[tmp] < b16953_arr[a] + 1){
			b16953_arr[tmp] = b16953_arr[a] + 1;
			b16953_dfs(tmp,b);
		}
	}
}

int min_sum = 999999999;
void b16953_dfs_2(long long a, long long b, int count){

	if (a > b) return;
	if (a == b) min_sum = min(min_sum,count);
	
	b16953_dfs_2(a*2, b, count+1);
	b16953_dfs_2(a*10+1, b, count+1);
}


//거꾸로 생각해서 풀기
int b16953_sol(int a, int b){
	int count = 0;

	while (true)
	{
		if (a == b) break;
		if (a > b) return -1;

		if (b % 2 == 0) b = b/2;
		else if (b % 10 == 1) b = (b - 1) / 10;
		else return -1;

		count ++;
	}

	return count + 1;
}



int b16953_bfs(long long a, long long b){
	queue<pair<long long,long long>> q;

	q.push(make_pair(a,1));
	while (!q.empty())
	{
		long long n = q.front().first;
		long long cnt = q.front().second;
		q.pop();

		if (n == b)	return cnt;
		else {

			if (n*2 <= b)
				q.push(make_pair(n*2, cnt+1));
			if (n*10 + 1 <= b)
				q.push(make_pair(n*10 + 1, cnt+1));

		}
	}

	return -1;
}



void b16953(){

	long long a, b;
	cin >> a >> b;

	// DFS 풀이_1
	//b16953_dfs_2(a,b,1);
	//if (min_sum == 999999999) cout << -1;
	//else cout << min_sum;


	// DFS 풀이_2 : 동작은 하지만 너무 오래 걸림
	//for (int i = 0; i < b16953_arr.size(); i++)
	//	b16953_arr[i] = 0;
	//
	//b16953_dfs(a,b);
	//if (b16953_arr[b] == 0) cout << -1;
	//else cout << b16953_arr[b]+1;
	

	// 거꾸로 생각해서 풀기
	//cout << b16953_sol(a,b);


	// BFS 풀이
	cout << b16953_bfs(a,b);
}







int b2667_arr[26][26];
bool b2667_visited[26][26] = {false,};

int b2667_dfs(int x, int y, int n, int cnt){
	
	b2667_visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		
		if(!b2667_visited[nx][ny] && b2667_arr[nx][ny] == 1)
			cnt = b2667_dfs(nx,ny,n,cnt+1);
	}

	return cnt;
}

void b2667(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++)
			b2667_arr[i][j] = tmp[j]-'0';
	}

	int answer = 0;
	vector<int> v;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (!b2667_visited[i][j] && b2667_arr[i][j] == 1){
				v.push_back(b2667_dfs(i,j,n,1));
				answer ++;
			}
		}
	}

	cout << answer << "\n";

	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	
}






bool b11724_visited[1001] = {false,};
void b11724_dfs(int a, vector<vector<int>> v){

	b11724_visited[a] = true;

	for (int i = 0; i < v[a].size(); i++)
	{
		int next = v[a][i];
		if (!b11724_visited[next])
			b11724_dfs(next,v);
	}
}

void b11724(){
	int n,m;
	int answer = 0;
	vector<vector<int>> v(1001);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!b11724_visited[i]){
			b11724_dfs(i,v);
			answer++;
		}
		
	}

	cout << answer;
}





void b1038(){
	int n;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	cin >> n;

	n = n - 9;

	int num = 1;
	while (n > 9)
	{
		int num_tmp = num % 10;
		int add = 0;
		for (int i = 0; i < num_tmp; i++)
			add += arr[i];

		n = n - (add);
		
		arr[num_tmp] = num_tmp;
		num++;
	}

}

void b1038_2(){
	int n;
	long long arr[1000001] = {0,1,2,3,4,5,6,7,8,9,0};
	cin >> n;

	int tmp = 10;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i]%10; j++) {
			arr[tmp] = arr[i]*10 + j;
			tmp++;
		}
	}

	if (n != 0 && arr[n] == 0) cout << -1;
	else cout << arr[n];
}





int b17070_n;
int house[17][17];


bool check_house(int x, int y){
	if (house[x][y] == 0 && x <= b17070_n && y <= b17070_n)
		return true;
	else
		return false;
}

int b17070_dfs(int x, int y, char s){
	
	//if (x > b17070_n || y > b17070_n) return 0;
	if (x == b17070_n && y == b17070_n) return 1;

	int answer = 0;
	
	//bool h_check = (house[x][y+1] == 0 && (x <= b17070_n && y+1 <= b17070_n));
	//bool v_check = (house[x+1][y] == 0 && (x+1 <= b17070_n && y <= b17070_n));
	//bool d_check = (house[x+1][y+1] && (x+1 <= b17070_n && y+1 <= b17070_n) && h_check && v_check);

	bool down = check_house(x+1,y);
	bool right = check_house(x,y+1);
	bool diagonal = check_house(x+1,y+1);

	if (s == 'h'){
		//if (house[x][y] == 1) return 0;
		if (right) answer += b17070_dfs(x,y+1,'h');
		if (right && down && diagonal) answer += b17070_dfs(x+1,y+1,'d');
	}
	else if (s == 'v'){
		//if (house[x][y] == 1) return 0;
		if (down) answer += b17070_dfs(x+1,y,'v');
		if (right && down && diagonal) answer += b17070_dfs(x+1,y+1,'d');
	}
	else if (s == 'd'){
		//if (house[x][y] || house[x-1][y] || house[x][y-1]) return 0;
		if (right) answer += b17070_dfs(x,y+1,'h');
		if (down) answer += b17070_dfs(x+1,y,'v');
		if (right && down && diagonal) answer += b17070_dfs(x+1,y+1,'d');
	}

	return answer;
}


void b17070(){
	cin >> b17070_n;
	for (int i = 1; i <= b17070_n; i++) {
		for (int j = 1; j <= b17070_n; j++) {
			cin >> house[i][j];
		}
	}
	// 'h' 가로 'v' 세로 'd' 대각선

	cout << b17070_dfs(1,2,'h');


}




void b1495(){
	int n,s,m;
	int answer = -1;
	vector<int> v(101);
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	queue<pair<int,int>> q;
	q.push(make_pair(s,0));

	while (!q.empty())
	{
		int vol = q.front().first;
		int idx = q.front().second;
		q.pop();

		

		if (idx == n) {
			if (answer < vol) answer = vol;
			continue;
		}
		if (vol + v[idx+1] <= m) q.push(make_pair(vol+v[idx+1],idx+1));
		if (vol - v[idx+1] >= 0) q.push(make_pair(vol-v[idx+1],idx+1));

	}

	cout << answer;
}


void b1495_2(){

	bool DP[101][1001] = {false,};
	int n,s,m;
	int answer = -1;
	vector<int> v(101);
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	DP[0][s] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (DP[i][j]) {
				if (j + v[i+1] <= m) DP[i+1][j + v[i+1]] = true;
				if (j - v[i+1] >= 0) DP[i+1][j - v[i+1]] = true;
			}
		}
	}

	for (int i = m; i >= 0; i--) {
		if (DP[n][i]) {
			answer = i;
			break;
		}
	}

	cout << answer;
}



void b15486(){
	int n;
	vector<pair<int,int>> v;
	vector<int> cost(1500001,0);
	//int cost[1500001] = {0,};

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		if (v[i].first + i -1 >= n) continue;
		else {
			//cost[i] = v[i].second;
			int tmp = 0;
			for (int j = 1; j < v[i].first; j++) {
				//tmp += v[i+j-1].second;
				tmp += cost[i+j];
			}

			if (v[i].second > tmp) {
				answer -= tmp;
				answer += v[i].second;
				cost[i] = v[i].second;

				for (int j = 1; j < v[i].first; j++) {
				cost[i+j] = 0;
				}
			}
			//else
			//	cost[i] = 0;
		}
	}

	cout << answer;
}


void b15486_2(){
	// 점화식 이용
	int n;
	int answer = 0;
	vector<pair<int,int>> v;
	vector<int> dp(1500001,0);
	//int cost[1500001] = {0,};

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	for (int i = 0; i < n; i++) {
		dp[v[i].first + i] = max(dp[v[i].first + i],dp[i]+v[i].second);
		dp[i+1] = max(dp[i+1], dp[i]);
	}

	answer = dp[n];
	cout << answer;
}


void b15486_3(){
	// 원래 코드 약간 변형
	int n;
	vector<pair<int,int>> v;
	vector<int> cost(1500001,0);
	//int cost[1500001] = {0,};

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	int answer = 0;
	for (int i = n-1; i >= 0; i--) {
		if (v[i].first + i -1 >= n) {
			cost[i] = cost[i+1];
			answer = max(answer,cost[i]);
		}
		else {
			cost[i] = max(cost[i+1], v[i].second + cost[i+v[i].first]);
			answer = max(answer, cost[i]);
		}
	}

	cout << answer;
}


void b1890(){
	int n;
	int answer = 0;
	int arr[101][101];
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	if (arr[0][0] == 0) {
		cout << answer;
		return;
	}

	long long dp[101][101] = {0,};
	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n-1 && j == n-1) continue;
			if (dp[i][j] == 0) continue;
			//if (arr[j][j] == 0) continue;

			int tmp = arr[i][j];
			if (i+tmp < n) dp[i+tmp][j] = dp[i+tmp][j] + dp[i][j];
			if (j+tmp < n) dp[i][j+tmp] = dp[i][j+tmp] + dp[i][j];
		}
	}

	answer = dp[n-1][n-1];

	cout << answer;
	return;
}




void b12026(){
	int n;
	int answer = -1;
	int dp[1001];
	fill_n(dp,1001,99999999);
	string str;
	cin >> n >> str;

	//vector<vector<int>> v;
	//for (int i = 0; i < str.size(); i++)
	//{
	//	if (str[i] == 'B') v[0].push_back(i);
	//	else if (str[i] == 'O') v[1].push_back(i);
	//	else if (str[i] == 'J') v[2].push_back(i);
	//}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (dp[i] == 99999999) continue;
		char next;
		if (str[i] == 'B') next = 'O';
		if (str[i] == 'O') next = 'J';
		if (str[i] == 'J') next = 'B';

		for (int j = i+1; j < n; j++) {
			if (str[j] == next) 
				dp[j] = min(((j-i)*(j-i)) + dp[i], dp[j]);

		}
	}

	if (dp[n-1] != 99999999) answer = dp[n-1]-1;
	cout << answer;
}




void b11058(){
	//https://100100e.tistory.com/156
	//https://wookiist.dev/123
	int n;
	cin >> n;
	int dp[101];
	

}




int dp[2001][2001] = {false,};

void b10942(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	vector<int> v(2001);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = 1; i <= n; i++) {
		dp[i][i] = true;
	}

	for (int i = 1; i < n; i++) {
		if (v[i] == v[i+1]) 
			dp[i][i+1] = true;
	}
	
	for (int j = 3; j <= n; j++) {
		for (int i = 1; i <= n-j+1; i++) {
			if (v[i] == v[j+i-1] && dp[i+1][j+i-2])
				dp[i][j+i-1] = true;
		}
	}

	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		cout << dp[a][b] << "\n";
	}
}


bool comppp(int a, int b){
	return a < b;
}

void b11066(){
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int answer = 0;
		int k;
		cin >> k;
		vector<int> v;

		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		priority_queue<int, vector<int>, greater<int>> qqq(v.begin(),v.end());

		while (!qqq.empty())
		{
			int a = qqq.top();
			qqq.pop();
			if (qqq.empty()) {
				break;
			}
			int b = qqq.top();
			qqq.pop();

			qqq.push(a+b);
			answer += a+b;
		}

		cout << answer << "\n";
	}
}


void b11066_2(){	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int answer = 0;
		int k;
		cin >> k;
		vector<int> v;

		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		




		cout << answer << "\n";
	}

}



int wall_visited[1001][1001] = {0,};
int wall_arr[1001][1001];
int wall_n, wall_m;
int wall_answer = 99999999;

void b2206_dfs(int x, int y, bool wall_punch, int cost){

	wall_visited[x][y] = true;

	if(x == wall_n-1 && y == wall_m-1) {
		if (wall_answer > cost) wall_answer = cost;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (wall_visited[nx][ny] || nx < 0 || ny < 0 || nx >= wall_n || ny >= wall_m)
			continue;

		
		//가려는 곳이 막혀 있고 벽 부수기 불가능할 때
		if (wall_arr[nx][ny] && wall_punch)
			continue;
		//가려는 곳이 막혀 있고 벽 부수기 가능할 때
		else if (wall_arr[nx][ny] && !wall_punch) {
			wall_arr[nx][ny] = 0;
			b2206_dfs(nx, ny, true,cost+1);
			wall_arr[nx][ny] = 1;
			wall_visited[nx][ny] = false;
		}
		//가려는 곳이 안 막혀 있을 때
		else if (!wall_arr[nx][ny]) {
			b2206_dfs(nx, ny, wall_punch,cost+1);
			wall_visited[nx][ny] = false;
		}
		

	}

}

void b2206(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> wall_n >> wall_m;

	for (int i = 0; i < wall_n; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < wall_m; j++)
			wall_arr[i][j] = tmp[j] - '0';
	}

	b2206_dfs(0,0,false,0);

	if (wall_answer == 99999999) cout << -1;
	else cout << wall_answer+1;
}


void b2206_2(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> wall_n >> wall_m;

	for (int i = 0; i < wall_n; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < wall_m; j++)
			wall_arr[i][j] = tmp[j] - '0';
	}

	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push(make_pair(make_pair(0,0),make_pair(0,1)));
	wall_visited[0][0] = 1;


	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall_punch = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();

		if (x == wall_n-1 && y == wall_m-1 && wall_answer > cost) {
			wall_answer = cost;
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (wall_visited[nx][ny] || nx < 0 || ny < 0 || nx >= wall_n || ny >= wall_m)
				continue;

			
			if (wall_arr[nx][ny] && !wall_punch) {//가려는 곳이 막혀 있고 벽 부수기 가능할 때
				q.push(make_pair(make_pair(nx,ny),make_pair(2,cost+1)));
				wall_visited[nx][ny] = 2;
			}

			else if (!wall_arr[nx][ny] && wall_punch != 1) {//가려는 곳이 안 막혀 있을 때
				q.push(make_pair(make_pair(nx,ny),make_pair(wall_punch,cost+1)));
				wall_visited[nx][ny] = 1;
			}
			
			//else if (wall_arr[nx][ny] && wall_punch) //가려는 곳이 막혀 있고 벽 부수기 불가능할 때
			//	continue;
		}
	}

	
	if (wall_answer == 99999999) cout << -1;
	else cout << wall_answer;
}



int wall_visited_3[1001][1001][2];

void b2206_3(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> wall_n >> wall_m;

	for (int i = 0; i < wall_n; i++){
		string tmp;
		cin >> tmp;
		for (int j = 0; j < wall_m; j++)
			wall_arr[i][j] = tmp[j] - '0';
	}

	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push(make_pair(make_pair(0,0),make_pair(0,1)));
	wall_visited_3[0][0][0] = 1;


	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall_punch = q.front().second.first;
		int cost = q.front().second.second;
		q.pop();

		if (x == wall_n-1 && y == wall_m-1 && wall_answer > cost) {
			wall_answer = cost;
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= wall_n || ny >= wall_m)
				continue;

			
			if (wall_arr[nx][ny] && !wall_punch) {
				//갈 수 없는 길이고 벽 부수기 가능할 때
				q.push(make_pair(make_pair(nx,ny),make_pair(wall_punch+1,cost+1)));
				wall_visited_3[nx][ny][wall_punch+1] = 1;
			}

			else if (!wall_arr[nx][ny] && !wall_visited_3[nx][ny][wall_punch]) {
				//갈 수 있는 길이고, 현재 상태로 방문하지 않았다면
				q.push(make_pair(make_pair(nx,ny),make_pair(wall_punch,cost+1)));
				wall_visited_3[nx][ny][wall_punch] = 1;
			}
			
			//else if (wall_arr[nx][ny] && wall_punch) //가려는 곳이 막혀 있고 벽 부수기 불가능할 때
			//	continue;
		}
	}

	
	if (wall_answer == 99999999) cout << -1;
	else cout << wall_answer;
}



void b1476(){
	int e, s, m;
	cin >> e >> s >> m;

	int n = 1;
	while (true) {
		if ((n - e) % 15 == 0 && (n - s) % 28 == 0 && (n - m) % 19 == 0)
			break;
		n++;
	}

	cout << n;
}




void b1107(){
	int answer = 0;
	int button[11] = {0,};
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		button[tmp] = 1;
	}

	if (n == 100) {
		cout << 0;
		return;
	}

	int nn = n;
	int res = 0;
	int mod = 100000;
	while (mod > 0)
	{
		int now = nn / mod;

		if (button[now]) {
			for (int j = 0; j < 11; j++) {
				if (!button[now+j+1] && now+j+1 < 10) {
					res += (now+j+1) * mod;
					break;
				}
				else if (!button[now-j-1] && now-j-1 > 0) {
					res += (now-j-1) * mod;
					break;
				}
			}
		}
		else
			res += now * mod;

		nn = nn % mod;
		mod /= 10;
	}

	string s = to_string(n);

	answer += res - n + s.size();
	

	cout << answer;
}


void b1107_2(){
	int answer = 0;
	int button[11] = {0,};
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		button[tmp] = 1;
	}

	int res = 0;
	int ii = 1;
	while (true)
	{
		int plus = n + ii;
		int minus = n - ii;

		string str_p = to_string(plus);
		string str_m = to_string(minus);


		bool ch1 = true;
		for (int i = 0; i < str_p.size(); i++) {
			for (int j = 0; j < 11; j++) {
				if (button[str_p[i]-'0']) {
					ch1 = false;
					continue;
				}
			}
		}

		if (ch1) {
			res = plus;
			break;
		}
		
		if (minus > 0){
			bool ch2 = true;
			for (int i = 0; i < str_m.size(); i++) {
				for (int j = 0; j < 11; j++) {
					if (button[str_m[i]-'0']) {
						ch2 = false;
						continue;
					}
				}
			}

			if (ch2) {
				res = minus;
				break;
			}
		}

		ii++;
	}

	if (!res){
		string tmp = to_string(res);
		answer = n - res + tmp.size();
	}
	cout << answer;

}



void b1107_3(){
	int brokenButton[11] = {0,};
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		brokenButton[tmp] = 1;
	}
	
	int answer = abs(n-100);
	for (int i = 0; i < 1000001; i++) {
		string tmp_i = to_string(i);
		bool isPossible = true; 

		for (int j = 0; j < tmp_i.size(); j++) {
			if (brokenButton[tmp_i[j] - '0']) isPossible = false;
		}

		if (isPossible){
			int asnwer_tmp = abs(n - i) + tmp_i.size();
			if (asnwer_tmp < answer) 
				answer = asnwer_tmp;
		}
	}

	
	cout << answer;




	//string tmp = "0000000";
	//for (int a = 0; a < 10; a++) {
	//	if (brokenButton[a]) continue;
	//	tmp[0] = char(a);

	//	for (int b = 0; b < 10; b++) {
	//		if (brokenButton[b]) continue;
	//		tmp[1] = char(b);

	//		for (int c = 0; c < 10; c++) {
	//			if (brokenButton[c]) continue;
	//			tmp[2] = char(c);

	//			for (int d = 0; d < 10; d++) {
	//				if (brokenButton[d]) continue;
	//				tmp[3] = char(d);

	//				for (int e = 0; e < 10; e++) {
	//					if (brokenButton[e]) continue;
	//					tmp[4] = char(e);

	//					for (int f = 0; f < 10; f++) {
	//						if (brokenButton[f]) continue;
	//						tmp[5] = char(f);

	//						for (int g = 0; g < 10; g++) {
	//							if (brokenButton[g]) continue;
	//							tmp[6] = char(g);

	//							int asnwer_tmp = abs(n - stoi(tmp)) + to_string(stoi(tmp)).size();
	//							if (asnwer_tmp < answer) answer = asnwer_tmp;
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

}




void b1065(){
	int n;
	int answer = 0;

	cin >> n;

	int x = 1;
	while (x <= n) {
		string x_str = to_string(x);

		bool is_onenum = true;

		if (x_str.size() == 1 || x_str.size() == 2 ) {
			answer ++;
			x ++;
			continue;
		}

		int a = x_str[0] - '0';
		int b = x_str[1] - '0';
		int min = a-b;

		for (int i = 2; i < x_str.size(); i++) {
			int c = x_str[i] - '0';

			if (min != b-c) {
				is_onenum = false;
				break;
			}

			b = c;
			min = b-c;
		}

		if(is_onenum) answer ++;

		x ++;
	}

	cout << answer;

}




void b14501(){ //b15486
	
	int T[16];
	int P[16];
	int bene[16] = {0,};
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> T[i] >> P[i];

	for (int i = 0; i < n; i++) {

		if (T[i] + i <= n) 
			bene[T[i] + i] = max(bene[T[i] + i], P[i] + bene[i]);
		bene[i+1] = max(bene[i+1], bene[i]);
	}

	cout << bene[n];
}


int b14889_p[21][21] = {0,};
int team[22];// = {0,};
int b14889_n;
int b14889_answer = 9999999;

void b14889_dfs(int x, int cnt){

	if (cnt == b14889_n/2) {
		int start = 0;
		int link = 0;

		for (int i = 1; i <= b14889_n; i++) {
			for (int j = 1; j <= b14889_n; j++) {
				if (team[i] && team[j]) start += b14889_p[i][j];
				if (!team[i] && !team[j]) link += b14889_p[i][j];
			}
		}

		int min = start >= link ? start - link : link - start;
		if (b14889_answer > min) b14889_answer = min;

		return;
	}

	for (int i = x; i < b14889_n; i++)
	{
		team[i] = 1;
		b14889_dfs(x+1, cnt+1);
		team[i] = 0;
	}
}

void b14889(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> b14889_n;
	
	for (int i = 1; i <= b14889_n; i++) {
		for (int j = 1; j <= b14889_n; j++) {
			cin >> b14889_p[i][j];
		}
	}

	b14889_dfs(1,0);

	cout << b14889_answer;
}






void b10819_C(){
}


int b10819_check(int *arr, int n){
	int sum = 0;

	for (int i = 0; i < n-1; i++) {
		sum += abs(arr[i] - arr[i+1]);
	}

	return sum;
}


void b10819(){
	int n;
	int arr[9];
	int answer = -1;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//b10819_C();

	sort(arr,arr+n);

	do {
		//answer = max(answer, b10819_check(arr, n));
		int sum = 0;

		for (int i = 0; i < n-1; i++) 
			sum += abs(arr[i] - arr[i+1]);

		answer = max(answer, sum);

	} while (next_permutation(arr, arr+n));

	cout << answer;
}


int b2529_k;
int b2529_arr[10] = {0,};
int b2529_answer[10] = {0,};

void b2529_dfs(int idx){
	if (idx == k) return;

	for (int i = 9; i <= 0; i--) {
		if (b2529_arr[idx] + i <= 9){
			b2529_answer[idx] = b2529_arr[idx] + i;
			b2529_answer[idx+1] = b2529_arr[idx+1] + b2529_answer[idx];
			b2529_dfs(idx+1);
		}
	}

}

void b2529(){
	cin >> b2529_k;

	for (int i = 1; i <= b2529_k; i++){
		char tmp;
		cin >> tmp;
		if (tmp == '<') b2529_arr[i] = 1;
		if (tmp == '>') b2529_arr[i] = -1;
	}

	b2529_dfs(0);
}





char b2529_arr2[11];
bool b2529_visited[11] = {false,};
string b2529_max = "-1";
string b2529_min = "9999999999";


bool b2529_check(int idx){
	if (b2529_arr2[idx] == '<' && b2529_answer[idx] > b2529_answer[idx+1]) return false;
	if (b2529_arr2[idx] == '>' && b2529_answer[idx] < b2529_answer[idx+1]) return false;

	return true;
}

void b2529_dfs2(int cnt){
	if (cnt == b2529_k+1) {
		for (int i = 0; i < b2529_k; i++){
			if (!b2529_check(i)) 
				return;
		}
		
		
		string answer = "";
		for (int i = 0; i < b2529_k+1; i++)
			answer += to_string(b2529_answer[i]);

		if (stoi(b2529_min) > stoi(answer)) b2529_min = answer;
		if (stoi(b2529_max) < stoi(answer)) b2529_max = answer;

		cout << answer << endl;

		return;
	}

	for (int i = 0; i < 10; i++) {
		
		if (!b2529_visited[i]) {
			b2529_visited[i] = true;
			b2529_answer[cnt] = i;
			b2529_dfs2(cnt+1);
			b2529_visited[i] = false;
		}
	}
}


void b2529_2(){
	cin >> b2529_k;

	for (int i = 0; i < b2529_k; i++)
		cin >> b2529_arr2[i];

	b2529_dfs2(0);

	cout << b2529_max << "\n" << b2529_min;
}



vector<string> boo_list;
char sign[10];
int boo;
int boo_visited[10] = {0,};


bool checkBoo(string num){
	//bool okay = true;
	for (int i = 0; i < boo; i++) { // check
		if (sign[i] == '>' && num[i] < num[i+1]) return false;
		if (sign[i] == '<' && num[i] > num[i+1]) return false;
	}

	//if (okay) 
	//	boo_list.push_back(num);
	//}
    return true;
}

void getBoo(int cnt, string num){
	if (cnt == boo+1){
		if (checkBoo(num)) boo_list.push_back(num); // 부등호 성립하는지 확인 후 넣기
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!boo_visited[i]){
			boo_visited[i] = 1;
			//boo_tmp[cnt] = i;
			getBoo(cnt+1, num + to_string(i));
			boo_visited[i] = 0;
		}
	}
}


void b2529_3(){
	cin >> boo;
	for (int i = 0; i < boo; i++)
		cin >> sign[i];

	getBoo(0,"");
	

	//string max = "-1";
	//string min = "999999999";

	auto p = minmax_element(boo_list.begin(), boo_list.end());
	cout << *p.second << "\n" << *p.first;

	
	//if (okay){
	//	if (stoi(min) > stoi(boo_list[i])) min = boo_list[i];
	//	if (stoi(max) < stoi(boo_list[i])) max = boo_list[i];
	//}
	
	//cout << max << "\n" << min << "\n";
}


vector<int> ball_list;
int ball_tmp[3];
int ball_visited[10] = {0,};
int record[101][3]; // num, strike, ball

void getBall(int idx, int cnt){
	if (cnt == 4) {
		int tmp = ball_tmp[1]*100 + ball_tmp[2]*10 + ball_tmp[3]; 
		ball_list.push_back(tmp);
		return;
	}

	for (int i = 1; i < 10; i++) {

		if (!ball_visited[i]){
			ball_visited[i] = 1;
			ball_tmp[cnt] = i;
			getBall(i,cnt+1);
			ball_visited[i] = 0;
		}
	}
}

bool getSB(int ball, int num, int n){
	string ball_s = to_string(ball);
	string num_s = to_string(num);

	int S = 0;
	int B = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j && num_s[i] == ball_s[j]) S++; // strike
			if ((i != j && num_s[i] == ball_s[j])) B++; // ball
		}
	}
	
	if (record[n][1] == S && record[n][2] == B) 
		return true;
	else 
		return false;
}

void b2503(){

	getBall(1,1); // 세 자리 숫자 조합 구하기
	int answer = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> record[i][0] >> record[i][1] >> record[i][2];
	}

	for (int i = 0; i < ball_list.size(); i++) {
		bool pass = true;

		for (int j = 0; j < n; j++) {
			if (!getSB(ball_list[i], record[j][0], j)) pass = false;
		}

		if (pass) answer ++;
	}
	cout << answer;
}




vector<string> word;
//int alphabet_list[11];
int num_list[11]; // 알파벳에 대조할 숫자 조합
int num_visited[11] = {0,};
int numnum = 0; // 만들어야 할 숫자 조합 자릿수
int WordNum_max = -1;
int alphabet[27] = {0,}; // 0:A, 1:B, 2:C .., alphabet[0]는 A의 num_list 인덱스

void calWordNum(){
	int sum = 0;

	for (int i = 0; i < word.size(); i++) {
		string tmp = "";
		for (int j = 0; j < word[i].size(); j++){
			int idx = alphabet[word[i][j] - 65];
			tmp += to_string(num_list[idx]);
		}
		sum += stoi(tmp);
	}

	if (WordNum_max < sum) WordNum_max = sum;

	return;
}

void getWordNum(int cnt){
	if (cnt == numnum+1){ // 조합이 완성되면
		calWordNum();
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!num_visited[i]){
			num_visited[i] = 1;
			num_list[cnt] = i;
			getWordNum(cnt+1);
			num_visited[i] = 0;
		}
	}
}

void b1339(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		word.push_back(str);
		for (int j = 0; j < str.length(); j++) {
			if (alphabet[str[j] - 65] == 0) {
				numnum++;
				int tmp = str[j] - 65;
				alphabet[str[j] - 65] = numnum;
			}
		}
	}

	getWordNum(1);

	cout << WordNum_max;
}


void b1339_2(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		word.push_back(str);

		int val = 1;
		for (int j = str.length()-1; j >= 0 ; j--) {
			alphabet[str[j] - 65] += val;
			val *= 10;
		}
	}

	sort(alphabet, alphabet+26,greater<int>());

	int answer = 0;
	int val = 9;
	for (int i = 0; i < 26; i++) {
		answer += alphabet[i]*val;
		val--;
	}

	cout << answer;
}

int b9095_target;
int b9095_answer;
void b9095_dfs(int sum){
	int answer = 0;
	
	if (sum == b9095_target){
		b9095_answer ++;
		return;
	}
	else if (b9095_target < sum) {
		return;
	}

	b9095_dfs(sum+1);
	b9095_dfs(sum+2);
	b9095_dfs(sum+3);
}

void b9095(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b9095_target;
		b9095_answer = 0;

		b9095_dfs(0);
		cout << b9095_answer << "\n";
	}
}




int b10972_arr[10001];
int b10972_tmp[10001];
int b10972_visited[10001] = {0,};
int b10972_n;
int b10972_nowIdx = 0;
int b10972_nextIdx = 0;
long long b10972_maxIdx = 0;

void b10972_dfs(int cnt, int idx){
	if (cnt == b10972_n+1){
		b10972_nowIdx++;
		
		if ((long long)b10972_nowIdx == b10972_maxIdx) {
			cout << -1;
			exit(0);
		}
		if (b10972_nowIdx == b10972_nextIdx) {
			for (int i = 1; i <= b10972_n; i++)
				cout << b10972_tmp[i] << " ";
			exit(0);
		}

		bool match = true;
		for (int i = 1; i <= b10972_n; i++) {
			if (b10972_arr[i] != b10972_tmp[i]) 
				match = false;
		}
		if (match) b10972_nextIdx = b10972_nowIdx+1;
		return;
	}

	for (int i = 1; i <= b10972_n; i++) {
		if (!b10972_visited[i]){
			b10972_visited[i] = 1;
			b10972_tmp[cnt] = i;
			b10972_dfs(cnt+1, idx+1);
			b10972_visited[i] = 0;
		}

	}
}

void b10972(){

	cin >> b10972_n;
	for (int i = 1; i <= b10972_n; i++) 
		cin >> b10972_arr[i];

	b10972_maxIdx = 1;
	for (int i = 1; i <= b10972_n; i++)
		b10972_maxIdx *= i;

	b10972_dfs(1,1);
}





void b10972_2(){
	cin >> b10972_n;
	for (int i = 0; i < b10972_n; i++) 
		cin >> b10972_arr[i];

	if (next_permutation(b10972_arr, b10972_arr+b10972_n)){
		for (int i = 0; i < b10972_n; i++) {
			cout << b10972_tmp[i] << " ";
		}
		cout << "\n";
	}
	else
		cout << -1;

}



int b10973_arr[10001];
int b10973_n;

void b10973(){
	cin >> b10973_n;
	for (int i = 0; i < b10973_n; i++) 
		cin >> b10973_arr[i];

	if (prev_permutation(b10973_arr, b10973_arr+b10973_n)){
		for (int i = 0; i < b10973_n; i++) {
			cout << b10973_arr[i] << " ";
		}
		cout << "\n";
	}
	else
		cout << -1;
}




void navis01(){
	int n;
	int answer = 0;
	int answer_2 = 0;
	cin >> n;
	
	while (n > 1) {
		answer += n / 2;
		answer_2 += n % 2;
		n = n / 2 + n % 2; 
		//totalanswer + answer_2;
	}
	
	cout << answer << "," << answer_2;
	
}



void navis02(){
	int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	string week[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED",};
	int mon;
	int day;
	
	cin >> mon >> day;

	if (month[mon] < day) {
		cout << "ERROR";
		return;
	}

	int sum = 0;
	for (int i = 1; i < mon; i++){
		sum += month[i];
	}
	sum += day;
	
	cout << week[sum % 7];
}






void navis03(){
	string str;
	cin >> str;

	int i = 0;
	//while (i < str.size()){
	//	if (isdigit(str[i]) )
	//}
}

void navis05(){
	int n;
	vector<pair<int,int>> v;
	cin >> n;

	if(n < 1 || n > 10) { // 예외처리
		cout << -1;
		return;
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.size() > 3){
			cout << -1;
			return;
		}
		v.push_back(make_pair(str[0]-'0',str[2]-'0'));
		if( v[i].first > 8 || v[i].first < 0 || v[i].second > 8 || v[i].second < 1) { // 예외처리
			cout << -1;
			return;
		}
		//if (cin.eof()) {
		//	cout << -1;
		//	return;
		//}
	}


	sort(v.begin(),v.end());

	priority_queue<int, vector<int>, greater<int>> q;
	q.push(v.front().first + v.front().second);

	for (int i = 1; i < n; i++) {
		int start = v[i].first;
		int end = v[i].first+v[i].second;

		if (q.top() <= start)
			q.pop();
		q.push(end);
	}

	cout << q.size();
}


void navis06(){
	string first;
	string second;
	
	string answer = "";
	
	cin >> first >> second;

	string new_first = first;
	string new_second = second;


	int first_comma = -1;
	for (int i = 0; i < first.size(); i++) {
		if (first[i] == '.') {
			if (i < 19){ // 실수가 20개 이하라면 그만큼 0 채우기
				for (int j = 0; j < 20-i; j++){
					new_first = "0" + new_first;
				}
			}
			if (first.size() - i - 1< 10){
				int tmp = first.size() - i - 1;
				for (int j = 0; j < 10 - tmp; j++){
					new_first = new_first + "0";
				}
			}
			first_comma = i;
			new_first = new_first.substr(0,20) + new_first.substr(21,new_first.size());
		}
	}
	
	int second_comma = -1;
	for (int i = 0; i < second.size(); i++) {
		if (second[i] == '.') {
			if (i < 19){ // 실수가 20개 이하라면 그만큼 0 채우기
				for (int j = 0; j < 20-i; j++){
					new_second = "0" + new_second;
				}
			}
			if (second.size() - i - 1< 10){
				int tmp = first.size() - i - 1;
				for (int j = 0; j < 10 - tmp; j++){
					new_second = new_second + "0";
				}
			}
			second_comma = i;
			new_second = new_second.substr(0,20) + new_second.substr(21,new_second.size());
		}
	}

	cout << new_first << endl << new_second;

	int mod = 0;
	for (int i = 29; i >= 0; i--) {
		int tmp = (new_first[i] - '0') + (new_second[i] - '0');
		if ((new_first[i] - '0') + (new_second[i] - '0') > 9){
			answer += to_string(tmp-10);
			mod = 1;
		}
		else {
			answer += to_string(tmp + mod);
			mod = 0;
		}
	}


	cout << answer;
}


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

void b1759(){
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


void b9663(){
	cin >> queen_n;

	getQueen(0);

	cout << queen;
}


//int boardVisited[26][26][4] = {0,};
//int boardCost[26][26][4];
//int p67259_dx[4] = {-1,1,0,0};  // 상하좌우
//int p67259_dy[4] = {0,0,-1,1};
//int boardMin = 999999999;

// 다익스트라 풀이... 틀림
//void p67259(){
//
//	for (int i = 0; i < 26; i++){
//		for (int j = 0; j < 26; j++)
//			fill_n(boardCost[i][j],4,999999999);
//	}
//	
//	vector<vector<int>> board;
//	vector<int> tmp1(3,0);
//	vector<int> tmp2(3,0);
//	vector<int> tmp3(3,0);
//	board.push_back(tmp1);
//	board.push_back(tmp2);
//	board.push_back(tmp3);
//
//
//	priority_queue<pair<pair<int,int>,pair<int,int>>> q;
//    int answer = 999999999;
//
//	q.push(make_pair(make_pair(0,-1),make_pair(0,0)));
//
//	boardCost[0][0][0] = 0;
//	boardCost[0][0][1] = 0;
//	boardCost[0][0][2] = 0;
//	boardCost[0][0][3] = 0;
//
//
//	while (!q.empty()) {
//		int cost = q.top().first.first;
//		int stat = q.top().first.second;
//		int x = q.top().second.first; // 상:0,하:1,좌:2,우:3
//		int y = q.top().second.second;
//		q.pop();
//
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + p67259_dx[i];
//			int ny = y + p67259_dy[i];
//			int nstat = i;
//			int ncost = cost;
//			
//			if (ny < 0 || nx < 0 || nx >= board.size() || ny >= board.size())
//				continue;
//
//			if (stat == -1) ncost += cost + 100;
//			else if (nstat == stat) ncost += cost + 100;
//			else ncost += cost + 600;
//
//			// Point : 재방문이 가능해야 함
//			// 따라서 visited 체크하려면 [x][y][n] 3차원으로 나눠 지금까지 온 방향에 맞춰 체크해야 함
//			// visited 굳이 체크 안 해 줘도 boardCost 배열이 0이 아니면 방문한 것이므로 그렇게 처리해도 됨
//			if (ncost < boardCost[nx][ny][nstat]){
//				boardCost[nx][ny][nstat] = ncost;
//				q.push(make_pair(make_pair(ncost,nstat),make_pair(nx,ny)));
//			}
//		}
//	}
//
//	for (int i = 0; i < 4; i++){
//		if (answer > boardCost[board.size()-1][board.size()-1][i])
//			answer = boardCost[board.size()-1][board.size()-1][i];
//	}
//
//	cout << answer;
//}



int boardCost[26][26];
int p67259_dx[4] = {-1,1,0,0};  // 상하좌우
int p67259_dy[4] = {0,0,-1,1};
int boardMin = 999999999;

//signal: segmentation fault (core dumped)
void p67259_2(){
	vector<vector<int>> board;
	vector<int> tmp1(8,0);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board.push_back(tmp1);
	board[0][7] = 1;
	board[2][5] = 1;
	board[3][4] = 1;
	board[4][3] = 1;
	board[4][7] = 1;
	board[5][2] = 1;
	board[5][6] = 1;
	board[6][1] = 1;
	board[6][5] = 1;
	board[7][0] = 1;

	for (int i = 0; i < 26; i++)
		fill_n(boardCost[i],26,999999999);

	int n = board.size();
	

	queue<pair<pair<int,int>,pair<int,int>>> q;
    int answer = 0;

	q.push(make_pair(make_pair(0,-1),make_pair(0,0)));
	boardCost[0][0] = 0;

	while (!q.empty()) {
		int cost = q.front().first.first;
		int stat = q.front().first.second;
		int x = q.front().second.first; // 상:0,하:1,좌:2,우:3
		int y = q.front().second.second;
		q.pop();

		if (x == n-1 && y == n-1){
			if (boardMin > cost) boardMin = cost;
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nx = x + p67259_dx[i];
			int ny = y + p67259_dy[i];

			
			if (ny < 0 || nx < 0 || nx >= n || ny >= n || board[nx][ny] == 1)
				continue;
			
			int nstat = i;
			int ncost;
			if (stat == -1) ncost = cost + 100;
			else if (nstat == stat) ncost = cost + 100;
			else ncost = cost + 600;


			// Point : 재방문이 가능해야 함
			// 따라서 visited 체크하려면 [x][y][n] 3차원으로 나눠 지금까지 온 방향에 맞춰 체크해야 함
			// visited 굳이 체크 안 해 줘도 boardCost 배열이 0이 아니면 방문한 것이므로 그렇게 처리해도 됨
			if (board[nx][ny] == 0 || board[nx][ny] >= ncost){
				//boardVisited[nx][ny] = 1;
				board[nx][ny] = ncost;
				q.push(make_pair(make_pair(ncost,nstat),make_pair(nx,ny)));
			}
		}
	}
	cout << boardMin;
}


class Car{
	public:
	int x, y, cost, stat;
};

void p67259_3(){
		//vector<vector<int>> board;
	int board[9][9];

	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			board[i][j] = str[j]-'0';
		}
	}

	int n = 8;//board.size();


	Car c;
	c.x = 0, c.y = 0, c.cost = 0, c.stat = -1;
	queue<Car> q;
	board[0][0] = 1;

	q.push(c);

	while (!q.empty()) {
		Car tmp = q.front();
		q.pop();

		if (tmp.x == n-1 && tmp.y == n-1){
			if (boardMin > tmp.cost) boardMin = tmp.cost;
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nx = tmp.x + p67259_dx[i];
			int ny = tmp.y + p67259_dy[i];

			
			if (ny < 0 || nx < 0 || nx >= n || ny >= n || board[nx][ny] == 1)
				continue;
			
			int nstat = i;
			int ncost = 0;
			if (tmp.stat == -1 || nstat == tmp.stat) ncost = tmp.cost + 100;
			else if (nstat != tmp.stat) ncost = tmp.cost + 600;
			

			if (board[nx][ny] == 0 || board[nx][ny] >= ncost){
				board[nx][ny] = ncost;
				Car nc;
				nc.x = nx, nc.y = ny, nc.cost = ncost, nc.stat = nstat;
				q.push(nc);
			}
		}
	}
	cout << boardMin;
}



int tomato2[101][101][101];
int dx_[6] = {0,1,0,-1,0,0};
int dy_[6] = {1,0,-1,0,0,0};
int dh_[6] = {0,0,0,0,1,-1};

void b7569(){
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
		            return;
		        }
				if (tomato2[k][i][j] > answer) answer = tomato2[k][i][j];
			}
		}
	}
    
    cout << answer - 1;	

}



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

void getCAN(int x, int y, int dir, int cleanNum){
	
	int nd = dir;
	for (int i = nd; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];


		if (nx >= 0 || ny >= 0 || nx <= robot_n-1 || ny <= robot_m-1)
			continue;
		if (ground[nx][ny] == 0){ //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			ground[nx][ny] = 2;
			robotAnswer ++;
			getCAN(nx, ny, i+1, cleanNum+1);		
		}

		else if (ground[nx][ny] != 0 && cleanNum != 4) { // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
			nd = i+1;
		}

		else if (ground[nx][ny] != 0 && cleanNum == 4) { // 네 방향 모두 청소가 이미 되어있는 경우 한 칸 후진
			if (dir == 0) y = y+1; // 서쪽일 경우 동쪽으로 한 칸 후진
			else if (dir == 1) x = x-1; // 남쪽일 경우 북쪽으로 한 칸 후진
			else if (dir == 2) y = y-1; // 동쪽일 경우 서쪽으로 한 칸 후진
			else if (dir == 3) x = x+1; // 북쪽일 경우 남쪽으로 한 칸 후진

			if (ground[x][y] == 1) return;
			else getCAN(x, y, dir, 0);
		}
	}
}

void b14503(){
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

	//ground[r][c] == 2;
	//getCAN(r,c,dir,1);
}






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

void b2573(){
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
			return; 
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

int rainyGround[101][101];
int rainyGround_origin[101][101];
int rainy_visited[101][101] = {0,};

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

void b2468(){
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



void b4796(){
	int num = 1;
	while (true) {
		long long l,p,v;
		cin >> l >> p >> v;

		if (l == 0) break;

		int answer = (v/p)*l;
		answer += v%p <= l ? v%p : l;

		cout << "Case " << num << ": " << answer << "\n";
		num++;
	}
}










void p64062(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> stones;
	int k = 3;
    int answer = 0;

	stones.push_back(2);
	stones.push_back(4);
	stones.push_back(5);
	stones.push_back(3);
	stones.push_back(2);
	stones.push_back(1);
	stones.push_back(4);
	stones.push_back(2);
	stones.push_back(5);
	stones.push_back(1);

	int start = 1;
	int end = 200000000;
	int mid;

	while (start <= end) {
		mid = (start+end)/2;
		int tmp = 0;

		bool less = false;
		bool zero = false;
		int zero_num = 0;
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i]-mid <= 0) {
				//stones[i] = 0;
				zero = true;
				zero_num++;
			}
			else {
				//stones[i] = stones[i]-mid;
				zero = false;
				zero_num = 0;
			}

			if (zero_num >= k){ // 범위를 줄여야 함
				less = true;
				//tmp = mid-1;
				break;
			}
		}

		if (less) {
			end = mid-1;
		}
		else {
			start = mid+1;
			answer = max(answer,mid+1);
		}
	}

	cout << answer;
}





void b11053(){
	int arr[1001];
	int dp[1001] = {0,};
	int n;
	int answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) 
				dp[i] = max(dp[i], dp[j]+1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}


void b11054(){
	int desc[1001] = {0,};
	int insc[1001] = {0,};
	int arr[1001];
	int n;
	int answer = 0;

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int insc_max = 0;
	// check incs
	for (int i = 0; i < n; i++) {
		if (insc[i] == 0) insc[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) 
				insc[i] = max(insc[i],insc[j]+1);
		}
		insc_max = max(insc[i], insc_max);
	}
	
	int sum_max = 0;
	int desc_max = 0;
	// check decs
	for (int i = n-1; i >= 0; i--) {
		if (desc[i] == 0) desc[i] = 1;
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) 
				desc[i] = max(desc[i],desc[j]+1);
		}
		desc_max = max(desc[i], desc_max);
		sum_max = max(desc[i]+insc[i]-1, sum_max);
	}

	answer = max(max(desc_max,insc_max),sum_max);

	cout << answer;
}


//vector<int> b1182_v;
//int b1182_n, b1182_s;
//int b1182_answer = 0;
//void b1182_dfs(int idx, int sum){
//	if (sum == b1182_s)
//		b1182_answer++;
//
//	if(idx == b1182_n) return;
//	
//	for (int i = idx; i < n; i++)
//		b1182_dfs(i+1,sum+b1182_v[i]);
//
//}
//
//void b1182(){
//	cin >> b1182_n >> b1182_s;
//
//	for (int i = 0; i < b1182_n; i++) {
//		int tmp;
//		cin >> tmp;
//		b1182_v.push_back(tmp);
//	}
//
//	b1182_dfs(0,0);
//
//	cout << b1182_answer;
//}


int b1182_answer = 0;
int b1182_arr[21];
int b1182_n;
int b1182_s;

void b1182_dfs(int i, int sum){
	
	if (i >= b1182_n) return;
	if (sum + b1182_arr[i] == b1182_s) b1182_answer ++;

	b1182_dfs(i+1, sum);
	b1182_dfs(i+1, sum + b1182_arr[i]);
}

void b1182(){
	cin >> b1182_n >> b1182_s;

	for (int i = 0; i < b1182_n; i++) {
		cin >> b1182_arr[i];
	}

	b1182_dfs(0,0);

	cout << b1182_answer;
}




long long b1208_answer = 0;
int half;
int pn, ps;
int parr[41];
map<int,int> mpLeft;
//map<int,int> mpRight;

void b1208_dfsLeft(int i, int sum){
	if(i == half) {
		mpLeft[sum]++;
		return;
	}

	b1208_dfsLeft(i+1, sum);
	b1208_dfsLeft(i+1, sum+parr[i]);
}

void b1208_dfsRight(int i, int sum){
	if(i == pn) {
		b1208_answer += mpLeft[ps - sum];
		//mpRight[sum]++;
		return;
	}

	b1208_dfsRight(i+1, sum);
	b1208_dfsRight(i+1, sum+parr[i]);
}

void b1208(){
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	 cin >> pn >> ps;
	 for (int i = 0; i < pn; i++) {
		 cin >> parr[i];
	 }

	 half = pn/2;
	 b1208_dfsLeft(0,0);
	 b1208_dfsRight(half,0);
	 

	 //for (auto left = mpLeft.begin(); left != mpLeft.end(); left++){
	//	for (auto right = mpRight.begin(); right != mpRight.end(); right++){
	//		if (left->first + right->first == ps){
	//			answer += left->second * right->second;
	//		}
	//	}
	 //}
	 if (ps == 0) b1208_answer --;
	 cout << b1208_answer;
}





int main(){


	//b1182(); // 부분수열의 합
	//b1208(); // 부분수열의 합 2
	
	//b11053(); // 가장 긴 증가하는 부분 수열
	//b11054(); // 가장 긴 바이토닉 부분 수열



//int dx[4] = {-1,0,1,0};
//int dy[4] = {0,1,0,-1};

//#include <stdio.h>
//#include <stdlib.h>
//#include <unordered_set>
//#include <unordered_map>
//#include <map>
//#include <functional>
//#include <iomanip>
//#include <stack>
//#include <string>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <math.h>
//#include <cmath>

//using namespace std;



	//b11718(); // 그대로 출력하기
	//b11718_2(); 
	//b11718_3();
	//b11718_4();
	//b2908(); // 상수
	//b10951(); // A+B - 4
	//b11719(); // 그대로 출력하기 2
	//b11650(); // 좌표 정렬하기
	//b1924(); // 2007년
	//b1924_2();
	//b10992(); // 별찍기 문제 모르겠음
	//b10828(); // 스택
	//b10845();	// 큐
	//b11656();	// 접미사 배열
	//b10820();	// 문자열 분석
	//b10820_2(); 
	//b224();
	//b10870(); // 피보나치 수 5 - swap 
	//b10870_2(); // 배열
	//b10870_3(); // 재귀
	//b2309(); // 일곱 난쟁이
	//b2609(); // 최대공약수와 최소공배수
	//b1978(); // 소수 찾기
	//b1978_2();
	//b2581(); // 소수
	//b2581_2();
	//p42578(); // 몰겠음 (해시-위장)
	//p42578_2();
	//p42579(); // 베스트앨범 | 프로그래머스

	// 정렬
	//p42746(); // 가장 큰 수 - 혼자하는 코딩
	//p42747(); // 모르겠음 
				// H-Index | 프로그래머스
	//p42626(); // 틀림 // 더 맵게 | 프로그래머스
	//p42626_2(); // 큐 이용
	//p42627(); // 그지발싸개문제모르겠음(힙-디스크컨트롤러)
	//p42628(); //이중우선순위큐 | 프로그래머스
	//p42583(); // ㅋ 모르겠음 (스택-다리를지나는트럭)
	//p42839(); // 소수 찾기 | 프로그래머스 
				//완전탐색을 이용한 모든 수 조합 구하기
	//p42842(); //카펫 | 프로그래머스
	//p42860(); // 탐욕법 조이스틱 다시 풀 것
	//p42860_2(); // 다시 풀었는데 문제 ㅈㄴ이상함
	//p42860_3();
	//p42883(); // 큰 수 만들기 | 프로그래머스
	//p42885(); // 구명보트 | 프로그래머스
	//p42885_2(); // 시간 줄임
	//p42861(); // 섬 연결하기 | 프로그래머스
	//p42861_2();
	//p42884(); // 단속카메라 완벽하게 이해 못함
	//p42895(); // N으로 표현 | 프로그래머스
	//p43105(); // DP 정수 삼각형 | 프로그래머스
	//p43105_2(); 
	//p42898(); // 등굣길 | 프로그래머스
	//p42897(); // 도둑질 | 프로그래머스
	//p43163(); // 단어 변환 (프로그래머스) DFS/BFS


	//---------- DFS/BFS
	//b1260(); // DFS와 BFS
	//b2178(); // 미로 탐색
	//b1303(); // 전쟁 - 전투
	//b1303_2();
	//b1743(); // 음식물 피하기
	//b2606(); //바이러스
	//b1697(); // 숨바꼭질 1
	//b6603(); // 로또
	//b7576(); // 토마토
	//b7569(); // 토마토 2
	//b7562(); // 나이트의 이동
	//b12851(); // 숨바꼭질 2
	//b13549(); // 숨바꼭질 3 다익스트라 알고리즘 우선순위큐 없이 INF로 해결
	//b13913(); // 숨바꼭질 4
	//b14226(); 
	//b14226_2();// 이모티콘 queue에 인덱스,가중치,비용 세 가지로 BFS
	//b17086();
	//b17086_2(); // 아기상어 ---------나중에 풀기 (완료)
	//b1012(); // 유기농 배추
	//b2667(); // 단지번호 붙이기
	//b16953(); // A->B
	//b11724(); // 연결 요소의 개수


	// 알고리즘 다지기 기초 백준 문제 추천
	//b1789(); // 수들의 합
	//b3085(); // 사탕 게임 ----------나중에 풀기
	//b3085_2();
	//b3085_3();
	//b2293(); // 동전 1 - DP
	//b2293_2();
	//b2294(); // 동전 2 - DP
	//b1038(); // 감소하는 수 ---------- 나중에 풀기 https://intaehwang.tistory.com/95
	//b1038_2();
	//b17070(); // 파이프 옮기기
	//b1292(); // 쉽게 푸는 문제

	//약점체크
	//b2504(); // 괄호의 값 https://jaimemin.tistory.com/820 참고해서 다시 풀기
	//b2504_2();
	//b14719(); // 빗물
	//b14719_2();
	//b1062(); // 가르침 (완전탐색) 모르겟음 다시 풀기
	//b1062_2();
	//b1806(); // 부분합 (투포인터) 이해 못함
	//b1806_2(); // 이해했는데 이 코드 틀림 
	//b1806_3(); 
	//b1916(); // 최소비용 구하기
	//b14888(); // 연산자 끼워넣기 백트래킹/재귀/완전탐색/DFS
	// 세 가지 방식
	// https://mytodays.tistory.com/9
	// https://gyeolse.github.io/algorithm/boj-14888/
	// https://cryptosalamander.tistory.com/60
	//b14888_2();

	// 그리디 알고리즘
	//b1700(); // 멀티탭 스케줄링 - 그리디 (다시 풀기) -> 완료
	//b1700_2();
	//b11047();
	//b11000(); // 강의실 배정 - 모르겠다 -> 완료
	//b11000_2(); // 우선순위 큐
	//b1946(); // 신입사원
	//b12845(); // 모두의 마블 - 우선순위큐 인접한 카드만 합성할 수 있어서 사실 틀렸는데 맞음
	//b1931(); // 회의실 배정 - 최대 회의수를 구해야 하기에 종료 시간을 기준으로 잡음
	//b1969(); // DNA - 완전탐색에 가까운 문제
	//b4796(); // 캠핑

	// 백트래킹 
	//완전탐색의 아이디어에서 불필요한 분기(Branch) 를 가지치기(Pruning) 하는 것입니다.
	//b1182(); 부분 수열의 합 - 재귀 - 해결법 알지만 완벽히 이해 못 함
	//b1405(); // 미친 로봇 - 다시 풀기
	// https://jaimemin.tistory.com/724
	//https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-1405-%EB%AF%B8%EC%B9%9C%EB%A1%9C%EB%B4%87/
	//https://yabmoons.tistory.com/171
	
	// 이진탐색
	//b1920();
	//b1920_2();
	//b10816(); // 숫자 카드 2
	//b1654(); // 랜선 자르기
	//b2805(); // 나무 자르기
	//p64062(); // 징검다리 건너기(프로그래머스)


	//그래프
	//p43238(); // 입국심사
	//p49189(); //가장 먼 노드
	//b49191(); // 순위
	// 방의 개수
	//b1197(); // 최소 스패닝 트리
	//b2252(); // 줄 세우기 - 위상정렬


	// KMP 알고리즘
	//b16916(); // 부분 문자열
	b16916_2(); // 어렵다... 다음에 풀기


	// 튼튼한 기본기
	//b2693(); // N번째 큰 수
	//b2609_2(); // 최대공약수 최대공배수
	//b2501(); // 약수 구하기
	//b3460_2(); // 이진수


	// DP
	//b1495(); // 기타리스트
	//b1495_2();
	//b15486(); // 퇴사
	//b15486_2();
	//b15486_3();
	//b1890(); // 점프
	//b12026(); // BOJ
	//b11058(); // 크리보드
	//b10942(); // 팰린드롬
	//b11066(); // 파일 합치기
	//b11066_2(); 


	//DFS&BFS 연습
	//b2206(); // 벽 부수고 이동하기
	//b2206_2();
	//b2206_3();
	//b1476(); // 날짜 계산
	//b1107(); // 리모컨
	//b1107_2(); 
	//b1107_3(); //https://yjios.tistory.com/8

	//완전탐색
	//b1065(); // 한수
	//b14501(); // 퇴사
	//b14889(); // 스타트와 링크
	//b10819(); // 차이를 최대로
	//b2529(); // 부등호
	//b2529_2(); 
	//b2529_3(); 
	//b2503(); // 숫자야구
	//b1339(); // 단어 수학
	//b1339_2();
	//b9095(); //1,2,3 더하기
	//b10972(); // 다음 순열
	//b10972_2();
	//b10973(); // 이전 순열


	//navis01();
	//navis02();
	//navis03();
	//navis05();
	//navis05_2();
	//navis06();

	//b1759(); // 암호 만들기
	//b9663(); // N-Queen
	//p67259(); // 경주로 건설 (프로그래머스
	//p67259_2(); 
	//p67259_3(); 
	// https://programmers.co.kr/questions/20299 의 경우처럼 알고리즘이 항상 최단경로를 보장하지 못함
	// if (board[nx][ny] == 0 || board[nx][ny] >= ncost) 에서 ncost가 더 작을 경우에만 돌기 때문에... 이 조건이 없더라도 돌아가도록 해야 함
	//b14503(); // 로봇 청소기
	//b2573(); // 빙산
	//b2468(); // 안전 영역





	//string tmp = "qwerty";
	//string tmp2 = "qwert";
	//auto it = 


	//string str = "string";
	//cout << str[-1];


	//string temp = "123";
	//auto it = stoi(temp)+1; // int 124
	//vector<bool> prime(stoi(temp)+1); // 123개의 벡터 공간



	//string s = "-1";
	//int i = stoi(s);
	//cout << i;


	//string s;
	//scanf("%s",s);
	////printf("%s",s);
	//cout << endl << s; // scanf-printf / cin-cout 혼용 사용 불가함
	//
	//int tmp1[10];
	//char tmp2[10];
	//char tmp3[] ="";
	//
	//scanf("%d", &tmp1[3]);
	////scanf("%d", tmp1[3]); // 오류남
	//scanf("%d", tmp1);

	////scanf("%s", tmp2);
	////scanf("%s", tmp3);

	//printf("%d\n", tmp1[5]);


	return 0;
}