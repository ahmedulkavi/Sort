#include<iostream>
using namespace std;

void merge(int *a,int l,int m,int r)
{
    int i_a,i_l,i_r;
    int s_l = m-l+1,s_r = r-m;

    int L[s_l],R[s_r];

    for(int i=0;i<s_l;i++)
    {
        L[i] = a[l+i];
    }

    for(int i=0;i<s_r;i++)
    {
        R[i] = a[m+1+i];
    }

    i_l = 0;
    i_r = 0;

    for(i_a=l;i_l<s_l && i_r<s_r;i_a++)
    {
        if(L[i_l]<R[i_r])
        {
            a[i_a] = L[i_l];
            i_l++;
        }

        else
        {
            a[i_a] = R[i_r];
            i_r++;
        }
    }

    while(i_l<s_l)
    {
        a[i_a] = L[i_l];
        i_l++;
        i_a++;
    }

    while(i_r<s_r)
    {
        a[i_a] = R[i_r];
        i_r++;
        i_a++;
    }

}

void merge_sort(int *a,int l,int r)
{
    if(l>=r)
    {
        return;
    }

    int m = l + (r-l)/2;

    merge_sort(a,l,m);

    merge_sort(a,m+1,r);

    merge(a,l,m,r);
}

int main(void)
{
    int n;

    cout << "Enter the size of array:" << endl;
    cin >> n;

    int *a = new int[n];

    cout << "Enter the elements:" << endl;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    merge_sort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete [] a;
}
