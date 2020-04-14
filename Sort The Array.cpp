#include <bits/stdc++.h>

using namespace std;

void merge_sort(int ara[], int l, int r)
{
    if(l == r) return;
    int mid = l + (r - l) / 2;
    merge_sort(ara, l, mid);
    merge_sort(ara, mid + 1, r);
    int temp[r - l + 1], i = l, j = mid + 1, k = 0;
    while((i <= mid) && (j <= r))
    {
        if(ara[i] < ara[j]) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while(i <= mid) temp[k++] = ara[i++];
    while(j <= r) temp[k++] = ara[j++];
    for(i = l, j = 0; i <= r; i++, j++)
        ara[i] = temp[j];
}
void selection_sort(int ara[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int mn_idx = i;
        for(int j = i + 1; j < n; j++)
            if(ara[mn_idx] > ara[j]) mn_idx = j;
        swap(ara[i], ara[mn_idx]);
    }
}
void insertion_sort(int ara[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i, k = i - 1;
        while(ara[j] < ara[k] && k >= 0)
        {
            int temp = ara[j];
            ara[j] = ara[k];
            ara[k] = temp;
            j--;
            k--;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ara[n];
        for(int i = 0; i < n; i++) cin>>ara[i];
        // merge_sort(ara, 0, n - 1);
        //sort(ara, ara + n);
        //selection_sort(ara, n);
        insertion_sort(ara, n);
        for(int i = 0; i < n; i++)
            cout<<ara[i]<<" ";
        cout<<endl;
    }
    return 0;
}
