#include<iostream>
using namespace std;

int min(int*a,int sz);

void c_sort(int *a,int s,int sz)
{
    int *cnt = new int[s];
    int *output = new int[sz];

    for(int i=0;i<s;i++)
    {
        cnt[i] = 0;
    }

    for(int i=0;i<sz;i++)
    {
        cnt[a[i]-min(a,sz)]++;
    }

    for(int i=1;i<s;i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(int i=0;i<sz;i++)
    {
        output[cnt[a[i]-min(a,sz)]-1] = a[i];
        cnt[a[i]-min(a,sz)]--;
    }

    for(int i=0;i<sz;i++)
    {
        a[i] = output[i];
    }

    /*
    int j = 0;

    for(int i=1;i<sz;i++)
    {
        cnt[i]+=cnt[i-1];
    }

    for(int i=0;i<sz;i++)
    {
        a[cnt[i]]
    }*/


    delete [] cnt;
    delete [] output;

}

int max(int *a,int sz)
{
    int m = a[0];
    for(int i=0;i<sz;i++)
    {
        if(a[i]>m) m = a[i];
    }

    return m;
}

int min(int *a,int sz)
{
    int m = a[0];
    for(int i=0;i<sz;i++)
    {
        if(a[i]<m) m = a[i];
    }

    return m;
}

int main(void)
{
    int sz;

    cout << "Enter the size of array:" << endl;
    cin >> sz;

    int *a = new int[sz];

    cout << "Enter the elements:" << endl;

    for(int i=0;i<sz;i++)
    {
        cin >> a[i];
    }

    int m = max(a,sz)- min(a,sz)+1;

    //cout  << m << endl;

    c_sort(a,m,sz);

    for(int i=0;i<sz;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete [] a;

    return 0;
}
