#include <iostream>
#include <string>
#include <cmath>
#include <bitset>


using namespace std;


string toStrBin(unsigned long decimal){
  return bitset<32>(decimal).to_string();
}


unsigned long max(unsigned long a, unsigned long b){
  if ( a > b ) return a;
  else return b;  
}


class Tree{
public:
  unsigned long value;
  Tree * _0_son = nullptr;
  Tree * _1_son = nullptr;
  void addToTree(unsigned long);
  unsigned long checkXOR(unsigned long);
  Tree();
};


int main() {
  unsigned long n;
  cin >> n;
  Tree tree;
  unsigned long currentNumber;
  unsigned long maxXOR = 0;

  for ( unsigned long i = 0; i < n; i++ ){
    cin >> currentNumber;
    tree.addToTree(currentNumber);
    maxXOR = max(tree.checkXOR(currentNumber), maxXOR);
    cout << maxXOR << "\n"; 
  }

  return 0; 
}


void Tree::addToTree(unsigned long number){
  string strBinNumber = toStrBin(number);
  Tree * currentNode = this;

  for ( int i = 0; i < 32; i++ ){
    char currentDigit = strBinNumber[i];
    if ( currentDigit == '0' ){
      if ( currentNode->_0_son ){
        currentNode = currentNode->_0_son;       
      }
      else{
        currentNode->_0_son = new Tree();
        currentNode = currentNode->_0_son;        
      }      
    }
    if ( currentDigit == '1' ){
      if ( currentNode->_1_son ){
        currentNode = currentNode->_1_son;       
      }
      else{
        currentNode->_1_son = new Tree();
        currentNode = currentNode->_1_son;        
      }      
    }    
  }

  currentNode->value = number;  
}


unsigned long Tree::checkXOR(unsigned long number){
  string strBinNumber = toStrBin(number);
  string numberToMaxXOR = strBinNumber;

  for ( int i = 0; i < 32; i++ ){
    if ( numberToMaxXOR[i] == '0' ) numberToMaxXOR[i] = '1';
    else numberToMaxXOR[i] = '0';    
  }

  Tree * currentNode = this;
  unsigned long nearestNumber;
  
  for ( int i = 0; i < 32; i++ ){
    if ( numberToMaxXOR[i] == '0' ){
      if ( currentNode->_0_son ){
        currentNode = currentNode->_0_son;      
      }
      else currentNode = currentNode->_1_son;      
    }
    if ( numberToMaxXOR[i] == '1' ){
      if ( currentNode->_1_son ){
        currentNode = currentNode->_1_son;        
      }
      else currentNode = currentNode->_0_son;      
    }    
  }

  nearestNumber = currentNode->value;
  return number ^ nearestNumber;  
}


Tree::Tree() {}
