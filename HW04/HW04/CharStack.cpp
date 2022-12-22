class CharStack {

public:
  int size;
  char stack[20];
  
  CharStack() { // constructor
    size = 0;
  }

  void push(char new_item) {
    size++;
    stack[size] = new_item;
  }

  char pop() {
    size--;
    return(stack[size]);
  }

  char top() {
    return(stack[size]);
  }

  bool isEmpty() {
    if(size == 0){//stack ว่าง
      return(true);
    }else{//stack ไม่ว่าง
      return(false);
    }
  }
};