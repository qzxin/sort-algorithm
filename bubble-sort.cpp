#include <iostream>
using namespace std;
void swap(int &A, int &B) {
    int temp = A; A = B; B = temp;
}

void BubbleSort(int nums[], int left, int right) {
    if (nums == NULL || right-left+1 <= 0)
        return;
    for (int i = left; i < right; i++) {
        for (int j = i+1; j <= right-(i-left); j++) {
            if (nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
            }
        }
    }
}

int main() {
    int nums[] = {1,5,3,6,7,3,8,3,12,45,11};
    int len = sizeof(nums)/sizeof(nums[0]);
    BubbleSort(nums, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}