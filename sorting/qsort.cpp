#include <iostream>
using namespace std;
int sequence[] = {-1, 3, 7, 1, 12, 10};
void swapElement(int, int);

int partition(int start, int end) {
    
    int leftBound = start, rightBound = end;
    int pivot = sequence[start];

    end++;
    while (true) {
        while (sequence[++start] <= pivot) {
            if (start >= rightBound) {
                break;
            }
        }
        while (sequence[--end] >= pivot) {
            if (end <= leftBound) {
                break;
            }
        }

        if (start >= end) {
            break;
        }
        swapElement(start, end);        
    }

    swapElement(leftBound, end);
    return end;
}

void qsort(int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = partition(start, end);
    qsort(start, mid-1);
    qsort(mid+1, end);
}
void swapElement(int leftIndex, int rightIndex) {
    int temp = sequence[leftIndex];
    sequence[leftIndex] = sequence[rightIndex];
    sequence[rightIndex] = temp;
}

int main() {
    int size = sizeof(sequence)/sizeof(sequence[0]);
    qsort(0, size-1);
    for (int i = 0; i < size; ++i) {
        cout << sequence[i] << endl;
    }
    return 0;
}