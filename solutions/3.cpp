#include <iostream>

using namespace std;

int is_prime(unsigned long n){

  for ( long long i = 2; i * i < n + 1; i++ ){
    if ( n % i == 0 ){
      return 0;
    }
  }

  return 1;
}


unsigned long foo(unsigned long n){
  if ( n % 2 == 0 ) return n / 2;
  if ( is_prime(n) ) return 1;
  else{

    for ( long long i = 3; i * i < n + 1; i += 2 ){
      if ( n % i == 0 ){
        return n / i;
      }
    }

  }
}


int main(){
  unsigned long n;
  cin >> n;
  unsigned long k = foo(n);
  cout << k << " " << n - k;
}