#include "eye_sec_user.h"
#include <QApplication>

std::vector<QString> initialize_namelist() {
    std::vector<QString> result;
    std::string line;
    std::ifstream file_in;
    file_in.open("test.txt", std::ios::in);
    while (std::getline(file_in, line)) {
        result.push_back(QString::fromStdString(line));
    }
    file_in.close();
    return result;
}
bool is_equal(std::string s1, std::string s2) {
    if (0 == std::strcmp(s1.c_str(),s2.c_str())) {
        return true;
    } else return false;
}
void admin_client() {
    std::cout << "Eye Security - Admin Access\nMenu: \n" <<
                 "1. Add an eye \n2. Remove an eye\n" <<
                 "3. Add a user \n4. Remove a user\n5. Quit \n" <<
                 "Choice entry: ";

}
int getPerson(std::vector<Person> people, std::string name) {
    int result;
    if (people.size() == 0) {
        return 0;
    }
    else {
        for (unsigned int i = 0; i < people.size(); i++) {
            if (is_equal(name, people[i].getName())) {
                result = i;
            }
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    std::string input;
    std::cout << "Please specify which client to run: 'admin' or 'user'.\nEntry: ";
    std::cin >> input;
    std::vector<Person> people;
    if (is_equal(input, "admin")) {
        int admin_choice = 0;
        while (admin_choice != 5) {
            admin_client();
            std::cin >> admin_choice;
            //adding an eye index
            if (admin_choice == 1) {
                std::cout << "Enter Person's name ";
                std::cin >> input;

                int person_index = getPerson(people, input);
                int index_number;
                std::cout << "Enter the exact file index of the eye to add (e.g. 2) \nEntry: ";
                std::cin >> index_number;
//                people[person_index].addIrisInstance(a);

            } //removing an eye index

            else if (admin_choice == 2) {
                std::cout << "Enter Person's name ";
                std::cin >> input;

                int person_index = getPerson(people, input);
                int index_number;
                std::cout << "Enter the exact file index of the eye to add (e.g. 2) \nEntry: ";
                std::cin >> index_number;
                people[person_index].removeIrisInstance(index_number);

            } //adding a person
            else if (admin_choice == 3) {
                std::cout << "Enter the name of the person to be added (e.g. John Smith) \nEntry: ";
                std::cin >> input;
                Person p(input);
                people.push_back(p);

            } //removing a person

            else if (admin_choice == 4) {
                std::cout << "Enter the name of the person to be removed (e.g. John Smith) \nEntry: ";
                std::cin >> input;
                people.erase(people.begin() + getPerson(people, input));


            } else if (admin_choice == 5) {
                std::cout << "Exiting...\n";
            } else {
                std::cout << "Invalid choice.\n";
            }
        }

    } else if (is_equal(input, "user")) {
        QApplication a(argc, argv);
        eye_sec_user w;
        w.show();

        return a.exec();
    } else {
        std::cout << "Invalid entry. Ending program.\n";
        return 0;
    }
}
