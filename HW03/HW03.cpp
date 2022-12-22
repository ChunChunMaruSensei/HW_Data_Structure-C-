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
        else{
            Poly_node* CheckEx = head;
            while(true){
                if(CheckEx -> next == NULL){
                    break;
                }
                else if(CheckEx -> next -> exponent < NewTerm -> exponent){
                    break;
                }
                else if(CheckEx -> exponent == NewTerm -> exponent){
                    break;
                }
                CheckEx = CheckEx -> next;
            }
            if(CheckEx -> exponent == NewTerm -> exponent){
                CheckEx -> coef += NewTerm -> coef;
            }
            else{
                NewTerm -> next = CheckEx -> next;
                CheckEx -> next = NewTerm;
            }
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
        Poly_node* Checkf1 = head;
        Poly_node* Checkf2 = f2.head;
        Poly_node* Backup;

        while (true){
            if(Checkf1 -> exponent > Checkf2 -> exponent){
                if(Checkf1 -> next == NULL){
                    Checkf1 -> next = Checkf2;
                    break;
                }
                if(Checkf1 -> next -> exponent < Checkf2 -> exponent){
                    Backup = Checkf2 -> next;
                    Checkf2 -> next = Checkf1 -> next;
                    Checkf1 -> next = Checkf2;
                    Checkf1 = Checkf2;
                    Checkf2 = Backup;
                    if(Checkf2 == NULL){
                        break;
                    }
                }
                else{
                    Checkf1 = Checkf1 -> next;
                } 
            }
            else if(Checkf1 -> exponent == Checkf2 -> exponent){
                Checkf1 -> coef += Checkf2 -> coef;
                Checkf2 = Checkf2 -> next;
                if(Checkf2 == NULL){
                    break;
                }
                if(Checkf1 -> next == NULL){
                    Checkf1 -> next = Checkf2;
                    break;
                }
            }
            else if(Checkf1 -> exponent < Checkf2 -> exponent){
                Backup = Checkf2 -> next;
                Checkf2 -> next = Checkf1;
                head = Checkf2;
                Checkf1 = Checkf2;
                Checkf2 = Backup;
            }
        }
    }
    void minus(Polynomial f2){
        Poly_node* Checkf1 = head;
        Poly_node* Checkf2 = f2.head;
        Poly_node* Backup;

        while (Checkf2 != NULL){
            Checkf2 -> coef *= -1;
            Checkf2 = Checkf2 -> next;
        }

        Checkf2 = f2.head;

        while (true){
            if(Checkf1 -> exponent > Checkf2 -> exponent){
                if(Checkf1 -> next == NULL){
                    Checkf1 -> next = Checkf2;
                    break;
                }
                if(Checkf1 -> next -> exponent < Checkf2 -> exponent){
                    Backup = Checkf2 -> next;
                    Checkf2 -> next = Checkf1 -> next;
                    Checkf1 -> next = Checkf2;
                    Checkf1 = Checkf2;
                    Checkf2 = Backup;
                    if(Checkf2 == NULL){
                        break;
                    }
                }
                else{
                    Checkf1 = Checkf1 -> next;
                } 
            }
            else if(Checkf1 -> exponent == Checkf2 -> exponent){
                Checkf1 -> coef += Checkf2 -> coef;
                Checkf2 = Checkf2 -> next;
                if(Checkf2 == NULL){
                    break;
                }
                if(Checkf1 -> next == NULL){
                    Checkf1 -> next = Checkf2;
                    break;
                }
            }
            else if(Checkf1 -> exponent < Checkf2 -> exponent){
                Backup = Checkf2 -> next;
                Checkf2 -> next = Checkf1;
                head = Checkf2;
                Checkf1 = Checkf2;
                Checkf2 = Backup;
            }
        }
    }
};