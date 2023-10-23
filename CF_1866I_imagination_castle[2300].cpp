#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5, M = N;
int n, m, k, x, y;
vector<int> arr[M];
bool P[N]{};//store col index
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		x, y;
		arr[x].push_back(y);
	}
	int p1 = 1;								
	for(int i = n, j = m; i >= 0; i--){    
		int mx_p = -1;
		for(auto a : arr[i]){
			mx_p = max(a, mx_p);
			P[a] = 1;
		}
		while(j >= 0 && P[j]){
			j--;
		}
		if(j > mx_p){
			P[j] = 1;
			if(i == 1 && j == 1){
				p1 = 0;
			}
		}
	}
	if(p1) cout << "Chaneka" << endl;
	else cout << "Bhinneka" << endl;
	return 0;
}