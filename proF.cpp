//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo 1000000000000000008
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 5005
#define MOD
#define all(x) x.begin(), x.end()
#define Pi 3.141592653589793238
#define cosdo(x) cos(x/180 * Pi)
#define sindo(x) sin(x/180 * Pi)
#define tando(x) tan(x/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task ""
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k, l, r, HN_SG;
int p[maxn];
ll dp[maxn][maxn];
ll delta[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> n >> k;
    cin >> l >> r;
    cin >> HN_SG;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= k; i ++)
        delta[i] = 2ll * i * (k - i);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= k; j ++)
            dp[i][j] = -oo;
    p[0] = -1000000009;
    for(int i = 1; i <= n; i ++)
        if(p[i] >= l && p[i] <= r)
            dp[i][1] = 0;
    for (int j = 2; j <= k; j ++)
    {
        deque <pair <ll, int>> dq;
        int pre = 1;
        for (int i = 1; i <= n; i ++)
        {
            while(p[i] - p[pre] > r) pre ++;
            while(!dq.empty() && p[i] - p[dq.front().S] > r) dq.pop_front();
            for(; p[i] - p[pre] >= l; pre ++){
                ll tmp = dp[pre][j - 1] - delta[j - 1] * p[pre];
                while(!dq.empty() && tmp >= dq.back().F) dq.pop_back();
                dq.PB({tmp, pre});
            }
            if (!dq.empty()) dp[i][j] = dq.front().F + delta[j - 1] * p[i];
        }
    }
    ll res = 0;
    for (int q = 1; q <= n; q ++)
        if (p[q] >= HN_SG - r && p[q] <= HN_SG - l) res = max(dp[q][k], res);
    cout << res;
}
