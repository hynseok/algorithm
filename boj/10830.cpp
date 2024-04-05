#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator * (const matrix &a, const matrix &b){
    int n = a.size();
    matrix ret(n, vector<ll>(n));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= 1000;
        }
    }
    return ret;
}

matrix power(matrix a, ll b){
    int n = a.size();
    matrix ret(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        ret[i][i] = 1;
    }

    while(b > 0){
        if(b % 2 == 1){
            ret = ret * a;
        }
        b /= 2;
        a = a * a;
    }
    return ret;
}

void printMatrix(matrix a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll b;
    cin >> n >> b;

    matrix a(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    matrix ans = power(a, b);
    printMatrix(ans);


    return 0;
}