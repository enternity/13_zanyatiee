#include <iostream>
#include <cmath>

using namespace std;

// Задание a: шаблонный одномерный массив
template <class T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int s = 0) {
        size = s;

        if (size > 0) {
            data = new T[size];
        }
        else {
            data = 0;
        }
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](int index) {
        return data[index];
    }

    bool operator==(const Array<T>& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Array<T>& other) const {
        return !(*this == other);
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};


// Задание b: иерархия классов 2D и 3D векторов
class Vector {
private:
    static double maxLen;

protected:
    static void updateMaxLen(double len) {
        if (len > maxLen) {
            maxLen = len;
        }
    }

public:
    virtual double length() const = 0;
    virtual void show() const = 0;

    static void showMaxLen() {
        cout << "Max length = " << maxLen << endl;
    }

    virtual ~Vector() {}
};

double Vector::maxLen = 0;


class Vector2D : public Vector {
private:
    double x;
    double y;

public:
    Vector2D(double xx = 0, double yy = 0) {
        x = xx;
        y = yy;

        updateMaxLen(length());
    }

    double length() const {
        return sqrt(x * x + y * y);
    }

    void show() const {
        cout << "Vector2D: (" << x << ", " << y << "), length = "
            << length() << endl;
    }
};


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

        updateMaxLen(length());
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    void show() const {
        cout << "Vector3D: (" << x << ", " << y << ", " << z << "), length = "
            << length() << endl;
    }
};


void printVectorArray(Array<Vector*>& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        arr[i]->show();
    }
}


// Проверка задания a
void zadanie_a() {
    cout << endl << "ZADANIE A" << endl;

    Array<int> firstArray(3);
    Array<int> secondArray(3);

    firstArray[0] = 1;
    firstArray[1] = 2;
    firstArray[2] = 3;

    secondArray[0] = 1;
    secondArray[1] = 2;
    secondArray[2] = 3;

    cout << "firstArray: ";
    firstArray.print();

    cout << "secondArray: ";
    secondArray.print();

    cout << "firstArray == secondArray: " << (firstArray == secondArray) << endl;

    secondArray[2] = 10;

    cout << "After changing secondArray:" << endl;

    cout << "firstArray: ";
    firstArray.print();

    cout << "secondArray: ";
    secondArray.print();

    cout << "firstArray != secondArray: " << (firstArray != secondArray) << endl;
}


// Проверка задания b
void zadanie_b() {
    cout << endl << "ZADANIE B" << endl;

    Vector2D vector2d(3, 4);
    Vector3D vector3d(1, 2, 2);

    vector2d.show();
    vector3d.show();

    Vector::showMaxLen();
}


// задание с и его проверка
void zadanie_c() {
    cout << endl << "ZADANIE C" << endl;

    Array<int> numbers1(4);
    Array<int> numbers2(4);

    numbers1[0] = 5;
    numbers1[1] = 10;
    numbers1[2] = 15;
    numbers1[3] = 20;

    numbers2[0] = 5;
    numbers2[1] = 10;
    numbers2[2] = 15;
    numbers2[3] = 20;

    cout << "numbers1: ";
    numbers1.print();

    cout << "numbers2: ";
    numbers2.print();

    cout << "numbers1 == numbers2: " << (numbers1 == numbers2) << endl;

    numbers2[3] = 100;

    cout << "numbers1 != numbers2: " << (numbers1 != numbers2) << endl;

    Vector2D v1(3, 4);
    Vector3D v2(1, 2, 2);
    Vector2D v3(5, 12);

    Array<Vector*> vectors1(2);
    Array<Vector*> vectors2(2);

    vectors1[0] = &v1;
    vectors1[1] = &v2;

    vectors2[0] = &v1;
    vectors2[1] = &v2;

    cout << endl << "vectors1:" << endl;
    printVectorArray(vectors1);

    cout << "vectors2:" << endl;
    printVectorArray(vectors2);

    cout << "vectors1 == vectors2: " << (vectors1 == vectors2) << endl;

    vectors2[1] = &v3;

    cout << "After changing vectors2:" << endl;
    printVectorArray(vectors2);

    cout << "vectors1 != vectors2: " << (vectors1 != vectors2) << endl;

    Vector::showMaxLen();
}


int main() {
    zadanie_a();
    zadanie_b();
    zadanie_c();

    return 0;
}
