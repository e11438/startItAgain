#include <iostream>

using namespace std;

static int numOfSwaps = 0;
static int numOfIterations = 0;

void swap(int * x, int * y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void insertionSort(int * arr, int n)
{
    if(!n) return;
    for(int i = 1; i < n ; ++i)
    {
        int currElem = arr[i];
        int j = i -1;
        while(j >= 0 && (arr[j] > currElem) )
        {
            numOfIterations++;
            arr[j+1] = arr[j]; 
            j--;

        }
        arr[j+1] = currElem;
        numOfSwaps++;
    }
    

}

void printArray(string str, int * arr, int n)
{
    //size_t len = sizeof(arr)/sizeof(arr[0]);
    //cout <<  "len - " << len<< endl;
    cout << str << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}


int main()
{
    cout << "selection sort" << endl;

    int arr[] = {2, 4, 3, 1, 8, 6, 5};

    size_t len = sizeof(arr)/sizeof(arr[0]);

    cout <<  "len of array - " << len<< endl;

    printArray( "Array before sorting ",arr, len);

    insertionSort(arr, len);

    printArray( "Array after sorting ",arr, len);

    cout << "numOfSwaps " << numOfSwaps << " numOfIterations " << numOfIterations << endl;
    return 0;
}

