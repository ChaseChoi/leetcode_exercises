#include <iostream>
using namespace std;
int sequence[] = {-1, 3, 7, 1, 12, 10};
int copyed[20];

void merge(int start, int mid, int end) {
    for (int j = start; j <= end; ++j) {
        copyed[j] = sequence[j];
    }
    int left = start, right = mid + 1;
    for (int i = start; i <= end; ++i) {
        if (left > mid) {
            sequence[i] = copyed[right++];
        } else if (right > end) {
            sequence[i] = copyed[left++];
        } else if (copyed[left] < copyed[right]) {
            sequence[i] = copyed[left++];
        } else {
            sequence[i] = copyed[right++];
        }
    }
}

void mergeSort(int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (end + start) / 2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end);
}

int main() {
    int size = sizeof(sequence)/sizeof(sequence[0]);
    mergeSort(0, size);
    for (int i = 0; i < size; ++i) {
        cout << sequence[i] << endl;
    }
}