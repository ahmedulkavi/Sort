#include<iostream>
#include<utility>
using namespace std;

int partition(int *a,int l,int h)
{
    int pivot = a[h],i,j;

    for(i=l-1,j=l;j<h;j++)
    {
        if(pivot>a[j])
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[h]);

    return i+1;
}

void quick_sort(int *a,int l,int h)
{
    if(l>=h)
    {
        return;
    }

    int p = partition(a,l,h);

    quick_sort(a,l,p-1);

    quick_sort(a,p+1,h);

}

int main(void)
{
    int n;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int *a = new int[n];

    cout << "Enter the elements:" << endl;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    quick_sort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete [] a;

    return 0;
}
