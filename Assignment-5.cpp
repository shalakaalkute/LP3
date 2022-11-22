#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;
void swap1(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partitionDet(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i= (low- 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap1(&arr[i], &arr[j]);
		}
	}
	swap1(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSortDet(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partitionDet(arr, low, high);
		quickSortDet(arr, low, pi - 1);
		quickSortDet(arr, pi + 1, high);
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// Generate a random number in between
	// low .. high
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    int choice;
    cout<<"\n\t------Menu------"<<endl;
    cout<<"\tEnter 1 for Randomised Quick Sort"<<endl;
    cout<<"\tEnter 2 for Deterministic Quick Sort"<<endl;
    cout<<"\nEnter Choice: ";
    cin>>choice;
    if(choice==1){
        cout<<"\n\tBefore sorting :";
        printArray(arr,n);
        quickSort(arr, 0, n - 1);
        cout<<"\n\tSorted array using Ramdomised Quick Sort: ";
        printArray(arr, n);
        cout<<endl;
    }
    else if(choice==2){
        cout<<"\n\t Before sorting :";
        printArray(arr,n);
        quickSortDet(arr, 0, n - 1);
        cout<<"\n\tSorted array using Deterministic Quick Sort: ";
        printArray(arr, n);
        cout<<endl;
    }
    else{
        cout<<"Please enter valide choice :("<<endl;
    }
	// quickSort(arr, 0, n - 1);
	// cout<<"\n\tSorted array using Ramdomised Quick Sort: ";
	// printArray(arr, n);
    // quickSortDet(arr, 0, n - 1);
    // cout<<"\n\tSorted array using Deterministic  Quick Sort: ";
	// printArray(arr, n);
	// cout<<endl;
	return 0;
}
