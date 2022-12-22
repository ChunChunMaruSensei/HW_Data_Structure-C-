#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    int index;
    Polynomial(){
        head = NULL;
        index = 0;
    }
    void addTerm(int coef, int exponent){
        Poly_node* NewTerm;
        NewTerm = new Poly_node;
        NewTerm -> coef = coef;
        NewTerm -> exponent = exponent;
        if(index == 0){
            head = NewTerm;
            NewTerm -> next = NULL;
            index++;
        }
        else if(head -> exponent < NewTerm -> exponent){
            NewTerm -> next = head;
            head = NewTerm;
        }
        else if(head -> exponent > NewTerm -> exponent){
            Poly_node* CheckEx = head;
            if(CheckEx -> next != NULL){
                while(NewTerm -> exponent < CheckEx -> next -> exponent){ //ออกเมื่อ NewTerm -> ex >= ex ของ Check
                    if(CheckEx -> next == NULL){
                        break;
                    }
                    CheckEx = CheckEx -> next;
                }
            }
            NewTerm -> next = CheckEx -> next;
            CheckEx -> next = NewTerm;
        }
        else if(head -> exponent == NewTerm -> exponent){
            Poly_node* CheckEx = head;
            while(NewTerm -> exponent != CheckEx -> exponent){
                CheckEx = CheckEx -> next;
            }
            CheckEx -> coef += NewTerm -> coef;
        }
    }
    void printPolynomial(){
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL){
            if(ptr->coef==0){

            }else{
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void plus(Polynomial f2){
        
    }
    void minus(Polynomial f2){

    }
};

































