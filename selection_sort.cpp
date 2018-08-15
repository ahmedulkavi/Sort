#include<iostream>
#include<utility>
using namespace std;

void selection_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int index_min = i;
        // Here we assume the i'th element is lowest value and start our comparison

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[index_min])
            {
                index_min = j;
            }

        }

            if(index_min!=i)
            {
                /* Here i'th element and minimum element has to be swapped
                We can use swap function if header file <utility> is included*/

                // Like this
                swap(a[i],a[index_min]);

                /*But currently we are using a temporary variable to do manual swap*/

                /*int temp = a[i];
                a[i] = a[index_min];
                a[index_min] = temp;*/
            }

    }
}

int main(void)
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    // n is the size of the array

    //cout << n << endl;

    int *a = new int[n];

    cout << "Enter the elements:" << endl;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    selection_sort(a,n);

    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            cout << a[i] << endl;
            break;
        }

        cout << a[i] << " ";
    }

    /*char ch;
    cout << "Press enter to exit:" << endl;
    cin.get(ch);
    cin.get(ch);*/

    delete [] a;

    return 0;
}
