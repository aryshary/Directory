#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Directory {
    vector<string> names;
    vector<string> ceos;
    vector<string> phones;
    vector<string> addresses;
    vector<string> types;
    const string fileName = "directory.txt";
public:
    Directory() {
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл для читання.\n";
            return;
        }
        string name, ceo, phone, address, type;
        while (getline(file, name) && getline(file, ceo) && getline(file, phone) && getline(file, address) && getline(file, type)) {
            names.push_back(name);
            ceos.push_back(ceo);
            phones.push_back(phone);
            addresses.push_back(address);
            types.push_back(type);
        }
        file.close();
    }

    void search(string info_type, string info) {
        for (int i = 0; i < names.size(); i++) {
            if ((info_type == "name" && names[i] == info) || (info_type == "ceo" && ceos[i] == info) || (info_type == "phone" && phones[i] == info) || (info_type == "type" && types[i] == info)) {
                cout << "Назва фірми: " << names[i] << "\nВласник: " << ceos[i] << "\nТелефон: " << phones[i] << "\nАдреса: " << addresses[i] << "\nРід діяльності: " << types[i] << "\n";
            }
        }
    }

    void display() {
        for (int i = 0; i < names.size(); i++) {
                cout << "Назва фірми: " << names[i] << "\nВласник: " << ceos[i] << "\nТелефон: " << phones[i] << "\nАдреса: " << addresses[i] << "\nРід діяльності: " << types[i] << "\n";
        }
    }

    void add() {
        string name, ceo, phone, address, type;
        cout << "Назва фірми: ";
        getline(cin, name);
        names.push_back(name);
        cout << "Власник: ";
        getline(cin, ceo);
        ceos.push_back(ceo);
        cout << "Телефон: ";
        getline(cin, phone);
        phones.push_back(phone);
        cout << "Адреса: ";
        getline(cin, address);
        addresses.push_back(address);
        cout << "Рід діяльності: ";
        getline(cin, type);
        types.push_back(type);
        ofstream file(fileName, ios::app);
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл для запису.\n";
            return;
        }
        file << name << "\n" << ceo << "\n" << phone << "\n" << address << "\n" << type << "\n";
        file.close();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Directory directory;
    int choice;
    do {
        cout << "Що бажаєте зробити?\n1. Додати фірму\n2. Пошук за назвою\n3. Пошук за власником\n4. Пошук за номером телефону\n5. Пошук за родом діяльності\n6. Виведення на екран\nВийти - 0\nВаш вибір: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            directory.add();
            break;
        case 2: {
            string name;
            cout << "Введіть назву фірми: ";
            getline(cin, name);
            directory.search("name", name);
            break;
        }
        case 3: {
            string ceo;
            cout << "Введіть власника: ";
            getline(cin, ceo);
            directory.search("ceo", ceo);
            break;
        }
        case 4: {
            string phone;
            cout << "Введіть номер телефону: ";
            getline(cin, phone);
            directory.search("phone", phone);
            break;
        }
        case 5: {
            string type;
            cout << "Введіть рід діяльності: ";
            getline(cin, type);
            directory.search("type", type);
            break;
        }
        case 6:
            directory.display();
            break;
        case 0: break;
        default:
            cout << "Виберіть число від 0 до 6\n";
            break;
        }
    } while (choice != 0);
    return 0;
}