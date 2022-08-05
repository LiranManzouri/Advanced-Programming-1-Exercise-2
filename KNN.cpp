#include "KNN.h"

using namespace std;


/**
 * It takes an array of pairs of flowers and distances, and returns the index of the pivot element
 * Args:
 *   arr (pair<Flower *, double>): the array of pairs of flowers and their distances from the flower
 * Returns:
 *   The index of the pivot.
 */
int KNN::partition(pair<Flower *, double> *arr, int left, int right, int pivot) {
    //gets the pivot to the right place in O(N), using swaps
    double x = arr[pivot].second;
    swap(arr[pivot], arr[right]);
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j].second <= x) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[right], arr[i]);
    return i;
}

/**
 * It takes an array of pairs of flowers and distances, and sorts the array so that the first k
 * elements are the k smallest distances
 * 
 * Args:
 *   k (int): the kth smallest element we want to find
 *   arr (pair<Flower *, double>): the array of pairs of flowers and their distances
 * 
 * Returns:
 *   the index of the pivot after the partition.
 */
void KNN::QuickSelect(int k, pair<Flower *, double> *arr, int left, int right) {
    if (left == right) {
        return;
    }
    // takes the middle as the pivot and does the partition around it
    int pivotIndex = left + (right - left) / 2;
    pivotIndex = partition(arr, left, right, pivotIndex);
    if (pivotIndex == k) {
        return;
    }
    if (k < pivotIndex) {
        return QuickSelect(k, arr, left, pivotIndex - 1);
    }
    return QuickSelect(k, arr, pivotIndex + 1, right);
}
