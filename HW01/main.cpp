#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{
  CardList L;
  L.insert_back("Pokemon");
  L.insert_back("Natu");
  L.insert_back("Kuy");
  L.insert_back("A");
  L.insert_back("B");
  L.shuffle(5);
  L.printCardList();
}
