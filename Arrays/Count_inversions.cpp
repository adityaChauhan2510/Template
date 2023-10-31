/*
Given a sequence of n numbers 1..n (assume all numbers are distinct). 
Define a measure that tells us how far this list is from being in ascending order.

For all i & j < size of array, if i < j and  A[j] < A[i], this is called inversion.


                ALGORITHM TO COUNT INVERSIONS(Use divide and conquer)


divide: size of sequence n to two lists of size n/2
conquer: count recursively two lists
combine:  this is a trick part (to do it in linear time)

combine use merge-and-count. Suppose the two lists are A, B.  
Produce an output list L from A, B while also counting the number of inversions, 
(a,b) where a is-in A, b is-in B and a > b.

*/


#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   

    
    int cntInv = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);

            cntInv += (mid - left + 1); 

            right++;
        }
    }


    // if elements on the left half are still left 
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr 
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cntInv; 
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}



int numberOfInversions(vector<int>&a, int n) {

   
    return mergeSort(a, 0, n - 1);
}



int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: " << cnt << endl;
    return 0;
}
