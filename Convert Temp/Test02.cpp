#include<iostream>
using namespace std;

int main(){
    int choice;double inputTemp;double temp;
    cin >> choice;
    cin >> inputTemp;
    if (choice == 1){
        temp = (inputTemp*1.8) + 32;
    }else if (choice == 2){
        temp = (inputTemp-32) * (5.0/9.0);
    }else{
        cout << "Error";
    }
    printf("%.2f",temp);
}