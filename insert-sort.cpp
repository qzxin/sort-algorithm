#include <iostream>
using namespace std;
void swap(int &A, int &B) {
    int temp = A; A = B; B = temp;
}

void InsertSort(int nums[], int left, int right) {
    if (nums == NULL || right-left+1 <= 0)
        return;
    for (int i = left; i < right; i++) {
        int j = i+1;
        int temp = nums[j];
        for (; j > left; j--) {
            if (temp >= nums[j-1])
                break;
            nums[j] = nums[j-1];
        }
        nums[j] = temp;
    }
}

int main() {
    int nums[] = {1,5,3,6,7,3,8,3,12,45,11};
    int len = sizeof(nums)/sizeof(nums[0]);
    InsertSort(nums, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}