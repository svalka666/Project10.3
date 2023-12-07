#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Product {
    string name;
    string shop;
    double price;
};

void createFile(const string& filename, const Product& product) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Cannot create file." << endl;
        return;
    }
    file << product.name << "," << product.shop << "," << product.price << endl;
    file.close();
}

void displayFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void addProduct(const string& filename, const Product& product) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Cannot open file for appending." << endl;
        return;
    }

    file << product.name << "," << product.shop << "," << product.price << endl;

    file.close();
}

void searchShop(const string& filename, const string& shopName) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, shop;
        double price;

        getline(ss, name, ',');
        getline(ss, shop, ',');
        ss >> price;

        if (shop == shopName) {
            found = true;
            cout << "Shop found:" << endl;
            cout << "Product: " << name << endl;
            cout << "Shop: " << shop << endl;
            cout << "Price: " << price << endl;
            break;
        }
    }

    if (!found) {
        cout << "Shop not found." << endl;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    Product product;
    int n;
    cout << "N: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter product name: ";
        cin >> product.name;
        cout << "Enter shop name: ";
        cin >> product.shop;
        cout << "Enter product price: ";
        cin >> product.price;
        createFile(filename, product);
    }


    int choice;
    do {
        cout << "Menu:\n1. Display file content\n2. Add product\n3. Search shop\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayFile(filename);
            break;
        case 2: {
            Product newProduct;
            cout << "Enter product name: ";
            cin >> newProduct.name;
            cout << "Enter shop name: ";
            cin >> newProduct.shop;
            cout << "Enter product price: ";
            cin >> newProduct.price;

            addProduct(filename, newProduct);
            break;
        }
        case 3: {
            string searchName;
            cout << "Enter shop name to search: ";
            cin >> searchName;
            searchShop(filename, searchName);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
