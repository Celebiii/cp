#include<bits/stdc++.h>
using namespace std;
void solve() {
	string s; cin >> s;
	int num_0 = 0, num_1 = 0;
	int num_01 = 0, num_10 = 0;
	int n = s.length();
	for(int i = 0; i < n; i++){
	    if(s[i] == '0'){
	        num_0++;
	        num_10 += num_1;
	    }else{
	        num_1++;
	        num_01 += num_0;
	    }
	}
	vector<vector<int>> one(n + 1, vector<int>(n * n + 1, 0)), zero = one;
	one[0][0] = zero[0][0] = 1;
	for(int i = 1; i <= n; i++){
	    for(int j = i - 1; j >= 0; j--){
	        for(int k = i * i; k >= 0; k--){
	            if(zero[j][k] && s[i - 1] == '0'){
	                zero[i + 1][j + i] = 1;
	            }else if(one[j][k] && s[i - 1] =='1'){
	                one[i + 1][j + i] = 1;
	            }
	        }
	    }
	}
	for(int i = 0; i <= n; i++){
	    for(int j = 0; j <= n*n; j++){
	        if(zero[i][j] 
	        && (num_01 - num_10)/2 + j >= 0 
	        && (num_01 - num_10)/2 + j <= n * n
	        && one[i][(num_01 - num_10)/2 + j]
            ){
                cout << i <<endl;
                return;
            }
	    }
	}
}
int main(){
    solve();
    return 0;
}