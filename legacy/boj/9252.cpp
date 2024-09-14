#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int dp[1001][1001] = {0,};
    bool direction[1001][1001] = {0,};
	int alen, blen;
	string a, b;
	
    cin>>a>>b;
	
	alen = a.length();
	blen = b.length();

    for(int i=1;i<=alen;i++)
    {
        for(int j=1;j<=blen;j++)
        {
            if(a[i-1]==b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				direction[i][j] = 1;
			}
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				direction[i][j] = 0;
            }
        }
    }
	
	int len = dp[alen][blen];
	int idx = 0;
	char lcs[len];
	int x, y;
	y = alen; x = blen;
	while(y > 0 && x > 0) {
		if (direction[y][x]) {
			lcs[idx++] = a[y-1];
			y--; x--;
		}
		else {
			if(dp[y][x] == dp[y-1][x]){
				y--;
			}
			else {
				x--;
			}
		}
	}
	lcs[len] = '\0';
	reverse(lcs, lcs+len);
	cout<<len<<"\n";
	if(len>0)
		cout<<lcs;
}

