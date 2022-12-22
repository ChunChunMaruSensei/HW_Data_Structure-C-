#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card* head;
    int size = 0;
    
    CardList(){
        head = NULL;
    }
    
    void insert_back(string newItem){
        Card* newptr = new Card;
        newptr->name = newItem;
        newptr->next = NULL;
        if(size==0){
            head = newptr;
        }else{
            Card* last = head;
            for(int i=1;i<size;i++){
                last = last->next;
            }
            last->next = newptr;
        }
        size++;
    }

    void pop_back(){
        Card* prev = head;
        Card* cur;
        if(size == 1){
            head = NULL;
            size--;
        }else if(size > 1){
            for(int i=1;i<size-1;i++){
            prev = prev->next;
            }
            cur = prev->next;
            prev->next = cur->next;
            delete cur;
            cur = NULL;
            size--;
        }
        
        
    }

    
    void shuffle(int pos){ //1<=pos<=size-1
        if(pos >= 1 && pos <= size-1){
            Card* cur;
            Card* last;
            Card* prev = head;
            for(int i=1;i<pos;i++){
                prev = prev->next;
            }
            cur = prev->next;
            last = cur;
            for(int i=1;i<size-pos;i++){
                last = last->next;
            }
            prev->next = NULL;
            last->next = head;
            head = cur;
        }
        
    }
    
    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }

};