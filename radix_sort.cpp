#include<iostream>
using namespace std;

int max(int *a,int n)
{
    int m = a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>m) m = a[i];
    }

    return m;
}

void counting_sort(int *a,int n,int exp)
{
    int cnt[10] = {0};

    int *output = new int [n];

    for(int i=0;i<n;i++)
    {
        cnt[(a[i]/exp)%10]++;
        //cout << cnt[(a[i]/exp)%10] << " " << (a[i]/exp)%10 << endl;
    }

    for(int i=1;i<10;i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        output[cnt[(a[i]/exp)%10]-1] = a[i];
        cnt[(a[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
    {
        a[i] = output[i];
    }

    delete [] output;
}

void radix_sort(int *a,int n)
{
    int m,exp;

    m = max(a,n);

    //cout << m << endl;

    for(exp=1;m/exp!=0;exp*=10)
    {
        counting_sort(a,n,exp);
    }
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

    radix_sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete [] a;

    return 0;
}
