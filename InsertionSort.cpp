
#include<bits/stdc++.h>
using namespace std;
void inserton(int n,int arr[])
{
    int i,j;
    for(i=1; i<n; i++)
    {

        int k=arr[i];
        for(j=i-1; j>=0; j--)
        {

            if(arr[j]<k)
            {

                arr[j+1]=arr[j];

            }
            else
            {
                break;
            }

        }
        arr[j+1]=k;
    }
    cout<<"Sorted : ";
    for(int i=0; i<=n-1; i++)
    {

        cout<<arr[i]<<" ";
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >>arr[i];
    }
    inserton(n,arr);
    return 0;

}

