#include <iostream>
using namespace std;
void swap(int &A, int &B) {
    int temp = A; A = B; B = temp;
}

void QuickSort(int a[], int l, int r) {
    // 直接交换法
    if (a == NULL || l >= r)
        return;
    int pivot = a[l]; //选最左侧为基元
    int i = l;
    int j = r+1;
    while (i < j) {
        while (i < r && a[++i] < pivot);
        while (a[--j] > pivot); // a[j]向左不会穿过a[l]
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[j], a[l]); //右指针是基元交换的位置
    QuickSort(a, l, j-1);
    QuickSort(a, j+1, r);
}

void QuickSort2(int a[], int l, int r) {
    // 挖坑填坑法
    if(l >= r)
        return;
    int i = l;
    int j = r;
    int pivot = a[i]; // 左边先挖坑
    while (i < j) {
        while (i < j && a[j] > pivot)
            j--;
        if (i < j) {
            a[i++] = a[j]; // 填左坑，挖右坑
        }
        while (i < j && a[i] < pivot)
            i++;
        if (i < j) {
            a[j--] = a[i]; // 填右坑，挖左坑
        }
    }
    a[j] = pivot; // 因为最先挖的左坑，最后填右坑
    QuickSort2(a, l, j-1);
    QuickSort2(a, j+1, r);
}


int main() {
    int nums1[] = {1,5,3,6,7,3,3,3,3,8,5,5,5,3,12,45,11};
    int nums2[] = {1,5,3,6,7,3,3,3,3,8,5,5,5,3,12,45,11};
    int len = sizeof(nums1)/sizeof(nums1[0]);
    QuickSort(nums1, 0, len-1);
    QuickSort2(nums2, 0, len-1);
    for (int i = 0; i < len; i++) 
        cout << nums1[i] << " ";
    cout << endl;
    for (int i = 0; i < len; i++) 
        cout << nums2[i] << " ";
    cout << endl;
}