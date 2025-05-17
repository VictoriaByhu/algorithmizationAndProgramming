#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Matrix {
private:
    static const int SIZE = 3;
    int data[SIZE][SIZE];

public:
    Matrix() {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                data[i][j] = 0;
    }

    void randomFill(int min, int max) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                data[i][j] = rand() % (max - min + 1) + min;
    }

    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j)
                cout << setw(4) << data[i][j];
            cout << endl;
        }
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        Matrix result;
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                result.data[i][j] = a.data[i][j] + b.data[i][j];
        return result;
    }

    friend Matrix operator-(const Matrix& a, const Matrix& b) {
        Matrix result;
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                result.data[i][j] = a.data[i][j] - b.data[i][j];
        return result;
    }

    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        Matrix result;
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                for (int k = 0; k < SIZE; ++k)
                    result.data[i][j] += a.data[i][k] * b.data[k][j];
        return result;
    }

    friend bool operator==(const Matrix& a, const Matrix& b) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                if (a.data[i][j] != b.data[i][j])
                    return false;
        return true;
    }
};

int main() {
    srand(time(0)); 

    Matrix A, B;

    cout << "Matrix A:\n";
    A.randomFill(1, 9);
    A.display();

    cout << "\nMatrix B:\n";
    B.randomFill(1, 9);
    B.display();

    cout << "\nA + B:\n";
    Matrix C = A + B;
    C.display();

    cout << "\nA - B:\n";
    Matrix D = A - B;
    D.display();

    cout << "\nA * B:\n";
    Matrix E = A * B;
    E.display();

    cout << "\nA == B? " << (A == B ? "Yes" : "No") << endl;

    return 0;
}