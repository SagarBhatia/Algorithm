#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char x[10],y[10],lcs[10],lcs2[10];
    cout<<"Enter The String: ";
    cin>>x>>y;

    int i,l1=strlen(x);
    int l2=strlen(y);
    int c[l1+1][l2+1];
    int b[l1+1][l2+1];
    int t1=l1,t2=l2,ind=0;

    for(i=0;i<=l1;i++)c[i][0]=0;
    for(i=0;i<=l2;i++)c[0][i]=0;
    for(i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else
            {
                if(c[i][j-1]<=c[i-1][j])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=0;
                }

            }
        }
    }
    for(i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    for(i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(i=t1;i>=0;i--)
    {
        for(int j=t2;j>=0;j--)
        {
            if(b[t1][t2]==0)
            {
                t2--;
                break;
            }
            else if(b[t1][t2]==2)
            {
                t1--;
                break;
            }
            else
            {
                lcs[ind++]=x[t1-1];
                t1--;
                t2--;
                break;

            }
        }
    }
    lcs[ind]='\0';
    //cout<<"LCS : "<<lcs<<endl;
    for(i=0;i<strlen(lcs);i++)
    {
        lcs2[strlen(lcs)-i-1]=lcs[i];
    }
    cout<<endl<<lcs2;
}
