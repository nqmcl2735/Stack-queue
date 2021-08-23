//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 3000005
#define MOD
#define Pi 3.141592653589793238
#define cosdo(x) cos(x/180 * Pi)
#define sindo(x) sin(x/180 * Pi)
#define tando(x) tan(x/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
int p[maxn];
int d[maxn];
int a[maxn];
int suf[maxn];
bool check1[maxn];
bool ok[maxn];
bool check2[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i] >> d[i];
        a[i] = p[i] - d[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i ++)
        suf[i] = suf[i - 1] + a[i];
    deque <int> dq;
    for (int i = 0; i <= n * 2; i ++)
    {
        while(!dq.empty() && suf[i] <= suf[dq.back()]) dq.pop_back();
        dq.PB(i);
        if (i - dq.front() >= n) dq.pop_front();
        if(i >= n) check1[i - n + 1] = (suf[i - n] <= suf[dq.front()]);
    }
    for (int i = n; i >= 2; i --)
        a[n - i + 1] = p[i] - d[i - 1];
    a[n] = p[1] - d[n];
    for (int i = 1; i <= n; i ++) a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; i ++)
        suf[i] = suf[i - 1] + a[i];
    while(!dq.empty()) dq.pop_back();
    for (int i = 0; i <= n * 2; i ++)
    {
        while(!dq.empty() && suf[i] <= suf[dq.back()]) dq.pop_back();
        dq.PB(i);
        if (i - dq.front() >= n) dq.pop_front();
        if(i >= n) ok[i - n + 1] = (suf[i - n] <= suf[dq.front()]);
    }
    for (int i = 1; i <= n; i ++)
        check2[i] = ok[n - i + 1];
    for (int i = 1; i <= n; i ++)
        if (check1[i] || check2[i]) cout << "YES\n";
        else cout << "NO\n";
}
