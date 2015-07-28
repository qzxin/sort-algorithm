#include <iostream>
using namespace std;
void swap(int &A, int &B) {
    int temp = A; A = B; B = temp;
}

void SelectSort(int nums[], int left, int right) {
    if (nums == NULL || right-left+1 <= 0)
        return;
    for (int i = left; i < right; i++) {
        int min_value = nums[i];
        int min = i;
        for (int j = i+1; j <= right; j++) {
            if (nums[j] < min_value) {
                min_value = nums[j];
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

int main() {
    int nums[] = {1,5,3,6,7,3,8,3,12,45,11};
    int len = sizeof(nums)/sizeof(nums[0]);
    SelectSort(nums, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}