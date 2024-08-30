#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<string> parseString(string); // prototype

int main()
{
  string userInput;
cout << "Enter some text (with space-separated words): ";
getline(cin, userInput);

vector<string> tokens = parseString(userInput);

cout << "There are this many tokens in string: " << tokens.size() << endl;
for (int i = 0; i < tokens.size(); i++)
  cout << "tokens[" << i << "] = " << "\"" << tokens[i] << "\"\n";
  return 0;
}

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

