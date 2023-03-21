#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Student {
public:
    string surname;
    string name;
    vector<int> marks;

    Student(string surname, string name, vector<int> marks) {
        this->surname = surname;
        this->name = name;
        this->marks = marks;
    }
};

int main() {
    // Відкриття файлу для читання
    ifstream file("data.txt");

    // Створення порожнього вектора для екземплярів класу
    vector<Student> students;

    // Читання даних з файлу та створення екземплярів класу
    string line;
    while (getline(file, line)) {
        string surname, name;
        vector<int> marks;

        // Розділення рядка на прізвище, ім'я та оцінки
        int pos = 0;
        while (pos < line.size()) {
            int next_pos = line.find_first_of(" \t", pos);
            if (next_pos == string::npos) {
                next_pos = line.size();
            }

            if (surname.empty()) {
                surname = line.substr(pos, next_pos - pos);
            } else if (name.empty()) {
                name = line.substr(pos, next_pos - pos);
            } else {
                string mark_str = line.substr(pos, next_pos - pos);
                try {
                    int mark = stoi(mark_str);
                    marks.push_back(mark);
                } catch (const invalid_argument& e) {
                }
            }

            pos = next_pos + 1;
        }

        // Створення екземпляру класу та додавання його до вектора
        Student student(surname, name, marks);
        students.push_back(student);
    }

    // Сортування вектора студентів за алфавітом імен
    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.name < s2.name;
    });

    // Виведення імен студентів без п'ятірок
    for (const auto& student : students) {
        if (find(student.marks.begin(), student.marks.end(), 5) == student.marks.end()) {
            cout << student.name <<  endl;
        }
    }
    return 0;
}