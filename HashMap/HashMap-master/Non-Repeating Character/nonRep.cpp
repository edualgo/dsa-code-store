#include<bits/stdc++.h>
using namespace std;

char nonRepeatingCharacter(string str)
{
  map<char,int> mapp;
  char tak;
  int l = str.size();
  for(int i=0;i<l;i++)
  {
      char key = str[i];
      if(mapp.count(key)==0)
      {
          mapp[str[i]] = 1;
      }
      else
      {
          mapp[str[i]]++;
      }
  }
  map<char,int>::iterator it;
  it = mapp.begin();
  while(it != mapp.end())
  {
      if(it -> second ==1)
      {
          tak = it -> first;
          break;
      }
      it++;
  }
  return tak;
}
int main()
{
    string word;
    cin >> word;
    char p = nonRepeatingCharacter(word);
    cout << p << endl;
}
