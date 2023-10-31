#include<bits/stdc++.h>
using namespace std;


//SELECTION SORT--->TC(N^2)
void selection_sort(int arr[], int n) {
  // selection sort
  for (int i = 0; i <= n - 2; i++) {
    int miniIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[miniIdx]) {
        miniIdx = j;
      }
    }
    swap(arr[i], arr[miniIdx]);
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}




//BUBBLE SORT
/*
Repeatedly swap 2 adjacent elements if they are in wrong position.
TC--->O(N^2)
*/

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < n-i; j++) {
            if (arr[j] > arr[j + 1]) {
                
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
INSERTION SORT
Insert an element from unsorted array to correct position in sorted array.

Worst case ---> O(n^2)
Best case  ---> O(n), when array is sorted.
*/

void insertion_sort(int arr[], int n) {

    for (int i = 1; i <n; i++) {
        int curr = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > curr) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curr;
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}



/*
MERGE SORT

TC---> O(nlogn)
SC--->O(n) + O(n)->stack space
*/

void merge(int arr[], int start, int mid, int end){
    
    int* b = new int[end+1];
    
    int i = start;
    int j = mid+1;
    int k = start;
    
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            b[k++] = arr[i++];
            
        }
        else{
            b[k++] = arr[j++];
        }
    }

    while(i <= mid){
        b[k++] = arr[i++];
    }

    while(j <= end){
        b[k++] = arr[j++];
    }
    
    //copying b array to arr array
    for(int i = start; i <= end; i++){
        arr[i] = b[i];    
    }
    
    delete[] b;
}

void helper(int arr[], int start, int end){
    
    //base case
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    
    helper(arr, start, mid);
    helper(arr, mid+1, end);
    
    merge(arr, start, mid, end);
}

void merge_sort(int arr[], int n){
	// Write your code here
    int start = 0;
    int end = n -1;
    
    helper(arr, start, end);

    cout << "After Using merge sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
}




/*
QUICK SORT
TC---> O(nlogn), no extra space

Worst case, time complexity--> O(n2), when pivot is first or last element

F(n) = F(k) + F(n-1-k), k  is num of elements smaller or equal to pivot.

*/

int partition(int arr[], int start, int end){
    
    int count = 0;
    for(int i = start+1; i<=end; i++){
        if(arr[i] <= arr[start]){
            count++;
        }
    }
    
    int idx = start + count;
    
    int temp = arr[start];
    arr[start] = arr[idx];
    arr[idx] = temp;
    
    
    int i = start;
    int j = end;
    
    while(i < idx && j > idx){
        
        if(arr[i] <= arr[idx]){
        	i++;
    	}
    	else if(arr[j] > arr[idx]){
        	j--;
    	}
    	else{
        	int temp = arr[i];
        	arr[i] = arr[j];
        	arr[j] = temp;
            i++;
            j--;
    	}
        
    }
    
    return idx;
    
    
    
}

void Quicksort(int arr[], int start, int end){
    
    //base case
    if(start >= end){
        return;
    }
    
    int pIdx = partition(arr, start, end);
    
    Quicksort(arr, start, pIdx - 1);
    Quicksort(arr, pIdx + 1, end);
}

void quick_sort(int arr[], int n) {
    
    Quicksort(arr, 0, n-1);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
  
}




int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before sorting : " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  quick_sort(arr, n);
  return 0;
}