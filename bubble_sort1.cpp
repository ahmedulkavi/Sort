#include<iostream>
#include<utility>
using namespace std;

void bubble_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]) swap(a[i],a[j]);
        }
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

    bubble_sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete [] a;

    return 0;
}
