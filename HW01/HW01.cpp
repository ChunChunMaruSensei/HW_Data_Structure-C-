#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card* head;
    int index;
    CardList(){
        head = NULL;
        index = 0;
    }

	void pop_back(){
        Card* PCard = head;//PCard ก่อนสุดท้าย
        Card* DelCard;
        if(index > 1){
            for(int i = 1; i<index-1; i++){
                PCard = PCard -> next;
            }
            DelCard = PCard -> next;
            PCard -> next = NULL;
            delete DelCard;
            DelCard = NULL;
            index -= 1;
        }
        else{
            head = NULL;
            index -=1;
        }
	}

    void insert_back(string newItem){
        Card* Poko = new Card;
        Poko -> name = newItem;
        Poko -> next = NULL;
        if(index == 0){
            Poko -> next = NULL;
            head = Poko;
            index++;
        }
        else{
            Card* LastCard = head;
            for(int i = 1; i<index; i++){
                LastCard = LastCard -> next;
            }
            LastCard -> next = Poko;
            index++;
        }
    }

    void shuffle(int pos){ //1<=pos<=size-1
        Card* LastCard = head;
        Card* PosCard = head;
        Card* RoCard ;
        if(0 < pos){
            if (pos <= index -1){
                for(int i = 1; i<index; i++){
                    LastCard = LastCard -> next;
                }
                LastCard -> next = head;
                for(int i = 1; i<pos; i++){
                    PosCard = PosCard -> next;
                }
                RoCard = PosCard -> next;
                head = RoCard;
                PosCard -> next = NULL;
            }
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