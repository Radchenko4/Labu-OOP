#include <iostream>
#include <cmath>
using namespace std;

class Square {
  private:
    int side;

  public:
    Square(int s = 0) {
        side = s;
    }

    int getSide() {
        return side;
    }

    void setSide(int s) {
        side = s;
    }

    int area() {
        return side * side;
    }

    void printSqr() {
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
    }

    friend Square frd(Square s1, Square s2);
};

// дружня функція, що обчислює площу нового квадрата
Square frd(Square s1, Square s2) {
    int newSide = sqrt(s1.area() + s2.area());
    return Square(newSide);
}

int main() {
    Square s1(10); // створення першого квадрата
    Square s2(22); // створення другого квадрата
    Square s3 = frd(s1, s2); // створення нового квадрата

    s1.printSqr(); // виведення значень першого квадрата
    s2.printSqr(); // виведення значень другого квадрата
    s3.printSqr(); // виведення значень нового квадрата
    system("pause");
    return 0;
}