#include<iostream>
#include "HW08.cpp"
using namespace std;

int main() {
    BST tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(14);
    tree.insert(6);
    tree.insert(15);
    tree.insert(9);
    tree.insert(8);
    tree.insert(13);
    tree.insert(12);
    tree.insert(16);
    tree.remove(2);
    tree.remove(14);
    tree.remove(6);
    tree.remove(15);
    tree.remove(9);
    tree.remove(8);
    tree.remove(13);
    tree.remove(12);
    tree.remove(16);
    //tree.remove(4);
    
    
    
    
    
    
    /*tree.insert(12);
    tree.insert(5);
    tree.insert(17);
    tree.insert(13);
    tree.insert(14);
    tree.insert(32);
    tree.insert(25);
    tree.insert(40);
    tree.remove(12);*/

    //tree.remove(12);
    //tree.remove(2);
    /*tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(8);
    tree.insert(6);
    tree.insert(5);*/
    cout << tree.get_depth(4) << endl;
    cout << tree.get_depth(2) << endl;
    cout << tree.get_depth(14) << endl;
    cout << tree.get_depth(6) << endl;
    cout << tree.get_depth(15) << endl;
    cout << tree.get_depth(9) << endl;
    cout << tree.get_depth(8) << endl;
    cout << tree.get_depth(13) << endl;
    cout << tree.get_depth(12) << endl;
    cout << tree.get_depth(16) << endl;
    
    
    
    

    /*cout << tree.get_depth(8) << endl;
    cout << tree.get_depth(5) << endl;
    cout << tree.get_depth(17) << endl;
    cout << tree.get_depth(13) << endl;
    cout << tree.get_depth(12) << endl;
    cout << tree.get_depth(14) << endl;
    cout << tree.get_depth(32) << endl;
    cout << tree.get_depth(25) << endl;
    cout << tree.get_depth(40) << endl;*/


   
    
    
    //tree.display();

    return 0;
}
