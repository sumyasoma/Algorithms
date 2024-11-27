////9 4 8 11 15 20 2 24 30 1 35
#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    while (i < j)
    {
        while (A[i] <= pivot && i < h)
            i++;
        while (A[j] > pivot && j > l)
            j--;
        if (i < j)
        {

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    quickSort(A, 0, n - 1);
    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

