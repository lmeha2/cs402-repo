
#include "Leona_Meharenna_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */



/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2



/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    // element is compared with the element adjacent to it, 
    // if the element is greater than the adjacent element, then the two elements are swapped
    int n = list.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (descending) {
                if (list[j] < list[j+1]) {
                    swap(list[j], list[j+1]);
                }
            } else {
                if (list[j] > list[j+1]) {
                    swap(list[j], list[j+1]);
                }
            }
        }

    } 
    cout<<"Bubble Sort Result: ";
    print_list(list);
}














/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    // Your code here!
    int n = list.size();
    for (int i = 0; i < n-1; i++) {
        int swap_idx = i; 
        //start from first unsorted element
        for (int j = i+1; j < n; j++)
        {
           if (!descending){
            if (list[j] < list[swap_idx]){
                swap_idx = j;
            }
           }
           else{
            if (list[j] > list[swap_idx]){
                swap_idx = j;
            }
           }
        }
        swap(list[i], list[swap_idx]);
        
    }
    cout << "Selection Sort Result: ";
    print_list(list);


}












/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    // Your code here!
    int n = list.size();
    for (int i = 1; i < n; i++){
        int key = list[i];
        int j = i - 1;
        if (!descending){
            while (j >= 0 && list[j] > key){
            list[j+1] = list[j];
            j-=1;
            } 
        }
        else{
            while (j >= 0 && list[j] < key){
                list[j+1] = list[j];
                j-=1;
            }
        
        }
        list[j+1] = key;
    }
    cout << "Insertion Sort Result: ";
    print_list(list);
}












/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */


template<typename T>
void quicksort(vector<T> &list, int low, int high, bool descending) {
    // Your code here!
    if (low < high){
        
        int p = partition(list, low, high, descending);

        quicksort(list, low, p - 1, descending);
        quicksort(list, p+1, high, descending);
    
    }
    
    
}

template<typename T>
int partition(vector<T> &list, int low, int high, bool descending){
    //pivot = random index + offset
    int pivot = low + get_rand_index(high-low+1);

    swap(list[pivot], list[high]);

    int i = low - 1;
    for (int j = low; j < high; j++){
        if (!descending){
            if (list[j] < list[high]){
                i+=1;
                swap(list[i], list[j]);
            }
        }
        else{
            if (list[j] > list[high]){
                i+=1;
                swap(list[i], list[j]);
            }
        }
    }

    //swap pivot into correct location in array, i+1

    swap(list[i+1], list[high]);
    return i+1;

}

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */


template<typename T>
vector<T>& quick_partition(vector<T> &list, int low, int high, bool descending) {
    // Your code here!
    //
    // You can use the helper function 
    //      unsigned int get_rand_index(unsigned int len)

    int pivot = list[high]; // pivot is at end of array

    int i = low - 1;

    for (int j = low; j < high; j++){
        if (!descending){
            if (list[j] < pivot){
                i+=1;
                swap(list[i], list[j]);
            }
        }
        else{
            if (list[j] > pivot){
                i+=1;
                swap(list[i], list[j]);
            }
        }
    }

    //swap pivot into correct location in array, i+1

    swap(list[i+1], list[high]);
    return list;
    
}










/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool decending) {
    // Your code here!
    int length = list.size();
    if (length <= 1) return;

    int middle = length/2;

    vector<T> left_vector;
    vector<T> right_vector;

    for (int i = 0; i < length; i++){
        if (i < middle){
            left_vector.push_back(list[i]);
        }
        else{
            right_vector.push_back(list[i]);
        }
    }
    merge_sort(left_vector, decending);
    merge_sort(right_vector, decending);
    merge(left_vector, right_vector, list, decending);
}


template<typename T>
void merge(vector<T> &left, vector<T> &right, vector<T> &list, bool descending){
    int leftSize = left.size();
    int rightSize = right.size();
    //indices for incrementing thru vectors

    int l = 0;
    int r = 0;
    int list_i = 0;
    if (!descending){
        while (l < leftSize && r < rightSize){
            if (left[l] < right[r]){
                list[list_i] = left[l];
                l+=1;
            }
            else{
                list[list_i] = right[r];
                r+=1;
            }
            list_i+=1;
        }
        while (l < leftSize){
            list[list_i] = left[l];
            l++;
            list_i++;
        }
         while (r < rightSize){
            list[list_i] = right[r];
            r++;
            list_i++;
        }
    }
    else{
        while (l < leftSize && r < rightSize){
            if (left[l] > right[r]){
                list[list_i] = left[l];
                l+=1;
            }
            else{
                list[list_i] = right[r];
                r+=1;
            }
            list_i+=1;
        }
        while (l < leftSize){
            list[list_i] = left[l];
            l++;
            list_i++;
        }
         while (r < rightSize){
            list[list_i] = right[r];
            r++;
            list_i++;
        }
    }
    
}









/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template<typename T>
void bucket_merge_sort(vector<T> &list, bool descending) {
    // Your code here!
    int b_m = list.size()-1;
    int sz = list.size();
    // 1) Create n empty buckets
    vector<vector<T>> buckets(list.size());
    int max_val = *max_element(list.begin(), list.end());
    int min_val = *min_element(list.begin(), list.end());
    // 2) Put array elements in different buckets
    for (int i = 0; i < sz; i++){
        // gotta normalize the values to avoid segmentation faults
        // list[i] - min_val shifts all vals so that minimum value becomes zero
        // / (max_val - min_val + 1) normalizes the values to a fraction between 0 and 1
        // * b_m scales down to valid bucket index
        int bucket_key = (int)((double)(list[i] - min_val) / (max_val - min_val + 1) * b_m);
        buckets[bucket_key].push_back(list[i]);
    }

    // 3) Sort individual buckets using quicksort
    for(int i = 0; i < buckets.size(); i++){
        if (buckets[i].size() > 1){
            quicksort(buckets[i], 0, buckets[i].size()-1, descending);
        }
        
    }

    // 4) merge all buckets together 
    list.clear();
    if (!descending){
        for (auto bucket : buckets){
            for (int x : bucket){
                list.push_back(x);
            }
        }
    }

    else{
        for (int i = buckets.size()-1; i >= 0; i--){
            for (int x : buckets[i]){
                list.push_back(x);
            } 
        }
    }



}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Your code here!

    //find max num
    int max_val = *max_element(list.begin(), list.end());
    //find num bits of max num
    int max_bits = 0;
    while (max_val > 0) {
        max_val >>= 1;
        max_bits++;
    }
    // 5 1 3 4 2 -> 101, 001, 011, 100, 010
    //first sort 4 2 5 1 3
    // 10 01 10 00 01
    // second sort 4 5 1 2 3
    // 100 101 001 010 011
    // 1 2 3 4 5
    for (int i = 0; i < max_bits; i++){
        vector<T> ones;
        vector<T> zeros;
        for (T x : list) {
            
            if ((x >> i) & 1){
                ones.push_back(x);
            }
            else{
                zeros.push_back(x);
            }
        }
        
        list.clear();
        if (!descending){
            list.insert(list.end(), zeros.begin(), zeros.end());
            list.insert(list.end(), ones.begin(), ones.end());
        }
        else{
            list.insert(list.end(), ones.begin(), ones.end());
            list.insert(list.end(), zeros.begin(), zeros.end());
            
        }
    }
}


/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    // Your code here!
    // merge sort + insertion sort
    // BIG O O(nlogn)
    // merge sort has runtime of O(nlogn)
    // insertion sort has an avg runtime of O(n^2) but we're running on chunks that are not dependent on n
    // so really you'd be getting an average run time of O(k^2), which is constant time
    if (list.size() <= 20) {
        insertion_sort(list, descending);
        return;
    }

 
    int mid = list.size() / 2;

    vector<T> left(list.begin(), list.begin() + mid);
    vector<T> right(list.begin() + mid, list.end());

    my_hybrid_sort(left, descending);
    my_hybrid_sort(right, descending);

    merge(left, right, list, descending);
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}






int main() {
    /**** STUDENT CODE HERE ****/ 






    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    std::srand(std::time({}));
    vector<int> test_list {4, 5, 3, 2, 1, 99};
    // bubble_sort(test_list, true);
    // selection_sort(test_list, true);
    // insertion_sort(test_list, true);
    // quicksort(test_list, 0, test_list.size()-1, false);
    // cout<<"Quicksort Result";
    // print_list(test_list);
    // merge_sort(test_list, false);
    // cout<<"Merge Sort Result";
    // print_list(test_list);
    // bucket_merge_sort(test_list);
    // cout << "BM Sort Result: ";
    // print_list(test_list);
    //bucket_merge_sort(test_list);
    // binary_radix_sort(test_list, true);
    // cout << "brs list: ";
    // print_list(test_list);
    my_hybrid_sort(test_list, true);
    cout << "mhs list: ";
    print_list(test_list);
    //radix_sort(test_list);

    //thank god
    return 0;
}









