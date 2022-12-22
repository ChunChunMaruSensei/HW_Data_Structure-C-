class CharStack {

public:
  int index;
  char charArray[10];
  
  CharStack() { // constructor
    index = -1;
  }

  void push(char new_item) {
    index++;
    charArray[index] = new_item;
  }

  char pop() {
    index--;
    return(charArray[index+1]);
  }

  char top() {
    return(charArray[index]);
  }

  bool isEmpty() {
    if(index == -1){
      return(true);
    }else{
      return(false);
    }
  }
};
