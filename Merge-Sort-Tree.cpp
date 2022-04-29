/*
   Author: Bishal Suvechha Manindra
   Algorithm: Merge Sort Tree
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
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
#define foreach(arr)  for (auto &e : arr) cout << e << " "
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
/* ----------------------------  Code Start Here ------------------------------ */

const int maxL = 1000005;
int arr[maxL + 1];
vector<int> ST[4 * maxL];
void build(int root, int start, int end)
{
    if (start == end)
    {
        ST[root].push_back(arr[start]);
        return;
    }

    int mid = start + (end - start) / 2;
    build(2 * root, start, mid);
    build(2 * root + 1, mid + 1, end);

    int i = 0, j = 0;
    while (i < ST[2 * root].size() && j < ST[2 * root + 1].size())
    {
        if (ST[2 * root][i] <= ST[2 * root + 1][j])
        {
            ST[root].push_back(ST[2 * root][i]);
            i++;
        }
        else
        {
            ST[root].push_back(ST[2 * root + 1][j]);
            j++;
        }
    }

    while (i < ST[2 * root].size())
    {
        ST[root].push_back(ST[2 * root][i]);
        i++;
    }
    while (j < ST[2 * root + 1].size())
    {
        ST[root].push_back(ST[2 * root + 1][j]);
        j++;
    }
}

int query(int root, int start, int end, int l, int r, int k)
{
    if (l > end or r < start)
        return 0;
    if (l <= start and r >= end)
    {
        return (upper_bound(ST[root].begin(), ST[root].end(), k) - ST[root].begin()) - (lower_bound(ST[root].begin(), ST[root].end(), k) - ST[root].begin());
    };

    int mid = start + (end - start) / 2;
    int left = query(2 * root, start, mid, l, r, k);
    int right = query(2 * root + 1, mid + 1, end, l, r, k);
    return left + right;
}

void run()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    ll q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }
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
