
#include <iostream>

using namespace std;

class Array {
int* data;  
int size; 
public:

Array(int size) {
this->size = size;
data = new int[size]; 
}

Array(const Array& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

~Array() {
    delete[] data; 
}


int& operator[](int index) {
    return data[index];
}

const int& operator[](int index) const {
    return data[index];
}

void print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

bool operator==(const Array& other) const {
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
};

int main() {
Array arr1(5); 
Array arr2(5); 

for (int i = 0; i < 5; i++) {
    arr1[i] = i;
    arr2[i] = i;
}


arr1.print(); 
arr2.print(); 

if (arr1 == arr2) {
    cout << "arr1 and arr2 are equal" << endl;
} else {
    cout << "arr1 and arr2 are not equal" << endl;
}

Array arr3(3); 
}