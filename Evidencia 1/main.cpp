// Evidencia 1
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

  while (getline(inFile, elem)) {
    s += elem;
  }

  inFile.close();
  return s;
}

int main() {
  string s = readString("transmission.txt");
  string aBuscar = readString("mcode1.txt");
  int aSize = aBuscar.size();
  aBuscar += s;
  int n = aBuscar.length();
  string findIndex = "";
  int incidence = 0;
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (i + j < n && aBuscar[j] == aBuscar[i + j]) {
      j++;
    }
    if (j == aBuscar.length()) {
      cout << "Longitud del string: " << j - aSize << endl;
    }
    if (j >= aSize && i != 0) {
      findIndex += to_string(i) + " ";
      incidence++;
    }
  }
  cout << endl;

  if (incidence > 0) {
    cout << "true" << endl;
    cout << "Numero de incidencias: " << incidence << endl;
    cout << "Indices de la cadena con matches identicos: ";
    cout << findIndex << endl;
  } else {
    cout << "false" << endl;
  }
}