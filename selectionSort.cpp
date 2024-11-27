#include<iostream>
using namespace std;

void selection(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int Min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[Min])
            {
                Min = j;
            }
        }
        int temp = arr[Min];
        arr[Min] = arr[i];
        arr[i] = temp;
    }

    cout << "Sorted : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection(n, arr);
    return 0;
}
