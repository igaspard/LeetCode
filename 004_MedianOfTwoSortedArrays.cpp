#include <iostream>

using namespace std;

double findMedianOfTwoSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int MergedSize = nums1Size + nums2Size;
  int m[MergedSize];
  int i, i1, i2;
  for (i = 0, i1 = 0, i2 = 0; i1 < nums1Size && i2 < nums2Size; i++) {
    if (nums1[i1] <= nums2[i2]) {
      m[i] = nums1[i1++];
    } else {
      m[i] = nums1[i2++];
    }
  }
  if (i1 < nums1Size) {
    for (int j = i1; j < nums1Size; j++)
      m[i++] = nums1[j];
  }
  if (i2 < nums2Size) {
    for (int j = 0; j < nums2Size; j++)
      m[i++] = nums2[j];
  }
  // Show the merged Arrays
  // for (int j = 0; j < MergedSize; j++)
  //   cout<<m[j]<<" ";
  // cout<<endl;

  if (MergedSize % 2) {
    return m[MergedSize/2];
  } else {
    return (m[MergedSize/2-1] + m[MergedSize/2]) / 2.0;
  }
}

int main(int argc, char const *argv[]) {
  cout<<"LeetCode 4. Median Of Two sorted Arrays!"<<endl;
  int a[2] = {1, 2};
  int b[2] = {3, 4};
  cout<<findMedianOfTwoSortedArrays(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int))<<endl;
  return 0;
}
