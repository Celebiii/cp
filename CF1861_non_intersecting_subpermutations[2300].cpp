#include<iostream>
using namespace std;

using ll = long long;
const int N = 4e3 + 7;
ll f[N][N]{},s[N]{},mod = 998244353;
int main(){
	ll n, k; 
	cin >> n >> k;
	s[0] = 1;
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] * k % mod;
	}
	ll ans = 0;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		ll x = 0;	
		for(int j = k - 1; j >= 1; j--){
			x = (x + f[i - 1][j] % mod) % mod;
			f[i][j] = x;
 		}
 		for(int j = 0; j < k; j++){
 			f[i][(j + 1)%k] = (f[i][(j + 1)%k] + f[i - 1][j]*(k - j) %mod) %mod;
		}
		ans = (ans + f[i][0]*s[n - i] % mod) % mod;
	}
	for(int i = 1; i <= 5; i++){
		for(int j = 0; j <= k - 1; j++){
			cout << "f[" << i << "][" << j << "]" << " = " << f[i][j] << endl;
		}
	}
	cout << ans << '\n';
	return 0;
}