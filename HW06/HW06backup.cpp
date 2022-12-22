#include <iostream>
using namespace std;
class Ranking{
private:
    int data[1000];
    int size;
    /*
         WRITE YOUR CODE HERE
    */
public:
    Ranking(int n){
        size = n;
    }
    void inputData(){
        for(int i=0;i<size;i++){
            cin>>data[i];
        }
    }
    int binarySearch(int key){
        int low = 0;
        int hi = size-1;
        int mid = (low+hi)/2;
        while(low != mid && hi != mid && low != hi){
            if(data[mid] == key){
                return(mid+1);
            }
            else if(data[low] == key){
                return(low+1);
            }else if(data[hi] == key){
                return(hi+1);
            }else{
                if(data[mid] < key){
                    hi = mid + 1;
                }else if(data[mid] > key){
                    low = mid + 1;
                }
            }
            mid = (low+hi)/2;
        }
    }

    void merge(int left, int mid, int right){
        int end_left, num, temp_index, i;
        end_left = mid - 1;
        temp_index = 0;
        num= right - left + 1;
        int tempArray[num];
        while ((left <= end_left) && (mid <= right)){
            if (data[left] < data[mid]){
                tempArray[temp_index] = data[mid];
                mid++;
                temp_index++;
            }else{
                tempArray[temp_index] = data[left];
                left++;
                temp_index++;
            }
        }
        while (left <= end_left){
            tempArray[temp_index] = data[left];
            left++;
            temp_index++;
        }

        while (mid <= right){
            tempArray[temp_index] = data[mid];
            mid++;
            temp_index++;
        }
		
        for(i = num-1; i >= 0; i--){
			data[right] = tempArray[i];
			right--;
        }

    }
    
    
    void mergeSort(int left, int right){
        int mid;
        if(left < right){
		    mid = (left + right) / 2;
	    	mergeSort(left, mid);
		    mergeSort(mid+1, right);
		    merge(left, mid+1, right);
        }
	}
    
    int show(int index){
        return data[index-1];
    }
};

