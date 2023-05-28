#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto inf = int{ 987'654'321 };

int n;
vvi cost;
vvi dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	cost = vvi(n, vi(3));
	for (auto&& row : cost) {
		for (auto&& x : row) {
			cin >> x;
		}
	}

	dp = vvi(n, vi(3));
	auto ans = inf;
	for (auto clr = 0; clr < 3; ++clr) {
		dp[0][clr] = cost[0][clr];
		dp[0][(clr + 1) % 3] = inf;
		dp[0][(clr + 2) % 3] = inf;

		for (auto i = 1; i < n; ++i) {
			for (auto j = 0; j < 3; ++j) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
			}
		}

		ans = min(ans, dp[n - 1][(clr + 1) % 3]);
		ans = min(ans, dp[n - 1][(clr + 2) % 3]);
	}

	cout << ans;

	return 0;
}