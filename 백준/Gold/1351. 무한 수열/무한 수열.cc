#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 52
#define MOD 1000000000
using namespace std;
typedef pair<int, int> p;

ll P, Q;
map<ll, ll> cache;	//idx, val

ll solve(ll n) {
  //기저 사례
	if (n == 0)return 1;
  
	ll& ret = cache[n];
	if (ret != 0)return ret;

	return ret = solve(n / P) + solve(n / Q);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll N;

	cin >> N >> P >> Q;
	cout << solve(N) << endl;
  
	return 0;
}