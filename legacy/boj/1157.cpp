#include <bits/stdc++.h>
using namespace std;

int main()
{
    int alpha[100] = {0, };

    char T;
    while(1)
    {
        scanf("%1c",&T);
        if(T=='\n')break;

        if(T>=97)
        {
            T-=32;
        }
        alpha[T]++;
    }   

    int min = -1;
    int idx;
    for(int i=0;i<100;i++)
    {
        if(alpha[i]>min)
        {
            idx=i;
            min=alpha[i];
        }
         
    }
    int tok=0;
    for(int i=0;i<100;i++)
    {
        if(alpha[i]==alpha[idx])
        {
            tok++;
        }
    }

    if(tok>1)
    {
        printf("?");
        return 0;
    }
    else
    {
        printf("%c",idx);
        return 0;
    }


}