// license test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "../../SDK/Utils/xorstr.h"
#include <Windows.h>
using namespace std;
static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char user[20];
static char key[25];
static bool state;


namespace auth {

    bool randon_unimportant_math_util(const char* user, const char* users_license)
    {
        std::string license;
        size_t ll = strlen(users_license);
        size_t l = strlen(user), lic_ctr = 0;
        int add = 0;

        for (size_t i = 0; i < ll; i++)
            if (users_license[i] != '-')
                license += users_license[i];

        while (lic_ctr < license.length()) {
            size_t i = lic_ctr;
            i %= l;
            int current = 0;
            while (i < l) current += user[i++];
            current += add;
            add++;
            if (license[lic_ctr] != letters[current % sizeof letters])
                return false;
            lic_ctr++;
        }
        return true;
    }

    bool first_use()
    {
        cout << "Welcome, new user. Please input your username and key\n";
        cout << "Username: ";
        cin >> user;
        cout << "\nLicense key: ";
        cin >> key;
        bool value = randon_unimportant_math_util((const char*)user, (const char*)key);
        if (value) {
            goto label;
        }
        return value;
    label:
        ofstream a_file(xorstr_("key.txt"));
        a_file.open("asdfasdf.txt");
        state = value;
        a_file << key;
        return value;
    }

    bool returning_user(ifstream& file)
    {
        cout << "Welcome back, please input your username\n";
        cout << "Username: ";
        cin >> user;
        file >> key;
        bool value = randon_unimportant_math_util((const char*)user, (const char*)key);
        if (value) {
            state = value;
        }
        return value;
    }

    int main()
    {
        Logger::LogDebug("Running Main");
        ifstream a_file("key.txt");
        a_file.open("key.txt");
        if (!a_file) {
            while (!state) {
                bool value = first_use();
                if (value) {
                    cout << "Your key is valid. Thank you for downloading our software\n";

                    return 0;
                }
                else {
                    cout << "Invalid key, please reenter\n";
                }
            }
        }
        else {
            Logger::LogDebug("key.txt exists");
            while (!state) {
                bool value = returning_user(a_file);
                if (value) {
                    cout << "Your key is valid. Thank you for choosing our software\n";

                    return 0;
                }
                else {
                    cout << "The username and key are do not match. Please reenter\n";
                }
            }
        }
    }
}

