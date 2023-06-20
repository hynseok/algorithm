#include <bits/stdc++.h>
using namespace std;

int ans=0;
int N, K;
int dy[2] = {0,-1};
int dx[2] = {1,0};
deque<int> fishbowl[101];

void Input();
bool check();
void addfish();
bool canBuild(int width, int height);
int Roll1();
void Roll2();
void Spread(int height);
void Distribute(int height);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Input();
    while(1)
    {
        if(check())
        {
            cout<<ans;
            return 0;
        }

        addfish();
        int height = Roll1();
        Distribute(height);
        Spread(height);
        Roll2();
        Distribute(4);
        Spread(4);
        ans++;
    }

}

void Input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int temp; cin>>temp;
        fishbowl[0].push_back(temp);
    }
}

bool check()
{
    int Min = 999999;
    int Max = -999999;

    for(int i=0;i<fishbowl[0].size();i++)
    {
        Min = min(Min, fishbowl[0][i]);
        Max = max(Max, fishbowl[0][i]);
    }

    if(Max-Min<=K) return true;
    else return false;
}

void addfish()
{
    int minval=999999;
    vector<int> indexV; 
    for(int i=0;i<fishbowl[0].size();i++)
    {
        if(fishbowl[0][i]<minval)
        {
            minval = fishbowl[0][i];
            indexV.clear();
            indexV.push_back(i);
        }
        else if(fishbowl[0][i]==minval)
        {
            indexV.push_back(i);
        }
    }

    for(int i=0;i<indexV.size();i++)
    {
        fishbowl[0][indexV[i]]++;
    }
}

bool canBuild(int width, int height)
{
    if(fishbowl[0].size()-width < height) return false;
    
    return true;
}

int Roll1()
{
    int width = 1;
    int height = 1;
    bool tok = true;
   

    while(1)
    {
        if(!canBuild(width,height)) break;

        int temp_width = width;
        
        for(int i=0;i<width;i++,temp_width--)
        {
            for(int j=0;j<height;j++)
            {
                fishbowl[temp_width].push_back(fishbowl[j][i]);
            }
        }

        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                fishbowl[i].pop_front();
            }
        }

        if(tok)
        {
            tok = false;
            height++;
        }
        else
        {
            tok = true;
            width++;
        }

    }

    return height;
}

void Roll2()
{
    int width = fishbowl[0].size();

    for(int i=0;i<width/2;i++)
    {
        fishbowl[1].push_front(fishbowl[0][i]);
    }
    for(int i=0;i<width/2;i++)
    {
        fishbowl[0].pop_front();
    }
    for(int i=0;i<width/4;i++)
    {
        fishbowl[2].push_front(fishbowl[1][i]);
        fishbowl[3].push_front(fishbowl[0][i]);
    }
    for(int i=0;i<width/4;i++)
    {
        fishbowl[1].pop_front();
        fishbowl[0].pop_front();
    }
}

/*
void Spread(int height)
{
    int temp_width = fishbowl[height-1].size();
    int size = fishbowl[0].size();
    for(int i=0;i<temp_width;i++)
    {
        for(int j=0;j<height;j++)
        {
            fishbowl[0].push_back(fishbowl[j][i]);
        }
    }
    
    for(int i=temp_width;i<size;i++)
    {
        fishbowl[0].push_back(fishbowl[0][i]);
    }

    for(int i=0;i<height;i++)
    {  
        for(int j=0;j<temp_width;j++)
        {
            fishbowl[i].pop_front();
        }
    }
}
*/

void Spread(int height)
{
    int temp_width = fishbowl[height-1].size();
    int size = fishbowl[0].size();
    for(int i=0;i<temp_width;i++)
    {
        for(int j=0;j<height;j++)
        {
            fishbowl[0].push_back(fishbowl[j][i]);
        }
    }

    for(int i=1;i<height;i++)
    {
        fishbowl[i].clear();
    }
    
    for(int i=temp_width;i<size;i++)
    {
        fishbowl[0].push_back(fishbowl[0][i]);
    }

    for(int i=0;i<size;i++)
    {  
        fishbowl[0].pop_front();
    }
}


void Distribute(int height)
{
    deque<int> temp_fishbowl[101];
    for(int i=0;i<height;i++)
    {
        temp_fishbowl[i] = fishbowl[i];
    }

    for(int i = height-1;i>=0;i--)
    {
        for(int j=0;j<fishbowl[i].size();j++)
        {
            int y = i;
            int x = j;
            int num1 = fishbowl[y][x];
            for(int k=0;k<2;k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if(ny>=0&&nx<fishbowl[i].size())
                {
                    int num2 = fishbowl[ny][nx];
                    int diff = abs(num1-num2)/5;
                    if(diff>0)
                    {
                        if(num1>num2)
                        {  
                            temp_fishbowl[y][x] -= diff;
                            temp_fishbowl[ny][nx] += diff;
                        }
                        else
                        {
                            temp_fishbowl[y][x] += diff;
                            temp_fishbowl[ny][nx] -= diff;
                        }
                    }
                }

            }
        }
    }

    for(int i=0;i<height;i++)
    {
        fishbowl[i] = temp_fishbowl[i];
    }
}
