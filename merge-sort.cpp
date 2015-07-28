#include <iostream>
using namespace std;
void Merge(int nums[], int left, int mid, int right);
void MergeSort(int nums[], int left, int right) {
    if (nums == NULL || right <= left)
        return;
    int mid = (left+right) >> 1;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid+1, right);
    Merge(nums, left, mid, right);
}
void Merge(int nums[], int left, int mid, int right) {
    int len = right - left + 1;
    int* temp = new int[len];
    int i = left, j = mid+1;
    int k = 0;
    while(i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    } 
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    // copy
    for (k = 0; k < len; k++) {
        nums[left+k] = temp[k];
    }
    delete temp;
}

int main() {
    int nums[] = {1,5,3,6,7,3,8,3,12,45,11};
    int len = sizeof(nums)/sizeof(nums[0]);
    MergeSort(nums, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}