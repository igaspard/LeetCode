#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
 public:
    static int search(const vector<int>& arr, int key) {
      int left = 0, right = (int)arr.size() - 1;
      
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (arr[mid] == key) return mid;
          else if (arr[mid] > key) right = mid - 1;
          else if (arr[mid] < key) left = mid + 1;
      }

      return -1;
    }

    static int left_bound(const vector<int> &arr, int key) {
        int left = 0, right = (int) arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) right = mid - 1; // don't return, find the left side
            else if (arr[mid] < key) left = mid + 1;
            else if (arr[mid] > key) right = mid - 1;
        }
        // check the left out of boundary
        if (left >= arr.size() || arr[left] != key)
            return -1;
        return left;
    }
    
    static int right_bound(const vector<int> &arr, int key) {
        int left = 0, right = (int) arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) left = mid + 1; // don't return, find the right side
            else if (arr[mid] < key) left = mid + 1;
            else if (arr[mid] > key) right = mid - 1;
        }
        // check the right out of boundary
        if (right < 0 || arr[right] != key)
            return -1;
        return right;
    }

    static int ceiling(const vector<int> &arr, int key) {
        int left = 0, right = (int)arr.size() - 1;
        if (key > arr[right]) return -1;
      
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) right = mid - 1;
            else if (arr[mid] < key) left = mid + 1;
        }

        return left;
    }

    static int floor(const vector<int> &arr, int key) {
        int left = 0, right = (int)arr.size() - 1;
        if (key < arr[left]) return -1;
      
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) right = mid - 1;
            else if (arr[mid] < key) left = mid + 1;
        }

        return right;
    }
};

int main(int argc, char* argv[]) {
    cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5}, 2) << endl;
    cout << BinarySearch::left_bound(vector<int>{1, 2, 2, 2, 3}, 2) << endl;
    cout << BinarySearch::right_bound(vector<int>{1, 2, 2, 2, 3}, 2) << endl;
    cout << BinarySearch::ceiling(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
    cout << BinarySearch::floor(vector<int>{1, 3, 8, 10, 15}, 12) << endl;

    return 0;
}