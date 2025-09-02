#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> partition(vector<int>& arr, int low, int high) {
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);

    int p = arr[low];
    int q = arr[high];

    int i = low + 1;
    int k = low + 1;
    int j = high - 1;

    while (k <= j) {
        if (arr[k] < p) {
            swap(arr[k], arr[i]);
            i++;
        } else if (arr[k] >= q) {
            while (arr[j] > q && k < j) j--;
            swap(arr[k], arr[j]);
            j--;
            if (arr[k] < p) {
                swap(arr[k], arr[i]);
                i++;
            }
        }
        k++;
    }

    i--; j++;
    swap(arr[low], arr[i]);
    swap(arr[high], arr[j]);

    return {i, j};
}

void dualPivotQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        pair<int, int> pivots = partition(arr, low, high);
        dualPivotQuickSort(arr, low, pivots.first - 1);
        dualPivotQuickSort(arr, pivots.first + 1, pivots.second - 1);
        dualPivotQuickSort(arr, pivots.second + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 7, 2, 9, 1, 5};
    dualPivotQuickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
