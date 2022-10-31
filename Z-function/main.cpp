// Algoritmo Z-function
// Tonatiuh Reyes
// Diego Mellado
// Iwalani Amador

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string readString(string fileName) {
  string s;
  ifstream inFile(fileName);

  string elem;

  while (getline(inFile, elem, ',')) {
    s += elem;
  }

  inFile.close();
  return s;
}

int main() {
  string s = "00111000011110101000111";
  int n = s.length();
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    int j = 1;
    while (i + j < n && s[j] == s[i + j]) {
      j++;
    }
    cout << j << ' ';
  }
}