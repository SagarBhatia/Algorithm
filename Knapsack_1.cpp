#include<iostream>
using namespace std;
/*int min_w(float w[],int n,int min)
{
    int i,temp2,temp;
    temp2=min;
    temp=min;
    for(i=1;i<n;i++)
    {
        if(w[i]<min && temp!=min)
        {
            min=w[i];
        }
    }
    return min;
}*/
int max_p(float p[],int n)
{
    int i,max=p[0],k=0;
    for(i=0;i<n;i++)
    {
        if(max<p[i])
        {
            max=p[i];
            k=i;
        }
    }
   // p[k]=-99;
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<p[i]<<"  ";
    }
return k;
}
float profit(float x[],float w[],float p[],int n,int wt)
{
    int i,k=0,w_left=wt;
    float p1=0,temp;
    for(i=0;i<n;i++)
    {
        k=max_p(p,n);
        cout<<"\nP[k] :  "<<p[k];
        temp=p[k];
        p[k]=-99;
        w_left=w_left-w[k];
        if(w_left>0)
        {
            p1=p1+temp;
        /*if(w_left>w[k])
        {
            p1=p1+temp;
        }
        else
        {
            p1=p1+((w_left/w[k])*temp);
        }*/
        }
        else
        {
             p1=p1+(((w_left+w[k])/w[k])*temp);
            break;
        }
    }
    return p1;
}
/*float weight(float x[],float w[],float p[],int n,int wt)
{
    float p1;
    int i,min=999,k,temp=wt;
    for(i=0;i<n;i++)
    {
        min=min_w(w,n,min);
    }

}*/
int main()
{
    int n,i,wt;
    cout<<"Enter the Number and Capacity: ";
    cin>>n>>wt;
    float x[n],w[n],p[n],p1=0;
    cout<<"\nEnter the Weight Array: ";
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
    for(i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"\nEnter Price Array: ";
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
   // weight(x,w,p,n,wt);
   p1=profit(x,w,p,n,wt);
   cout<<"\nProfit : "<<p1;
    return 0;
}
