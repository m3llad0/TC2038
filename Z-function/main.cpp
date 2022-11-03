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
  string s = readString("Z function-Test01.csv");
  // Get s length
  int n = s.length();
  cout << n << endl;
  // Iteration in n
  for (int i = 0; i < n; i++) {
    int j = 0;
    // Compares s[j] position with s[i+j], adds one to count and return j
    while (i + j < n && s[j] == s[i + j]) {
      j++;
    }
    cout << j << ' ';
  }
}