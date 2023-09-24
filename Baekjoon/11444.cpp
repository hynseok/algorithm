#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator*(const matrix &a, const matrix &b)
{
    int n = a.size();
    matrix ret(n, vector<ll>(n));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < n; k++)
            {
                ret[i][j] += ((a[i][k] % 1000000007) * (b[k][j] % 1000000007)) % 1000000007;
            }
            ret[i][j] %= 1000000007;
        }
    }
    return ret;
}

matrix power(matrix a, ll b)
{
    int n = a.size();
    matrix ret(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        ret[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ret = ret * a;
        }
        b /= 2;
        a = a * a;
    }
    return ret;
}

int main()
{

    ll n;
    matrix origin = {{1, 1}, {1, 0}};

    cin >> n;

    cout << power(origin, n)[0][1];
}