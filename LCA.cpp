/*
   Author: Bishal Suvechha Manindra
   Algorithm: LCA
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF INT_MAX
#define NINF INT_MIN
#define pb push_back
#define f first
#define s second
#define debug(x) cout << #x << "-->" << x << endl
#define print(x) cout << x << endl
#define printc(x) cout << x << " "
#define foreach(arr)    \
    for (auto &e : arr) \
    cout << e << " "
#define nextline cout << "\n"
#define MOD 1000000007
#define mem(dp, i) memset(dp, i, sizeof(dp))
#define timeTaken std::cout << "\nTime: " << float(clock() - begin_time) / CLOCKS_PER_SEC
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less: it is the basic for comparison of two function. Use less_equal for ordered multiset.
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero)
const int N = 1e5 + 2;
const int M = 20;
// M = log(N);
/* ----------------------------  Code Start Here ------------------------------ */

// DFS - O(N*M)
// LCA - O(M) == log(n) -> per_Query
//  Par[i][j] -> 2^j of i
vector<int> graph[N];
int Par[N][M];
int dept[N];

// building Sparse Table
void dfs(int cur, int par)
{
    dept[cur] = dept[par] + 1;

    Par[cur][0] = par;
    for (int j = 1; j < M; ++j)
    {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }

    for (auto &x : graph[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v)
{
    if (u == v)
        return u;
    if (dept[u] < dept[v])
        std::swap(u, v);
    int diff = dept[u] - dept[v];
    for (int j = M - 1; j >= 0; --j)
    {
        if ((diff >> j) & 1)
        {
            u = Par[u][j];
        }
    }
    // if u/v is LCA(u,v)
    if (u == v)
        return u;

    for (int j = M - 1; j >= 0; --j)
    {
        if (Par[u][j] != Par[v][j])
        {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}

void run()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    dfs(1, 0);

    // printing Sparse Table
    //  for(int i=1; i<=12; ++i){
    //    cout<<i<<"-> ";
    //    for(int j=0; j<4; ++j){
    //      cout<<Par[i][j]<<" ";
    //    }
    //    cout<<endl;
    //  }

    cout << LCA(9, 12) << endl;
    cout << LCA(10, 8) << endl;
    cout << LCA(9, 11) << endl;
}

/* ----------------------------  Code End Here ---------------------------------*/

int32_t main()
{
    FASTIO;
    const clock_t begin_time = clock();
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        run();
        nextline;
    }
    // timeTaken;
    return 0;
}

/* Example:
    11
    1 2
    1 3
    2 4
    2 5
    2 6
    4 10
    5 8
    8 9
    8 11
    3 7
    7 12
*/