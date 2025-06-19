#include<bits/stdc++.h>
#define ll long long
using namespace std;
//author: Pham Dan Truong 
int cnt[1000100]; // dem thua so le
int le(int n)
{
    int res=1;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            int dem=0;
            while(n%i==0)
            {
                dem++;
                n/=i;
            }
            if (dem%2==1)
            {
                res*=i;
            }
        }
    }
    if (n>1) res*=n;
    return res;
}
int main()
{
  //  freopen("input.inp" ,"r", stdin);
  //  freopen("main_out.out","w",stdout); 
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        ll res=n;
        ll dem=0;
        for (int i=1;i<=n;i++)
        {
            int tmp=sqrt(i);
            if (tmp*tmp==i)
            {
                dem++;
            }
        }
        res+=(dem*(dem-1));
        for (int i=2;i<=n;i++)
        {
            int tmp=le(i);
            if (tmp!=1)
            {
            res+=(cnt[tmp]*2);
            cnt[tmp]++;
            }
        }
        cout<<res<<endl;


}