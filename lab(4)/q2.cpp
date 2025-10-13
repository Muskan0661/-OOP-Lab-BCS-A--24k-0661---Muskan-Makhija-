#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int stockQuantity;

public:
    Product(int id, string n, double p, int q) {
        this->id = id;
        this->name = n;
        this->price = p;
        this->stockQuantity = q;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStock() { return stockQuantity; }

    void reduceStock(int q) { stockQuantity -= q; }
    void increaseStock(int q) { stockQuantity += q; }

    void display() {
        cout << "ID: " << id
             << " , name: " << name
             << " , price: " << price
             << " , stock: " << stockQuantity << endl;
    }
};

class ShoppingCart {
private:
    Product** items;
    int* quantities;
    int capacity;
    int count;

public:
    ShoppingCart(int capacity = 10) {
        this->capacity = capacity;
        this->count = 0;
        items = new Product*[capacity];
        quantities = new int[capacity];
    }

    ShoppingCart(Product* p, int q, int capacity = 10) {
        this->capacity = capacity;
        this->count = 0;
        items = new Product*[capacity];
        quantities = new int[capacity];
        addProduct(p, q);
    }

    void addProduct(Product* p, int q) {
        if (p->getStock() < q) {
            cout << "not enough stock: " << p->getName() << endl;
            return;
        }
        if (count == capacity) {
            cout << "cart is full!\n";
            return;
        }
        items[count] = p;
        quantities[count] = q;
        count++;
        p->reduceStock(q);
        cout << q << " x " << p->getName() << " added to cart. \n";
    }

    void removeProduct(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == id) {
                items[i]->increaseStock(quantities[i]);
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                count--;
                found = true;
                cout << "product removed from cart.\n";
                break;
            }
        }
        if (!found) cout << "product not found in cart.\n";
    }

    void displayCart() {
        cout << "\n Shopping Cart \n";
        if (count == 0) {
            cout << "cart is empty!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << items[i]->getName()
                 << " (quantity: " << quantities[i]
                 << ", Price each: " << items[i]->getPrice()
                 << ", Subtotal: " << items[i]->getPrice() * quantities[i]
                 << ")\n";
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->getPrice() * quantities[i];
        }
        return total;
    }

    ~ShoppingCart() {
        delete[] items;
        delete[] quantities;
    }
};

int main() {
    Product p1(1, "chips", 100, 10);
    Product p2(2, "chocolate", 500, 20);
    Product p3(3, "cup cake", 50, 20);

    ShoppingCart cart;

    cart.addProduct(&p1, 1);
    cart.addProduct(&p2, 2);
    cart.addProduct(&p3, 3);

    cart.displayCart();
    cout << "total Price: " << cart.calculateTotal() << endl;

    cart.removeProduct(2);

    cart.displayCart();
    cout << "total Price: " << cart.calculateTotal() << endl;

    return 0;
}
