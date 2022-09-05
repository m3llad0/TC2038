#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

vector<double> multiplications{0.0};
vector<double> additions{0.0};
vector<double> iterations{0.0};


// Dividir una matriz en 4 partes y devuelve un vector 
vector<vector<vector<int>>> sliceMatrix(vector<vector<int>> matrix)
{
    int halfMatrixSize = matrix.size()/2;
    vector<vector<int>> *result1 = new vector<vector<int>>;
    vector<vector<int>> *result2 = new vector<vector<int>>;
    vector<vector<int>> *result3 = new vector<vector<int>>;
    vector<vector<int>> *result4 = new vector<vector<int>>;
    vector<vector<vector<int>>> finalMatrix{};
	vector<int> aux{};
	vector<int> aux2{};
    // Iterar por renglón
    for (int i = 0; i < matrix.size(); i++)
    {
        if(i < halfMatrixSize)
        {
            // Construir matrices 1 y 2
			for (int j = 0; j < matrix[i].size(); j++) 
            {
				if(j < halfMatrixSize) 
                {
					aux.push_back(matrix[i][j]);
                    
				} 
                else 
                {
					aux2.push_back(matrix[i][j]);
				}
			}
			result1->push_back(aux);
			result2->push_back(aux2);
			aux.clear();
			aux2.clear();	
        }
        else {
            for(int j = 0; j < matrix[i].size();j++)
            {
                // Matriz 3 y 4
                if(j < halfMatrixSize)
                {
                    aux.push_back(matrix[i][j]);
                } 
                else 
                {
					aux2.push_back(matrix[i][j]);
            	}
            }
			result3->push_back(aux);
			result4->push_back(aux2);
			aux.clear();
			aux2.clear();	
        }
    }
    finalMatrix.push_back(*result1);
    finalMatrix.push_back(*result2);
    finalMatrix.push_back(*result3);
    finalMatrix.push_back(*result4);
	delete result1;
	delete result2;
	delete result3;
	delete result4;
    return finalMatrix;
}

//suma entre dos matrices.

vector<vector<int>> add(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    for(int i = 0; i < matrix1.size(); i++)
    {
        for(int j = 0; j < matrix1.size(); j++)
        {
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix1;
}
        
        
//Resta entre dos matrices.

vector<vector<int>> subtract(vector<vector<int>> matrix1,vector<vector<int>> matrix2){
    for(int i = 0; i < matrix1.size(); i++)
    {
        for(int j = 0; j < matrix1.size(); j++)
        {
            matrix1[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return matrix1; 
}


//Une 4 submatrices en una sola matriz.
 
vector<vector<int>> join(vector<vector<int>>matrix1,vector<vector<int>>matrix2,vector<vector<int>>matrix3,vector<vector<int>>matrix4)
{
    vector<vector<int>> finalMatrix;
	vector<int> *aux = new vector<int>;
	for(int j = 0; j < matrix1.size(); j++)
    {
		for(int i = 0; i < matrix1.size(); i++)
        {
			aux->push_back(matrix1[j][i]);
		}
		for(int i = 0; i < matrix1.size(); i++)
        {
			aux->push_back(matrix2[j][i]);
		}
		finalMatrix.push_back(*aux);
		aux->clear();
	}
	for(int j = 0; j < matrix1.size(); j++)
    {
		for(int i = 0; i < matrix1.size(); i++)
        {
			aux->push_back(matrix3[j][i]);
		}
		for(int i = 0; i < matrix1.size(); i++)
        {
			aux->push_back(matrix4[j][i]);
		}
		finalMatrix.push_back(*aux);
		aux->clear();
	}
	
	delete aux;
    return finalMatrix;
}

//strassen
vector<vector<int>> strassen(vector<vector<int>>matrix1, vector<vector<int>> matrix2)
{
    if(matrix1.size() == 2) 
    {
        int m1 = (matrix1[0][0] + matrix1[1][1]) * (matrix2[0][0] + matrix2[1][1]);
		int m2 = (matrix1[1][0] + matrix1[1][1]) * matrix2[0][0];	
        int m3 = (matrix1[0][0]) * (matrix2[0][1] - matrix2[1][1]);
        int m4 = matrix1[1][1] * (matrix2[1][0] - matrix2[0][0]);
        int m5 = (matrix1[0][0] + matrix1[0][1]) * (matrix2[1][1]);
		int m6 = (matrix1[1][0] - matrix1[0][0]) * (matrix2[0][0] + matrix2[0][1]);
        int m7 = (matrix1[0][1] - matrix1[1][1]) * (matrix2[1][0] + matrix2[1][1]);
        
        int c11 = m1 + m4 - m5 + m7;
        int c12 = m3 + m5;
        int c21 = m2 + m4;
        int c22 = m1 - m2 + m3 + m6; 
		
        vector<vector<int>>result{};
		result.push_back(vector<int> {c11, c12});
        result.push_back(vector<int> {c21,c22});

        multiplications.push_back(multiplications[multiplications.size()-1] + 7.0);
        additions.push_back(additions[additions.size()-1] + 18.0);
        iterations.push_back(iterations[iterations.size()-1] +1.0 );
        return result;
    } 
    else
    // Llamada recursiva al método Strassen
    {
		vector<vector<vector<int>>> slicedMatrix1 = sliceMatrix(matrix1);
		vector<vector<vector<int>>> slicedMatrix2 = sliceMatrix(matrix2);
        
        vector<vector<int>> a11 = slicedMatrix1[0];
        vector<vector<int>> a12 = slicedMatrix1[1];
        vector<vector<int>> a21 = slicedMatrix1[2];
        vector<vector<int>> a22 = slicedMatrix1[3];
        vector<vector<int>> b11 = slicedMatrix2[0];
        vector<vector<int>> b12 = slicedMatrix2[1];
        vector<vector<int>> b21 = slicedMatrix2[2];
        vector<vector<int>> b22 = slicedMatrix2[3];
        
        vector<vector<int>> m1 = strassen(add(a11,a22),add(b11,b22));
		vector<vector<int>> m2 = strassen(add(a21,a22),b11);
        vector<vector<int>> m3 = strassen(a11,subtract(b12,b22));
        vector<vector<int>> m4 = strassen(a22, subtract(b21,b11));
        vector<vector<int>> m5 = strassen(add(a11,a12),b22);
		vector<vector<int>> m6 = strassen(subtract(a21,a11),add(b11,b12));
        vector<vector<int>> m7 = strassen (subtract(a12,a22), add(b21,b22));

        vector<vector<int>> c11 = add(add(m1,m4),subtract(m7,m5));
		vector<vector<int>> c12 = add(m3,m5);
		vector<vector<int>> c21 = add(m2,m4);
		vector<vector<int>> c22 = add(add(m3,m6),subtract(m1,m2));

        // producir el resultado
        vector<vector<int>>result{join(c11,c12,c21,c22)};
        int sizeOfSlices = a11.size();
        int sizeOfPartialResult = c11.size();
        int sum = sizeOfSlices * sizeOfSlices * 10.0 + sizeOfPartialResult * sizeOfPartialResult * 8.0;
        additions.push_back(additions[additions.size()-1] + sum);
        multiplications.push_back(multiplications[multiplications.size()-1]);
        iterations.push_back(iterations[iterations.size()-1] + 1.0 );
        return result;   
    }
        
}


// Resultado en archivo txt
void writeFile(vector<vector<int>> matrix)
{
    std::ofstream finalfile;
    finalfile.open("StrassenMatrix.txt");
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (j == (matrix.size()-1))
            {
                finalfile << matrix[i][j];
            } 
			else
			{
                finalfile << matrix[i][j] << ",";
            }
        }
        finalfile << "\n";
	}
	finalfile.close(); 
}
