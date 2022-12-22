#include<iostream>
#include "BSTNode.cpp"

class BST {

public:
  BSTNode* root;

  BST() {
    root = nullptr;
  }

  void insert(int value) {
    BSTNode* newNode = new BSTNode;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL){
      root = newNode;
    }else{
      BSTNode* cur = root;
      while(true){
        if(cur->value > newNode->value){
          if(cur->left == NULL){
            cur->left = newNode;
            break;
          }else{
            cur = cur->left;
          }
        }else if(cur->value < newNode->value){
          if(cur->right == NULL){
            cur->right = newNode;
            break;
          }else{
            cur = cur->right;
          }
        }else{
          free(newNode);
          break;
        }
      }
    }
  }


  void remove(int value) {
    BSTNode* cur = root; //Node you want to delete
    BSTNode* prev;
    BSTNode* next;
    while(true){
      if(root == NULL){
        break;
      }else if(root->left == NULL && root->right == NULL){
        if(root->value = value){
          root = nullptr;
          free(root);
        }
      }
      if(cur->value > value){
        if(cur->left == NULL){ //if not have any node -> break
          break;
        }else{
          prev = cur;
          cur = cur->left;
        }
      }else if(cur->value < value){
        if(cur->right == NULL){ //if not have any node -> break
          break;
        }else{
          prev = cur;
          cur = cur->right;
        }
      }else{ //found node you want to delete
        BSTNode* cur_left = cur->left;
        BSTNode* cur_right = cur->right;
        if(cur->left == NULL && cur->right == NULL){ //not have child (case 1)
          if(root->value == value){ //case 1.1: the node and its parent is a root
				    root = nullptr;
            free(cur);
            break;
			    }
			    else{ //case 1.2: the node and its parent isn't a root
				    if(cur->value > prev->value){
              prev->right = NULL;
              free(cur);
              break;
            }else{
              prev->left = NULL;
              free(cur);
              break;
            }
				  }
        }else if(cur->left != NULL && cur->right == NULL){ //have single child at left (case 2)
          if(root->value == value){
            if(cur_left->left == NULL && cur_left->right == NULL){
              cur->value = cur_left->value;
              cur->left = NULL;
              free(cur_left);
              break;
            }else if(cur_left->left != NULL){
              root = cur_left;
              free(cur);
              break;
            }
          }
          if(prev->value > cur->value){ //check previous arm
            prev->left = cur->left;
            free(cur);
            break;
          }else{
            prev->right = cur->left;
            free(cur);
            break;
          }
        }else if(cur->left == NULL && cur->right != NULL){ //have single child at right (case 2)
          if(root->value == value){
            if(cur_right->left == NULL){
              cur->value = cur_right->value;
              cur->right = NULL;
              free(cur_right);
              break;
            }else if(cur_right->left != NULL){
              root = cur_right;
              free(cur);
              break;
            }
          }
          
          if(prev->value > cur->value){ //check previous arm
            prev->left = cur->right;
            free(cur);
            break;
          }else{
            prev->right = cur->right;
            free(cur);
            break;
          }
        }else if(cur->left != NULL && cur->right != NULL){ //have 2 child (case 3)
          if(cur_right->left == NULL && cur_right->right == NULL){
              cur->value = cur_right->value;
              cur->right = NULL;
              free(cur_right);
              break;
          }
          if(cur_right->left != NULL){ //(case 3.1)
            BSTNode* leftNode = cur_right->left; //left node of current->right
            BSTNode* prev_delete;
            if(leftNode->left != NULL){
              while(leftNode->left != NULL){
                prev_delete = leftNode;
                leftNode = leftNode->left;
              }
              if(leftNode->right != NULL){
                cur->value = leftNode->value;
                prev_delete->left = leftNode->right;
                free(leftNode);
                break;
              }else{
                cur->value = leftNode->value;
                prev_delete->left = NULL;
                free(leftNode);
                break;
              }
            }else{
              cur->value = leftNode->value;
              cur_right->left = leftNode->right;
              free(leftNode);
              break; 
            }
            
          }else if(cur_right->left == NULL){ //(case 3.2)
            cur->value = cur_right->value;
            cur->right = cur_right->right;
            free(cur_right);
            break;
          }
        }else{
          break;
        }
      }
    }
    
  }

  int get_depth(int value) {
    int depth = 0;
    BSTNode* cur = root;
    while(true){
      if(cur->value > value){
        if(cur->left == NULL){
          break;
        }else{
          cur = cur->left;
          depth++;
        }
      }else if(cur->value < value){
        if(cur->right == NULL){
          break;
        }else{
          cur = cur->right;
          depth++;
        }
      }else{
        return(depth);
      }
    }
    return -1;
  }

  int sum(){
    
  }

};
