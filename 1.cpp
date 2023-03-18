#include <string>
#include <vector>
#include <iostream>


using namespace std;


int check_letter(char letter){
  if (letter == 'B') return 0;
  if (letter == 'Y') return 1;
  else return -1;
}


int main(){
  int length;
  vector <string> words;
  string colours;
  vector <int> indexes_of_space;
  cin >> length;
  string tmp_word;
  int count_of_letters = 0;

  while ( count_of_letters != length ){
    cin >> tmp_word;
    words.push_back(tmp_word);
    count_of_letters += tmp_word.length();
  }

  indexes_of_space.push_back(words[0].size() - 1);

  for ( int i = 1; i < words.size(); i++ ){
    indexes_of_space.push_back(indexes_of_space[i-1] + words[i].size());
  }

  count_of_letters = 0;
  cin >> colours;
  int count = 0;
  int n = 0;

  for ( int i = 0; i < length - 1; i++ ){
    if ( i == indexes_of_space[n] ){
      n++;
      continue;
    }

    if ( check_letter(colours[i]) == check_letter(colours[i+1]) ){
      count++;
      i += words[n].size();
      n++;
    }
  }

  cout << count; 
}