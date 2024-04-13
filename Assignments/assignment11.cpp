#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[3][3];

public:
    Matrix() {}

    Matrix(int arr[][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = arr[i][j];
            }
        }
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix OBJ1(arr1);
    Matrix OBJ2(arr2);

    Matrix OBJ3 = OBJ1 + OBJ2;

    cout << "Matrix 1:" << endl;
    OBJ1.display();

    cout << "\nMatrix 2:" << endl;
    OBJ2.display();

    cout << "\nSum of Matrix 1 and Matrix 2:" << endl;
    OBJ3.display();

    return 0;
}
