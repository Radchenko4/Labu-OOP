#include<iostream>
using namespace std;

class Square{
    private:
        int side;
    public:
        Square(): side(0){} //конструктор без параметрів
        Square(int s): side(s){} //конструктор з параметром
        int getSide(){return side;} //метод для отримання значення сторони
        void setSide(int s){side = s;} //метод для присвоєння значення сторони
        int area(){return side*side;} //метод для обчислення площі квадрата
        Square operator+(Square s){ //перевантаження оператора "+"
            Square temp;
            temp.side = side + s.side;
            return temp;
        }
        Square operator++(){ //перевантаження префіксного оператора "++"
            ++side;
            return Square(side);
        }
        Square operator++(int){ //перевантаження постфіксного оператора "++"
            Square temp(side);
            side++;
            return temp;
        }
        friend ostream& operator<<(ostream& os, Square s){ //перевантаження оператора "<<"
            os << "Side: " << s.side << endl;
            os << "Area: " << s.area() << endl;
            return os;
        }
};

int main(){
    Square s1(5); //створення квадрата зі стороною 5
    Square s2(3); //створення квадрата зі стороною 3
    cout << "Square 1" << endl;
    cout << s1 << endl; //виведення інформації про квадрат 1
    cout << "Square 2" << endl;
    cout << s2 << endl; //виведення інформації про квадрат 2
    Square s3 = s1 + s2; //створення нового квадрата, який є сумою квадратів 1 та 2
    cout << "Square 3 (Sum of square 1 and square 2)" << endl;
    cout << s3 << endl; //виведення інформації про квадрат 3
    cout << "Incrementing square 1 using prefix operator" << endl;
    ++s1; //збільшення сторони квадрата 1 на одиницю за допомогою префіксного оператора "++"
    cout << s1 << endl; //виведення інформації про квадрат 1
    cout << "Incrementing square 2 using postfix operator" << endl;
    cout << s2++ << endl; //збільшення сторони квадрата 2 на одиницю за допомогою постфіксного оператора "++"
    cout << "Square 2 after incrementing using postfix operator" << endl;
    cout << s2 << endl; //виведення інформації про квадрат 2
    return 0;
}