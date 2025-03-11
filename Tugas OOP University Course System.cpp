#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int stock;
    string category;

public:
    Product(int id, string name, double price, int stock, string category)
        : id(id), name(name), price(price), stock(stock), category(category) {}

    void updatePrice(double new_price) {
        if (new_price < 0) {
            cout << "Harga tidak bisa negatif!" << endl;
            return;
        }
        price = new_price;
    }

    void updateStock(int quantity) {
        if (stock + quantity < 0) {
            cout << "Stok tidak cukup!" << endl;
            return;
        }
        stock += quantity;
    }

    double applyPercentageDiscount(double discount_percentage) {
        if (discount_percentage < 0 || discount_percentage > 100) {
            throw invalid_argument("Persentase diskon harus antara 0 dan 100");
        }
        return price * (1 - discount_percentage / 100);
    }

    double applyFixedDiscount(double discount_amount) {
        if (discount_amount < 0 || discount_amount > price) {
            throw invalid_argument("Diskon tidak valid!");
        }
        return price - discount_amount;
    }

    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Nama: " << name << endl;
        cout << "Harga: " << price << endl;
        cout << "Stok: " << stock << endl;
        cout << "Kategori: " << category << endl;
    }
};

int main() {
    Product product1(1, "Laptop", 1000, 10, "Elektronik");
    product1.displayInfo();

    // Menggunakan diskon persentase
    double discounted_price1 = product1.applyPercentageDiscount(15);
    cout << "Harga setelah diskon 15%: " << discounted_price1 << endl;

    // Menggunakan diskon tetap
    double discounted_price2 = product1.applyFixedDiscount(200);
    cout << "Harga setelah diskon tetap 200: " << discounted_price2 << endl;

    return 0;
}
