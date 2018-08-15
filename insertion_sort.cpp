#include<iostream>
using namespace std;

void insertion_sort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int item = a[i];

        int j = i-1;

        while(j>=0 && a[j]>item)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = item;
    }
}

int main(void)
{
    int n;

    cout << "Enter the size of array:" << endl;
    cin >> n;

    int *a = new int [n];

    cout << "Enter the elements:" << endl;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    insertion_sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    delete [] a;

    return 0;
}
