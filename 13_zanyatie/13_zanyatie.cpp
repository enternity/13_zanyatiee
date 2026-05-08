#include <iostream>
#include <cmath>

using namespace std;


// БАЗОВЫЙ КЛАСС ВЕКТОРА
class Vector {
protected:
    static double maxLen;

public:
    virtual double length() = 0;
    virtual void show() = 0;

    static void showMaxLen() {
        cout << "Max length = " << maxLen << endl;
    }

    void updateMax(double len) {
        if (len > maxLen) {
            maxLen = len;
        }
    }

    virtual ~Vector() {}
};

double Vector::maxLen = 0;


// 2D ВЕКТОР
class Vector2D : public Vector {
private:
    double x;
    double y;

public:
    Vector2D(double xx = 0, double yy = 0) {
        x = xx;
        y = yy;

        updateMax(length());
    }

    double length() {
        return sqrt(x * x + y * y);
    }

    void show() {
        cout << "2D Vector: (" << x << ", " << y << ")" << endl;
        cout << "Length = " << length() << endl;
    }
};


// 3D ВЕКТОР
class Vector3D : public Vector {
private:
    double x;
    double y;
    double z;

public:
    Vector3D(double xx = 0, double yy = 0, double zz = 0) {
        x = xx;
        y = yy;
        z = zz;

        updateMax(length());
    }

    double length() {
        return sqrt(x * x + y * y + z * z);
    }

    void show() {
        cout << "3D Vector: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Length = " << length() << endl;
    }
};


// ШАБЛОННЫЙ КЛАСС МАССИВА
template <class T>
class Array {
private:
    T* arr;
    int size;

public:
    Array(int s = 0) {
        size = s;
        arr = new T[size];
    }

    ~Array() {
        delete[] arr;
    }

    T& operator[](int index) {
        return arr[index];
    }

    bool operator==(Array<T>& other) {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(Array<T>& other) {
        return !(*this == other);
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


// MAIN
int main() {

    cout << "===== VECTOR TEST =====" << endl;

    Vector2D v1(3, 4);
    Vector3D v2(1, 2, 2);

    v1.show();
    cout << endl;

    v2.show();
    cout << endl;

    Vector::showMaxLen();

    cout << endl;
    cout << "===== ARRAY TEST =====" << endl;

    Array<int> a1(3);
    Array<int> a2(3);

    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;

    a2[0] = 1;
    a2[1] = 2;
    a2[2] = 3;

    cout << "Array 1: ";
    a1.show();

    cout << "Array 2: ";
    a2.show();

    if (a1 == a2) {
        cout << "Arrays are equal" << endl;
    }

    a2[2] = 10;

    if (a1 != a2) {
        cout << "Arrays are NOT equal" << endl;
    }

    return 0;
}