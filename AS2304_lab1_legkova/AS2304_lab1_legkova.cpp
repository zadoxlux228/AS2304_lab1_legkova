// lab1legkovaAS2304.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Truba {
    string name = "";
    int dlina = -1;
    int diametr = -1;
    bool inRepair = -1;
};

struct KS {
    string name = "";
    int totalWorkshops = -1;
    int activeWorkshops = -1;
    int efficiency = -1;
};

bool sozdano(const Truba& truba) {
    return !(truba.dlina == -1);
}

bool sozdano(const KS& ks) {
    return !(ks.totalWorkshops == -1);
}


int valid_int(std::string message, int min_value, int max_value) {
    int value;

    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min_value || value > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << message;
    }
    return value;
}
void edit_work_status(Truba& truba) {
    if (sozdano(truba)) {
        cout << "New working status(0 - no / 1 - yes): ";
        truba.inRepair = valid_int("New working status(0 - no / 1 - yes): ", 0, 1);
        cout << "New working status is set!" << endl;
    }
    else {
        cout << "The Truba has not been created yet!" << endl;
    }
}


ostream& operator << (ostream& os, const Truba& truba) {
    if (sozdano(truba)) {
        os << "-----Truba-----" << endl
            << "name: " << truba.name << endl
            << "lenght: " << truba.dlina << endl
            << "diameter: " << truba.diametr << endl
            << "is working: " << truba.inRepair << endl
            << "--------------" << endl;
    }
    else {
        os << "The Truba has not been created yet!" << endl;
    }

    return os;
}

void edit_eff(KS& ks) {
    cout << "new eff: ";
    ks.efficiency = valid_int("new eff", 0, 10);
}

ostream& operator << (ostream& os, const KS& ks) {
    if (sozdano(ks)) {
        os << "-----Compressor Station-----" << endl
            << "name: " << ks.name << endl
            << "number of workshops: " << ks.totalWorkshops << endl
            << "workshops in work: " << ks.activeWorkshops << endl
            << "efficiency: " << ks.efficiency << endl
            << "--------------" << endl;
    }
    else {
        os << "The compressor station has not been created yet!" << endl;
    }

    return os;
}



void add_truba(Truba& truba) {
    if (sozdano(truba)) {
        cout << "truba is created already!\n";
    }
    else {
        cout << "-----add Truba-----\n";

        cout << "name:";
        cin.ignore(1000, '\n');
        getline(cin, truba.name);

        cout << "lenght: ";
        truba.dlina = valid_int("lenght: ", 1, 10000);

        cout << "diameter: ";
        truba.diametr = valid_int("diameter: ", 1, 1000);

        cout << "is_working(0 - no / 1 - yes): ";
        truba.inRepair = valid_int("is_working(0 - no / 1 - yes): ", 0, 1);;

        cout << "Truba is created!\n";

        cout << "------------------\n";
    };
}
void add_ks(KS& ks) {
    if (sozdano(ks)) {
        cout << "Compressor station is created already\n";
    }
    else {
        cout << "---add compressor station---\n";

        cout << "name: ";
        cin.ignore(1000, '\n');
        getline(cin, ks.name);

        cout << "number of workshops: ";
        ks.totalWorkshops = valid_int("number of workshops: ", 1, 10000);

        cout << "workshops in work: ";
        ks.activeWorkshops = valid_int("workshops in work: ", 0, ks.totalWorkshops);

        cout << "efficiency: ";
        ks.efficiency = valid_int("effectivnost: ", 0, 10);

        cout << "Comperssor Station is created!\n";

        cout << "----------------------------\n";
    };
}
void save(ofstream& file, const Truba& truba) {
    if (sozdano(truba)) {
        file << "Truba" << endl;
        file << truba.name << endl;
        file << truba.dlina << endl;
        file << truba.diametr << endl;
        file << truba.inRepair << endl;
        cout << "Truba save in file!\n";
    }
    else {
        file << "None" << endl;
        cout << "The Truba has not been created yet!" << endl;
    }
}
void save(ofstream& file, const KS& ks) {
    if (sozdano(ks)) {
        file << "KS" << endl;
        file << ks.name << endl;
        file << ks.totalWorkshops << endl;
        file << ks.activeWorkshops << endl;
        file << ks.efficiency << endl;
        cout << "KS save in file!\n";
    }
    else {
        file << "None" << endl;
        cout << "The KS has not been created yet!" << endl;
    }
}

void save_obj(const Truba& truba, const KS& ks) {
    ofstream file("output.txt");
    if (file.is_open()) {
        save(file, truba);
        save(file, ks);
    }
    else cout << "No file" << endl;
    file.close();
}

void load(std::ifstream& file, KS& ks) {
    if (sozdano(ks)) {
        cout << "KS is created already!\n";
    }
    else {
        file.ignore(10000, '\n');
        getline(file, ks.name);
        file >> ks.totalWorkshops;
        file >> ks.activeWorkshops;
        file >> ks.efficiency;
        cout << "KS is created from file!" << endl;
    }
}
void load(ifstream& file, Truba& truba) {
    if (sozdano(truba)) {
        cout << "Truba is created already!\n";
    }
    else {
        file.ignore(1000, '\n');
        getline(file, truba.name);
        file >> truba.dlina;
        file >> truba.diametr;
        file >> truba.inRepair;
        cout << "Truba is created from file!" << endl;
    }
}

void load_obj(Truba& truba, KS& ks) {
    ifstream file("output.txt");

    if (file.is_open()) {
        string line;
        file >> line;

        if (line == "Truba") {
            load(file, truba);
        }
        else cout << "Truba cant created from file!" << endl;

        file >> line;
        if (line == "KS") {
            load(file, ks);
        }
        else cout << "KS cant created from file!" << endl;

    }
    else cout << "file not created!" << endl;

    file.close();
}

void see_all_objects(const Truba& truba, const KS& ks) {
    cout << truba;
    cout << ks;
}


void print_main_menu() {
    cout << "-----Menu-----\n";
    cout << "0 - exit\n";
    cout << "1 - add Truba\n";
    cout << "2 - add compressor station\n";
    cout << "3 - see all objects\n";
    cout << "4 - edit Truba\n";
    cout << "5 - edit compressor station\n";
    cout << "6 - save in file\n";
    cout << "7 - load from file\n";
    cout << "--------------\n";
};



void main_menu() {
    Truba truba;
    KS ks;

    while (true) {
        print_main_menu();

        int choice = valid_int("vvedite nomer: ", 0, 7);

        switch (choice)
        {
        case 0:
            cout << "Poka!\n";
            return;
        case 1:
            add_truba(truba);
            break;
        case 2:
            add_ks(ks);
            break;
        case 3:
            see_all_objects(truba, ks);
            break;
        case 4:
            edit_work_status(truba);
            break;
        case 5:
            edit_eff(ks);
            break;
        case 6:
            save_obj(truba, ks);
            break;
        case 7:
            load_obj(truba, ks);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};


int main() {
    main_menu();
    return 0;

}