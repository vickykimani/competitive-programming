// Given an unsorted array of size N, use selection sort to sort arr[] in increasing order

int select(int arr[], int i)
{
    int max = arr[0], ind = 0;
    int j;
    for (j = 1; j <= i; j++)
    {
        if (arr[j] > max)
        {
            ind = j;
            max = arr[j];
        }
    }
    return ind;
}

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = n - 1; i >= 0; i--)
    {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
    }
}