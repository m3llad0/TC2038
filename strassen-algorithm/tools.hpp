#include <fstream>
#include <sstream>

int getN(string fileName) {
    ifstream inFile("./txt_files/"+fileName);
    int N = 0;
    string line;
    getline(inFile, line);
    stringstream lineStream(line);
    string elem;
    while (getline(lineStream, elem, ',')) {
        N++;
    }
    
    inFile.close();
    return N;
}

// Recovers the matrix from a txt file. Note that it should be within a folder called "txt_files". Otherwise delete or change the string in ifstream.
vector<vector<int>> readMatrix(string fileName) {
    vector<vector<int>> matrix;
    // Change this string in case not in "txt_files" folder.
    ifstream inFile("./txt_files/"+fileName);

    string line;

    // Gets line
    while (getline(inFile, line)) {
        vector<int> row;
        stringstream lineStream(line);
        string elem;
        // Divides line in strings elements with a comma as a end of element.
        while (getline(lineStream, elem, ',')) {
            // Changes string elem to integer and stores it in vector.
            row.push_back(stoi(elem));
        }
        matrix.push_back(row);
    }
    
    inFile.close();
    return matrix;
}

template <typename T, size_t rows, size_t cols>
void printArrayM (T (&matrix)[rows][cols]) {
    cout << "Matrix: " << "rows: [" << rows << "] columns: [" << cols << "]" << endl;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

template <typename T>
void printVectorM (const vector <vector<T>> & matrix) {
    for (auto row_obj : matrix) {
        for (auto elem : row_obj) {
            cout << elem << ", ";
        }
        cout << endl;
    }
    cout << endl;
}