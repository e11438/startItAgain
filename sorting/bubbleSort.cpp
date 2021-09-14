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

void bubbleSort(int * arr, int n)
{
    if(!n) return;
    for(int i = 0; i < n ; ++i)
    {
        bool swaped = false;
        for(int j = 0; j < n - 1; ++j)
        {
            numOfIterations++;
            
            if(arr[j] > arr[j+1])
            {
                numOfSwaps++;
                swap(&arr[j], &arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped) break; 
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
    cout << "bubble sort" << endl;

    int arr[] = {2, 4, 3, 1, 8, 6, 5};

    size_t len = sizeof(arr)/sizeof(arr[0]);

    cout <<  "len of array - " << len<< endl;

    printArray( "Array before sorting ",arr, len);

    bubbleSort(arr, len);

    printArray( "Array after sorting ",arr, len);

    cout << "numOfSwaps " << numOfSwaps << " numOfIterations " << numOfIterations << endl;
    return 0;
}

