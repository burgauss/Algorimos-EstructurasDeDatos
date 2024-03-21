#include <iostream>
#include <cmath>

using namespace std;

template <class T>
void Print(T& vec, int n, string s) {  /// This Function is printing the elements in [e1,e2,.....,en] format
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Max(int A[], int n) {  /// This Function is Finding the Maximum Element by initializing the least integer
    int max = -32768;
    for (int i = 0; i < n; i++) { /// for all n elements process is repeated
        if (A[i] > max) {   /// compare each element, if found Max, 
            max = A[i];  /// then replace
        }
    }
    return max;   /// return Maximum element
}

// Linked List node
class Node {  /// A class for Node with element and a pointer to point to next node
public:
    int value;
    Node* next;
};

int countDigits(int x) {  /// This Function Counts the Digits
    int count = 0;  /// Initialize the count to 0
    while (x != 0) { /// repeat until 0 
        x = x / 10;   /// divide to get the Quotient
        count++; /// increment the count
    }
    return count;  /// return the count
}

void initializeBins(Node** p, int n) {  /// This Function is to initialize the array of pointer named as Bin
    for (int i = 0; i < n; i++) { /// all the memory locations
        p[i] = nullptr;  /// are initialized to null values
    }
}

void Insert(Node** ptrBins, int value, int idx) { /// This Function Insert the value with given index
    Node* temp = new Node;  /// create a temp pointer and allocate the memory and stores the address of the node
    temp->value = value;  /// assign value
    temp->next = nullptr;  /// assign pointer Null

    if (ptrBins[idx] == nullptr) { /// Now, if nothing is there
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr  /// then store the node in Bin with given Index
    }
    else {
        Node* p = ptrBins[idx]; /// other wise iterate in the list to insert at appropriate place
        while (p->next != nullptr) { /// traverse till null
            p = p->next; /// used for traversal
        }
        p->next = temp; /// insert the node
    }
}

int Delete(Node** ptrBins, int idx) { /// This Function is used to delete the nodes from the Bin woth given Index
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next; /// attach the pointer to the next node
    int x = p->value; /// get the value of the node to be deleted
    delete p; /// delete the node
    return x; /// and return the value
}

int getBinIndex(int x, int idx) { /// This function is used to know the exact position of the Bin wih given Index
    return (int)(x / pow(10, idx)) % 10; /// calculate the Index using power function and 10 is for decimal number
}

void RadixSort(int A[], int n) { /// This is the Actual Function using and calling all other Functions
    int max = Max(A, n); /// This logic is explained in the form of Algorithm, please refer
    int nPass = countDigits(max);

    // Create bins array
    Node** bins = new Node * [10];

    // Initialize bins array with nullptr
    initializeBins(bins, 10);

    // Update bins and A for nPass times
    for (int pass = 0; pass < nPass; pass++) {

        // Update bins based on A values
        for (int i = 0; i < n; i++) {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10) {
            while (bins[i] != nullptr) {
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }

    // Delete heap memory
    delete[] bins;
}

int main() {

    int A[] = { 237, 146, 259, 348, 152, 163, 235, 48, 36, 62 };
    int n = sizeof(A) / sizeof(A[0]); /// Calculating the number of elements

    Print(A, n, "\t\tA");
    RadixSort(A, n);  /// Calling Radix Sort
    Print(A, n, " Sorted A"); /// displaying the sorted elements

    return 0;
}