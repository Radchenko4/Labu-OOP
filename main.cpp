#include<iostream>
using namespace std;
// Клас Документ
class Document {
protected:
    int number;
    string date;
    float sum;
public:
    Document(int num, string d, float s) { // конструктор
        number = num;
        date = d;
        sum = s;
    }
    void setSum(float s) { // метод для зміни суми
        sum = s;
    }
    ~Document() {} // деструктор
};

// Клас Квитанція
class Receipt : public Document { // успадковуємо від Document
private:
    string recipient;
    string purpose;
public:
    Receipt(int num, string d, float s, string r, string p) : Document(num, d, s) { // конструктор зі списком ініціалізації
        recipient = r;
        purpose = p;
    }
    void printReceipt() { // метод для виведення даних про квитанцію
        cout << "Receipt #" << number << " issued on " << date << endl;
        cout << "Recipient: " << recipient << endl;
        cout << "Purpose: " << purpose << endl;
        cout << "Amount: " << sum << endl;
    }
    ~Receipt() {} // деструктор
};

// Клас Накладна
class Invoice : public Document { // успадковуємо від Document
private:
    string supplier;
    string product;
public:
    Invoice(int num, string d, float s, string sup, string prod) : Document(num, d, s) { // конструктор зі списком ініціалізації
        supplier = sup;
        product = prod;
    }
    void printInvoice() { // метод для виведення даних про накладну
        cout << "Invoice #" << number << " issued on " << date << endl;
        cout << "Supplier: " << supplier << endl;
        cout << "Product: " << product << endl;
        cout << "Amount: " << sum << endl;
    }
    ~Invoice() {} // деструктор
};

// Клас Чек
class Check : public Document { // успадковуємо від Document
private:
    string product_name;
    int quantity;
    float price;
public:
    Check(int num, string d, float s, string pname, int q, float p) : Document(num, d, s) { // конструктор зі списком ініціалізації
        product_name = pname;
        quantity = q;
        price = p;
    }
    void printCheck() { // метод для виведення даних про чек
        cout << "Check #" << number << " issued on " << date << endl;
        cout << "Product: " << product_name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per unit: " << price << endl;
        cout << "Total amount: " << sum << endl;
    }
    ~Check() {} // деструктор
};

// Демонстраційна програма
int main() {
    Document doc(123, "01.01.2022", 1000); // створення об'єкту класу Document
    doc.setSum(1500); // зміна суми
    

    Receipt receipt(456, "02.01.2022", 500, "Otrumyvach", "Pruznachenya platezhy"); // створення об'єкту класу Receipt
    receipt.printReceipt();

    Invoice invoice(789, "03.01.2022", 2000, "Postachalnuk", "product name"); // створення об'єкту класу Invoice
    invoice.printInvoice();

    Check check(246, "04.01.2022", 300, "product name", 3, 100); // створення об'єкту класу Check
    check.printCheck();

    return 0;
}

// Діаграма класів
/*
     Document
        / \
       /   \
Receipt Invoice
       \   /
        \ /
       Check
*/