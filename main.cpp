#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;
    int size;
public:
    DynamicArray(int n) {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) { // якщо і парне
                array[i] = i + 3; // то елемент масиву = і + 3
            }
            else { // якщо і не парне
                array[i] = i - 7; // то елемент масиву = і - 7
            }
        }
    }
    ~DynamicArray() {
        delete[] array; // звільнення пам'яті, виділеної під масив
    }
    int* getArray() {
        return array;
    }
    int getSize() {
        return size;
    }
};

void sumThirdElements(DynamicArray arr) {
    int* array = arr.getArray(); // отримання масиву з об'єкту класу
    int size = arr.getSize(); // отримання розміру масиву з об'єкту класу
    int sum = 0;
    for (int i = 2; i < size; i += 3) { // проходження кожного третього елемента масиву
        sum += array[i]; // додавання елемента до загальної суми
        cout << "Summing element " << i << ": " << array[i] << endl; // виведення інформації про оброблений елемент
    }
    cout << "Sum of every third element: " << sum << endl; // виведення загальної суми кожного третього елемента масиву
}

int main() {
    DynamicArray arr(11); // створення об'єкту класу з розміром масиву 11
    sumThirdElements(arr); // виклик функції для обробки масиву
    system("pause");
    return 0;
}