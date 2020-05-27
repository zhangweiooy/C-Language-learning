#include<cstdio>  
#include<iostream>   
#include<cstring>  
#include<algorithm>  
using namespace std; 
#define MOD 1000000007 
typedef long long ll;  
ll tree[100002];  
ll s[100002],c[100002];  
ll n, top;  
ll lowbit(ll x)  
{  
    return x&(-x);  
}  
void update(ll x,ll val) 
{  
    while(x<=n)  
    {  
        tree[x]+=val;  
        if(tree[x]>=MOD)  
            tree[x]%=MOD;  
        x+=lowbit(x);  
    }  
}  
ll getsum(ll x)
{  
    ll s=0; 
    while(x>0)  
    {  
        s+=tree[x];  
        if(s>=MOD)  
            s%=MOD;  
        x-=lowbit(x);  
    }  
    return s;  
}  
ll bin(ll x)//二分法查找x的下标位子  
{  
    ll l=1,h=top;  
    while(l<=h)  
    {  
        ll mid=(l+h)>>1;  
        if(x==c[mid])
	        return mid;  
        if(x>c[mid])
		    l=mid+1;  
        else 
		    h=mid-1;  
    }  
}  
int main()  
{  
    ll i; 
	int t,Case=0;
	scanf("%d",&t); 
    while(t--)  
    {  
        scanf("%d",&n);
        Case++;
        for(i=1; i<=n; i++)  
        {  
            scanf("%d",&s[i]);  
            c[i]=s[i];  
        }  
        sort(c+1,c+n+1);
        top=0;  
        for(i=1; i<=n; i++)  
        {  
            if(i==1||c[i]!=c[i-1])
            {  
                c[++top]=c[i];
                tree[top]=0;  
            }  
        }  
        update(1,1);  
        ll ans=0;  
        for(i=1; i<=n; i++)  
        {  
            ll id=bin(s[i]);  
            ll temp=getsum(id);  
            ans+=temp;  
            if(ans>=MOD)ans%=MOD;  
            update(id,temp);  
        }  
        printf("Case %d: %I64d\n",Case,ans);  
    }  
    return 0;  
}  
