#include <iostream>
#include <vector>
#include<math.h>

using namespace std;
// Ієрархія класів

// Ієрархія класів

class Shape {
public:
virtual double getSurfaceArea() const = 0; // чисто віртуальна функція
virtual ~Shape() {} // віртуальний деструктор для правильного видалення пам'яті
};

class Sphere : public Shape {
private:
double radius;
public:
Sphere(double r) : radius(r) {}
double getSurfaceArea() const override; // перевизначення чисто віртуальної функції
};

class GeometricBody : public Shape {
protected:
int numSides;
public:
virtual double getVolume() const = 0; // чисто віртуальна функція
virtual ~GeometricBody() {} // віртуальний деструктор для правильного видалення пам'яті
};

class Parallelepiped : public GeometricBody {
private:
double length, width, height;
public:
Parallelepiped(double l, double w, double h) : length(l), width(w), height(h) {}
double getSurfaceArea() const override; // перевизначення чисто віртуальної функції
double getVolume() const override; // перевизначення чисто віртуальної функції
};

class Tetrahedron : public GeometricBody {
private:
double sideLength;
public:
Tetrahedron(double s) : sideLength(s) {}
double getSurfaceArea() const override; // перевизначення чисто віртуальної функції
double getVolume() const override; // перевизначення чисто віртуальної функції
};

// Реалізація класів

double Sphere::getSurfaceArea() const {
return 4 * M_PI * radius * radius;
}

double Parallelepiped::getSurfaceArea() const {
return 2 * (length * width + length * height + width * height);
}

double Parallelepiped::getVolume() const {
return length * width * height;
}

double Tetrahedron::getSurfaceArea() const {
return sqrt(3) * sideLength * sideLength;
}

double Tetrahedron::getVolume() const {
return pow(sideLength, 3) / (6 * sqrt(2));
}

// Демонстраційна програма

int main() {
Shape* shapes[4];

Sphere sphere(5);
shapes[0] = &sphere;

Parallelepiped parallelepiped(3, 4, 5);
shapes[1] = &parallelepiped;

Tetrahedron tetrahedron(6);
shapes[2] = &tetrahedron;

GeometricBody* body = new Parallelepiped(2, 3, 4);
// body->setNumSides(6);
shapes[3] = body;

for (int i = 0; i < 4; i++) {
    cout << "Surface area: " << shapes[i]->getSurfaceArea() << endl;
}

// delete body;

return 0;
}


// Відповіді на питання

// Якщо базовий клас не абстрактний, зробити відповідну поліморфну
// функцію не віртуальною і подивитися, що буде. Пояснити отриманий
// результат.

// Якщо базовий клас не є абстрактним і ми зробимо поліморфну функцію не віртуальною, то при виклику цієї функції для 
// об'єктів похідних класів буде викликана версія функції з базового класу, а не з похідного класу. Це може призвести до 
// неправильних результатів, оскільки версія функції з базового класу не знає про нові поля та методи, які були додані у 
// похідному класі. Тому, якщо ми хочемо мати поліморфну функцію, то базовий клас має бути абстрактним, а функція - віртуальною.


