#include<iostream>
using namespace std;

class Heap {
public:
    // Function to heapify an array into a max heap
    void heapifyMax(int arr[], int n, int i) {
        int largest = i;
        int lchild = 2 * i + 1;
        int rchild = 2 * i + 2;

        // Check if left child is larger than the root
        if (lchild < n && arr[lchild] > arr[largest])
            largest = lchild;

        // Check if right child is larger than the largest so far
        if (rchild < n && arr[rchild] > arr[largest])
            largest = rchild;

        // If largest is not root
        if (largest != i) {
            swap(arr[largest], arr[i]);
            // Recursively heapify the affected sub-tree
            heapifyMax(arr, n, largest);
        }
    }

    // Function to create a max heap
    void createHeapMax(int arr[], int n) {
        // Start from the last non-leaf node and heapify each node in reverse order
        for (int i = n / 2; i >= 0; i--) {
            heapifyMax(arr, n, i);
        }
    }

    // Function to heapify the array into a min heap
    void heapifyMin(int arr[], int n, int i) {
        int smallest = i;
        int lchild = 2 * i + 1;
        int rchild = 2 * i + 2;

        // Check if left child is smaller than the root
        if (lchild < n && arr[lchild] < arr[smallest])
            smallest = lchild;

        // Check if right child is smaller than the smallest so far
        if (rchild < n && arr[rchild] < arr[smallest])
            smallest = rchild;

        // If smallest is not root
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            // Recursively heapify the affected sub-tree
            heapifyMin(arr, n, smallest);
        }
    }

    // Function to create a min heap
    void createHeapMin(int arr[], int n) {
        // Start from the last non-leaf node and heapify each node in reverse order
        for (int i = n / 2; i >= 0; i--) {
            heapifyMin(arr, n, i);
        }
    }

    // Function to delete minimum element from a min heap
    void deleteMin(int arr[], int n) {
        // Swap the root with the last element, reduce heap size, and heapify the root
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMin(arr, i, 0);
        }
    }

    // Function to delete maximum element from a max heap
    void deleteMax(int arr[], int n) {
        // Swap the root with the last element, reduce heap size, and heapify the root
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMax(arr, i, 0);
        }
    }

    // Function to display elements of the array
    void display(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}; 

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Heap heap;

    // Creating and displaying the max heap
    heap.createHeapMax(arr, n);
    cout << "Max Heap: ";
    heap.display(arr, n);

    // Creating and displaying the min heap
    heap.createHeapMin(arr, n);
    cout << "Min Heap: ";
    heap.display(arr, n);

    // Deleting minimum element from min heap
    cout << "Deleting min element: ";
    heap.deleteMin(arr, n);
    heap.display(arr, n);

    // Deleting maximum element from max heap
    cout << "Deleting max element: ";
    heap.deleteMax(arr, n);
    heap.display(arr, n);

    return 0;
}
