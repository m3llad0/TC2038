// Algoritmo de Strassen.
// Analisis y diseño de algoritmos. 
// Diego Mellado A01655451
// Iwalani Amador A01732251
// Tonatiuh Reyes A01025459.
// The program requires that the txt files with the matrices should be in a folder called "txt_files" to work properly.
// Tools has the functions to extract the matrix from the txt and to print it. Also the function to get N from the matrix within the txt.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "tools.hpp"
#include "strassen.hpp"

int main () {
    // You can define with which txt files you want to multiply, remember to use the A and B from the same n size. Otherwise use txt with matrices of same size.
    string name1 = "01. Matrix_A_16_2_4.txt";
    string name2 = "02. Matrix_B_16_2_4.txt";

    // Getting the n of the matrices.
    int n = getN(name1);
    
    // Creation of vectors of vectors of integers.
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;

    // Storage of the results, ResStras and ResTextB for Results Strassen Algorithm and Results Textbook method respectively;.
    vector<vector<int>> matrixResStras;
    vector<vector<int>> matrixResTextB;

    // Reading of the matrices from the txt files.
    matrix1 = readMatrix(name1);
    matrix2 = readMatrix(name2);

    // Textbook alogorithm.
    int  totalMult =0;

    for (int i=0; i<n; i++) {
        vector<int> row;
        for (int j=0; j<n; j++) {
            int sum = 0;
            for (int k=0; k<n; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            row.push_back(sum);
            totalMult++;
        }
        matrixResTextB.push_back(row);
    }

    cout << "TextBook multiplication matrix: " << endl;
    cout << "Total scalar multiplications: " << totalMult << endl;
    printVectorM(matrixResTextB);
    
    // Strassen's algorithm.
    
   // matrixResStras = strassen(matrix1, matrix2);

    cout << "Strassen algorithm matrix: " << endl;
    //printVectorM(matrixResStras);
    vector<vector<int>> resultingMatrix = strassen(matrix1,matrix2);
	cout << additions.size()<< " " << multiplications.size() << " " << iterations.size();
    writeFile(resultingMatrix);
	
	printf("\n\n");
  FILE *archivo = fopen("StrassenMatrix.txt", "r");
  int c; 
  while ((c=fgetc(archivo))!= EOF){
    putchar(c);
  }

    return 0;
}
