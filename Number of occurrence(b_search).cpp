#include <bits/stdc++.h>

using namespace std;

int b_search(int ara[], int l, int r, int k)
{
    int cnt = 0;
    if(l > r) return cnt;
    int mid = l + (r - l) / 2;
    if(ara[mid] == k) cnt++;
    if(ara[mid] <= k) cnt += b_search(ara, mid + 1, r, k);
    if(ara[mid] >= k) cnt += b_search(ara,l, mid - 1, k);
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, cnt = 0;
        cin>>n>>k;
        int ara[n];
        for(int i = 0; i < n; i ++) cin>>ara[i];
        cnt = b_search(ara, 0, n-1, k);
        if(cnt) cout<<cnt<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
