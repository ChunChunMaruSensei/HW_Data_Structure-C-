#include <iostream>
using namespace std;
class Ranking{
private:
    int data[1000];
    int size;
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
		int i; 
        int left_end; 
        int num_element; 
        left_end = mid-1;
		num_element = right-left+1;
        int temp[num_element];
        while (left <= left_end && mid <= right){
            if (data[left] < data[mid])
            {
                temp[i] = data[mid];
                i++;
                mid++;
            }
            else
            {
                temp[i] = data[left];
                i++;
                left++;
            }
        }
        while (left <= left_end)
        {
            temp[i] = data[left];
            left++;
            i++;
        }

        while (mid <= right)
        {
            temp[i] = data[mid];
            mid++;
            i++;
        }
		for(int i = num_element-1; i >= 0; i--){
			data[right] = temp[i];
			right--;
        }
    }
    void mergeSort(int left, int right){
    int mid;
    if(left < right){
    	mid = (right + left)/2;
    	mergeSort(left, mid);
    	mergeSort(mid+1, right);
    	merge(left, mid+1, right);
		}
	}
    int show(int index){
        return data[index-1];
    }
};
