#include <iostream>
using namespace std;
void swap(int &A, int &B) {
    int temp = A; A = B; B = temp;
}
int Partation(int nums[], int left, int right) {
    int number = nums[left];
    int i = left+1, j = right;
    while(i < j) {
        while (nums[i] < number)
            i++;
        while (nums[j] > number)
            j--;
        if (j <= i)
            break;
        swap(nums[i], nums[j]);
        i++, j--;
    }
    swap(nums[left], nums[j]);
    return j;
}
void QuickSort(int nums[], int left, int right) {
    if (nums == NULL || left >= right)
        return;
    int index = Partation(nums, left, right);
    QuickSort(nums, left, index-1);
    QuickSort(nums, index+1, right);
}


int main() {
    int nums[] = {1,5,3,6,7,3,8,3,12,45,11};
    int len = sizeof(nums)/sizeof(nums[0]);
    QuickSort(nums, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}