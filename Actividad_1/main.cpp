// Actividad 1
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
  string fileNames[3] = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};
  string s = readString("transmission.txt");

  for (int i = 0; i < 3; i++) {
    string fileName = fileNames[i];
    string aBuscar = readString(fileName);

    cout << "El archivo " << fileName << " contiene el mensaje: " << aBuscar << endl;

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
    if (j >= aSize && i != 0) {
      findIndex += to_string(i-aSize) + " ";
      incidence++;
    }
  }
  cout << endl << "En el archivo se encontro el mensaje de " << fileName << ": ";

  if (incidence > 0) {
    cout << "true" << endl;
    cout << "Numero de incidencias: " << incidence << endl;
    cout << "Indices de la cadena con matches identicos: ";
    cout << findIndex << endl << endl;
  } else {
    cout << "false" << endl << endl;
  }
  }
}