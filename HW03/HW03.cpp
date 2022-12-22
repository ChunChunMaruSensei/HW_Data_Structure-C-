#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    
    Polynomial(){
        head = NULL;
    }
    
    void addTerm(int coef, int exponent){
        Poly_node* newPolyNode = new Poly_node;
        newPolyNode->coef = coef;
        newPolyNode->exponent = exponent;
        newPolyNode->next = NULL;
        if(head == NULL){
            head = newPolyNode;
        }else{
            if(head->exponent < newPolyNode->exponent){
                newPolyNode->next = head;
                head = newPolyNode;
            }else{
                Poly_node* cur = head;
                while(true){
                    if(cur->next == NULL){ 
                        break;
                    }else{
                        if(cur->exponent == newPolyNode->exponent){
                            break;
                        }else if(cur->next->exponent < newPolyNode->exponent){
                            break;
                        }
                        cur = cur->next;
                    }
                }
                if(cur->exponent == newPolyNode->exponent){
                    cur->coef+= newPolyNode->coef;
                    delete newPolyNode;
                    newPolyNode = nullptr;
                }else{
                    newPolyNode->next = cur->next;
                    cur->next = newPolyNode;
                }
                
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
        Poly_node* f1Node = head;
        Poly_node* f2Node = f2.head;
        Poly_node* newNode;
        while(true){
            if(f2Node == NULL){
                break;
            }
            if(f1Node->exponent < f2Node->exponent){
                newNode = new Poly_node;
                newNode->coef = f2Node->coef;
                newNode->exponent = f2Node->exponent;
                newNode->next = f1Node;
                head = newNode;
                f1Node = head;
                f2Node = f2Node->next;
            }else{
                if(f1Node->exponent == f2Node->exponent){
                    f1Node->coef += f2Node->coef;
                    f2Node = f2Node->next;
                }else if(f1Node->next == NULL){
                    while (f2Node != NULL){
                        newNode = new Poly_node;
                        newNode->coef = f2Node->coef;
                        newNode->exponent = f2Node->exponent;
                        newNode->next = NULL;
                        f1Node->next = newNode;
                        f1Node = newNode;
                        f2Node = f2Node->next;
                    }
                    break;
                }else if(f1Node->next->exponent < f2Node->exponent){
                    newNode = new Poly_node;
                    newNode->coef = f2Node->coef;
                    newNode->exponent = f2Node->exponent;
                    newNode->next = f1Node->next;
                    f1Node->next = newNode;
                    f1Node = newNode;
                    f2Node = f2Node->next;
                }else{
                    f1Node = f1Node->next;
                }
            }
        }
    }
    
    void minus(Polynomial f2){
        Poly_node* f1Node = head;
        Poly_node* f2Node = f2.head;
        Poly_node* newNode;
        while(true){
            if(f2Node == NULL){
                break;
            }
            if(f1Node->exponent < f2Node->exponent){
                newNode = new Poly_node;
                newNode->coef = f2Node->coef * -1;
                newNode->exponent = f2Node->exponent;
                newNode->next = f1Node;
                head = newNode;
                f1Node = head;
                f2Node = f2Node->next;
            }else{
                if(f1Node->exponent == f2Node->exponent){
                    f1Node->coef -= f2Node->coef;
                    f2Node = f2Node->next;
                }else if(f1Node->next == NULL){
                    while (f2Node != NULL){
                        newNode = new Poly_node;
                        newNode->coef = f2Node->coef * -1;
                        newNode->exponent = f2Node->exponent;
                        newNode->next = NULL;
                        f1Node->next = newNode;
                        f1Node = newNode;
                        f2Node = f2Node->next;
                    }
                    break;
                }else if(f1Node->next->exponent < f2Node->exponent){
                    newNode = new Poly_node;
                    newNode->coef = f2Node->coef * -1;
                    newNode->exponent = f2Node->exponent;
                    newNode->next = f1Node->next;
                    f1Node->next = newNode;
                    f1Node = newNode;
                    f2Node = f2Node->next;
                }else{
                    f1Node = f1Node->next;
                }
            }
        }
    }
};