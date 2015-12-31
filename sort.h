#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#endif // SORT_H_INCLUDED
//Warning: do not delete the vector library, as this class relies on it for passing arrays to functions
#ifndef _GLIBCXX_VECTOR
    #include <vector>
#endif // _GLIBCXX_VECTOR
using namespace std;

//The return type of each sorting function is a vector, so for display of the vector, use a loop
//Time measurements take part of vector of 3.765, 436.2, 67.234, 456.23, 67.345, 1.689, 0.0001 and 8.32848
class mySort {
    private:
        void merge(vector<int>& arr, const int low, const int mid, const int high) {
            int* b = new int[high + 1 - low];
            int h, i, j, k;
            h = low;
            i = 0;
            j = mid + 1;
            while((h <= mid) && (j <= high)) {
                if(arr[h] <= arr[j]) {
                    b[i] = arr[h];
                    h++;
                }
                else {
                    b[i] = arr[j];
                    j++;
                }
                i++;
            }
            if(h > mid) {
                for(k = j; k <= high; k++) {
                    b[i] = arr[k];
                    i++;
                }
            }
            else {
                for(k = h; k <= mid; k++) {
                    b[i] = arr[k];
                    i++;
                }
            }
            for(k = 0; k <= high - low; k++) {
                arr[k + low] = b[k];
            }
            delete[] b;
        }
        void merge_sorttemp(vector<int>& arr, const int low, const int high ) {
            int mid;
            if(low < high) {
                mid = (low + high) / 2;
                this->merge_sorttemp(arr, low, mid);
                this->merge_sorttemp(arr, mid + 1, high);
                this->merge(arr, low, mid, high);
            }
        }
        void merge(vector<double>& arr, const double low, const double mid, const double high) {
            double b[(int)(high + 1 - low)];
            int h, i, j, k;
            h = low;
            i = 0;
            j = mid + 1;
            while((h <= mid) && (j <= high)) {
                if(arr[h] <= arr[j]) {
                    b[i] = arr[h];
                    h++;
                }
                else {
                    b[i] = arr[j];
                    j++;
                }
                i++;
            }
            if(h > mid) {
                for(k = j; k <= high; k++) {
                    b[i] = arr[k];
                    i++;
                }
            }
            else {
                for(k = h; k <= mid; k++) {
                    b[i] = arr[k];
                    i++;
                }
            }
            for(k = 0; k <= high - low; k++) {
                arr[k + low] = b[k];
            }
            delete[] b;
        }
        void merge_sorttemp(vector<double>& arr, const double low, const double high ) {
            double mid;
            if(low < high) {
                mid = (low + high) / 2;
                this->merge_sorttemp(arr, low, mid);
                this->merge_sorttemp(arr, mid + 1, high);
                this->merge(arr, low, mid, high);
            }
        }
        double partition(vector<double>& arr, double p, double r) {
            double q = p;
            for(double u = p; u < r; u++) {
                if (arr[u] <= arr[r]) {
                    double temp = arr[u];
                    arr[u] = arr[q];
                    arr[q] = temp;
                    q++;
                }
            }
            double tem = arr[q];
            arr[q] = arr[r];
            arr[r] = tem;
            return q;
        }
        void quicksorttemp(vector<double>& arr, double p, double r) {
            if(p < r) {
               double q = this->partition(arr, p, r);
               quicksorttemp(arr, p, q - 1);
               quicksorttemp(arr, q + 1, r);
            }
        }
        double partition(vector<int>& arr, int p, int r) {
            int q = p;
            for(int u = p; u < r; u++) {
                if (arr[u] <= arr[r]) {
                    int temp = arr[u];
                    arr[u] = arr[q];
                    arr[q] = temp;
                    q++;
                }
            }
            int tem = arr[q];
            arr[q] = arr[r];
            arr[r] = tem;
            return q;
        }
        void quicksorttemp(vector<int>& arr, int p, int r) {
            if(p < r) {
               int q = this->partition(arr, p, r);
               quicksorttemp(arr, p, q - 1);
               quicksorttemp(arr, q + 1, r);
            }
        }
    public:
        //Bubblesort, the most simple of all sorts, will sort by looking at two values at a time and swapping values if they are in the wrong order.
        //Time = 19ms
        vector<double> bubbleSortOf(vector<double> arr) {
            int swaps = 0;
            double tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
            return arr;
        }
        void bubbleSort(vector<double> &arr) {
            int swaps = 0;
            double tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
        }
        vector<float> bubbleSortOf(vector<float> arr) {
            int swaps = 0;
            float tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
            return arr;
        }
        void bubbleSort(vector<float> &arr) {
            int swaps = 0;
            float tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
        }
        vector<int> bubbleSortOf(vector<int> arr) {
            int swaps = 0;
            int tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
            return arr;
        }
        void bubbleSort(vector<int> &arr) {
            int swaps = 0;
            int tj;
            for (int j = 0; j < arr.size(); j++) {
                for (int i = 0; i < arr.size(); i++) {
                    if (arr[j] < arr[i]) {
                        tj = arr[j];
                        arr[j] = arr[i];
                        arr[i] = tj;
                        swaps++;
                    }
                }
                if (swaps == 0) {
                    break;
                } else {
                    swaps = 0;
                }
            }
        }
        //Selection sort sorts by selecting the smallest value that has not yet been sorted and swapping it with the current value,
        //which will be looped through the array.
        //Time = 18ms
        vector<double> selectionSortOf(vector<double> arr) {
            int minimum;
            double ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
            return arr;
        }
        void selectionSort(vector<double> &arr) {
            int minimum;
            double ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
        }
        vector<float> selectionSortOf(vector<float> arr) {
            int minimum;
            float ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
            return arr;
        }
        void selectionSort(vector<float> arr) {
            int minimum;
            float ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
        }
        vector<int> selectionSortOf(vector<int> arr) {
            int minimum, ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
            return arr;
        }
        void selectionSort(vector<int> &arr) {
            int minimum, ti;
            for (int i = 0; i < arr.size(); i++) {
                minimum = i;
                for (int j = i; j < arr.size(); j++) {
                    if (arr[j] < arr[minimum]) {
                        minimum = j;
                    }
                }
                if (minimum != i) {
                    ti = arr[i];
                    arr[i] = arr[minimum];
                    arr[minimum] = ti;
                }
            }
        }
        //Insertion sort sorts by finding whether the value is smaller than any other previously sorted value, and if it has,
        //shifts every value after where the value is meant to be inserted up by one and inserts the value into the now empty spot.
        //Time = 16ms
        vector<double> insertionSortOf(vector<double> arr) {
            int j;
            double temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
            return arr;
        };
        void insertionSort(vector<double> &arr) {
            int j;
            double temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
        };
        vector<float> insertionSortOf(vector<float> arr) {
            int j;
            float temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
            return arr;
        };
        void insertionSort(vector<float> &arr) {
            int j;
            float temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
        };
        vector<int> insertionSortOf(vector<int> arr) {
            int j, temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
            return arr;
        };
        void insertionSort(vector<int> &arr) {
            int j, temp;
            for (int i = 1; i < arr.size(); i++){
                j = i;
                while (j > 0 && arr[j] < arr[j-1]){
                      temp = arr[j];
                      arr[j] = arr[j - 1];
                      arr[j - 1] = temp;
                      j--;
                }
            }
        };
        //Counting sort is useful when you array is full of integers and the difference between the minimum and maximum values are
        //not large. It works by adding one to the value of the index (of the value it is looping through) and displaying that index the number
        //of times the value of it is. Counting sort is the most efficient sort for just integral values.
        /*vector<int> countingSortOf(vector<int> arr, int min, int max) {
            min--;
            max++;
            vector<int> table, result, negtable;
            int index, value;
            if (min < 0) {
                for (int m = min; m <= 0; m++) {
                    negtable.push_back(0);
                }
            }
            for (int j = min; j <= max + 1; j++) {
                table.push_back(0);
            }
            for (int i = 0; i < arr.size(); i++) {
                value = arr[i];
                if (value < 0) {
                    negtable[-value]++;
                } else {
                    table[value]++;
                }
            }
            if (min < 0) {
                for (int n = negtable.size() - 1; n > 0; n--) {
                    value = negtable[n];
                    if (value != 0) {
                        for (int m = 0; m < value; m++) {
                            result.push_back(-n);
                        }
                    }
                }
            }
            for (int k = 0; k < table.size(); k++) {
                value = table[k];
                if (value != 0) {
                    for (int l = 0; l < value; l++) {
                        result.push_back(k);
                    }
                }
            }
            return result;
        }
        void countingSort(vector<int> &arr, int min, int max) {
            min--;
            max++;
            vector<int> table, result, negtable;
            int index, value;
            if (min < 0) {
                for (int m = min; m <= 0; m++) {
                    negtable.push_back(0);
                }
            }
            for (int j = min; j <= max + 1; j++) {
                table.push_back(0);
            }
            for (int i = 0; i < arr.size(); i++) {
                value = arr[i];
                if (value < 0) {
                    negtable[-value]++;
                } else {
                    table[value]++;
                }
            }
            if (min < 0) {
                for (int n = negtable.size() - 1; n > 0; n--) {
                    value = negtable[n];
                    if (value != 0) {
                        for (int m = 0; m < value; m++) {
                            result.push_back(-n);
                        }
                    }
                }
            }
            for (int k = 0; k < table.size(); k++) {
                value = table[k];
                if (value != 0) {
                    for (int l = 0; l < value; l++) {
                        result.push_back(k);
                    }
                }
            }
            arr = result;
        }
        vector<int> countingSortOf(vector<int> arr) {
            vector<int> table, result, negtable;
            int index, value;
            int min = arr[0];
            int max = arr[0];
            for (int o = 0; o < arr.size(); o++) {
                value = arr[o];
                if (value < min) {
                    min = value;
                } else if (value > max) {
                    max = value;
                }
            }
            min--;
            max++;
            if (min < 0) {
                for (int m = min; m <= 0; m++) {
                    negtable.push_back(0);
                }
            }
            for (int j = min; j <= max + 1; j++) {
                table.push_back(0);
            }
            for (int i = 0; i < arr.size(); i++) {
                value = arr[i];
                if (value < 0) {
                    negtable[-value]++;
                } else {
                    table[value]++;
                }
            }
            if (min < 0) {
                for (int n = negtable.size() - 1; n > 0; n--) {
                    value = negtable[n];
                    if (value != 0) {
                        for (int m = 0; m < value; m++) {
                            result.push_back(-n);
                        }
                    }
                }
            }
            for (int k = 0; k < table.size(); k++) {
                value = table[k];
                if (value != 0) {
                    for (int l = 0; l < value; l++) {
                        result.push_back(k);
                    }
                }
            }
            return result;
        }
        void countingSort(vector<int> &arr) {
            vector<int> table, result, negtable;
            int index, value;
            int min = arr[0];
            int max = arr[0];
            for (int o = 0; o < arr.size(); o++) {
                value = arr[o];
                if (value < min) {
                    min = value;
                } else if (value > max) {
                    max = value;
                }
            }
            min--;
            max++;
            if (min < 0) {
                for (int m = min; m <= 0; m++) {
                    negtable.push_back(0);
                }
            }
            for (int j = min; j <= max + 1; j++) {
                table.push_back(0);
            }
            for (int i = 0; i < arr.size(); i++) {
                value = arr[i];
                if (value < 0) {
                    negtable[-value]++;
                } else {
                    table[value]++;
                }
            }
            if (min < 0) {
                for (int n = negtable.size() - 1; n > 0; n--) {
                    value = negtable[n];
                    if (value != 0) {
                        for (int m = 0; m < value; m++) {
                            result.push_back(-n);
                        }
                    }
                }
            }
            for (int k = 0; k < table.size(); k++) {
                value = table[k];
                if (value != 0) {
                    for (int l = 0; l < value; l++) {
                        result.push_back(k);
                    }
                }
            }
            arr = result;
        }*/
        //Shellsort works by using insertion sort in subarrays, and is better for larger arrays
        //Time = 19ms
        vector<double> shellSortOf(vector<double> arr) {
            int i;
            double temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
            return arr;
        }
        void shellSort(vector<double> &arr) {
            int i;
            double temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
        }
        vector<float> shellSortOf(vector<float> arr) {
            int i;
            float temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
            return arr;
        }
        void shellSort(vector<float> &arr) {
            int i;
            float temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
        }
        vector<int> shellSortOf(vector<int> arr) {
            int i, temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
            return arr;
        }
        void shellSort(vector<int> &arr) {
            int i, temp;
            int flag = 1;
            int d = arr.size();
            while(flag || (d > 1)) {
                 flag = 0;
                 d = (d + 1) / 2;
                 for (i = 0; i < (arr.size() - d); i++) {
                      if (arr[i + d] < arr[i]) {
                             temp = arr[i + d];
                             arr[i + d] = arr[i];
                             arr[i] = temp;
                             flag = 1;
                     }
                }
            }
        }
        //Linear search finds the index of an array that contains a value
        int linearSearch(vector<double> arr, double value) {
            double last = arr.back();
            int i;
            for(i = 0; arr[i] != value; i++) {
            }
            if (i < arr.size() || arr[last] == value) {
                return i;
            } else {
                cerr << "From function linearSearch(vector, double): The specified value was not found." << endl;
                return -1;
            }
        }
        int linearSearch(vector<int> arr, int value) {
            int last = arr.back();
            int i;
            for(i = 0; arr[i] != value; i++) {
            }
            if (i < arr.size() || arr[last] == value) {
                return i;
            } else {
                cerr << "From function linearSearch(vector, int): The specified value was not found." << endl;
                return -1;
            }
        }
        int linearSearch(vector<char> arr, char value) {
            int last = (int)arr.back();
            int i;
            for(i = 0; arr[i] != value; i++) {
            }
            if (i < arr.size() || arr[last] == value) {
                return i;
            } else {
                cerr << "From function linearSearch(vector, char): The specified value was not found." << endl;
                return -1;
            }
        }
        int linearSearch(vector<float> arr, float value) {
            float last = arr.back();
            int i;
            for(i = 0; arr[i] != value; i++) {
            }
            if (i < arr.size() || arr[last] == value) {
                return i;
            } else {
                cerr << "From function linearSearch(vector, float): The specified value was not found." << endl;
                return -1;
            }
        }
        int linearSearch(vector<bool> arr, bool value) {
            int last = (int)arr.back();
            int i;
            for(i = 0; arr[i] != value; i++) {
            }
            if (i < arr.size() || arr[last] == value) {
                return i;
            } else {
                cerr << "From function linearSearch(vector, bool): The specified value was not found." << endl;
                return -1;
            }
        }
        int linearSearchSimple(vector<double> arr, double value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearchSimple(vector, double): The specified value was not found." << endl;
            return -1;
        }
        int linearSearchSimple(vector<int> arr, int value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearchSimple(vector, arr): The specified value was not found." << endl;
            return -1;
        }
        int linearSearch(vector<string> arr, string value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearch(vector, string): The specified value was not found." << endl;
            return -1;
        }
        int linearSearchSimple(vector<char> arr, char value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearchSimple(vector, char): The specified value was not found." << endl;
            return -1;
        }
        int linearSearchSimple(vector<float> arr, float value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearchSimple(vector, float): The specified value was not found." << endl;
            return -1;
        }
        int linearSearchSimple(vector<bool> arr, bool value) {
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == value) {
                    return i;
                }
            }
            cerr << "From function linearSearchSimple(vector, bool): The specified value was not found." << endl;
            return -1;
        }
        //Merge Sort works by dividing the array down until the array gets small then merging it back the right way.
        //Time =
        /*void mergeSort(vector<int>& arr) {
            this->merge_sorttemp(arr, 0, (arr.size() - 1));
        }
        void mergeSort(vector<double>& arr) {
            this->merge_sorttemp(arr, 0, (arr.size() - 1));
        }*/
        //Quicksort uses divide-and-conquer to split the array up, arrange everything around one element and repeats
        //Quicksort is preferable for larger arrays
        //Time = 19ms
        void quickSort(vector<double>& arr) {
            this->quicksorttemp(arr, 0, (arr.size() - 1));
        }
        void quickSort(vector<int>& arr) {
            this->quicksorttemp(arr, 0, (arr.size() - 1));
        }
        //Reverses an array to sort in the opposite direction
        //Time = 20ms
        void reverse(vector<double>& arr) {
            double temp;
            for (int i = 0; i < arr.size()/2; i++) {
                temp = arr[i];
                arr[i] = arr[arr.size() - 1 - i];
                arr[arr.size() - 1 - i] = temp;
            }
        }
        void reverse(vector<int>& arr) {
            int temp;
            for (int i = 0; i < arr.size()/2; i++) {
                temp = arr[i];
                arr[i] = arr[arr.size() - 1 - i];
                arr[arr.size() - 1 - i] = temp;
            }
        }
} Sort;
