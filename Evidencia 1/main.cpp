// Algoritmo Z-function
// Tonatiuh Reyes
// Diego Mellado
// Iwalani Amador

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

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
  string s = "hola me llamo virus xd";
  string aBuscar;
  cout << "Ingrese la cadena a buscar: ";
  cin >> aBuscar;
  int aSize = aBuscar.size();
  aBuscar += s;
  int n = aBuscar.length();
  string findIndex = "";
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (i + j < n && aBuscar[j] == aBuscar[i + j]) {
      j++;
    }
    if (j == aBuscar.length()) {
      cout << "Longitud del string: " << j - aSize << endl;
      cout << "String: ";
    } else if  (j != aBuscar.length()) {
      cout << j << ' ';
    }
    if (j > 2) {
      findIndex += to_string(i) + " ";
    }
  }
  cout << endl;
  cout << "Indices de la cadena con matches mayores a 2 caracteres: ";
  cout << findIndex << endl;
}