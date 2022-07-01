#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

class account
{
    string username, password, user, pass;
    static int count;
    int l;
    string uname;
    string passw;
    string sUserID, spass, sID;
    int option, c = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    string a, b;

public:
    void start()
    {
        cout << "1- SIGN UP" << endl;
        cout << "2- LOG IN" << endl;
        cout << "3- FORGET PASSWORD" << endl;
        cout << "enter option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            forget();
        }
    }
    void login()
    {
    x:
        cout << "enter username: ";
        cin >> username;
        cout << "enter password: ";
        cin >> password;

        ifstream myfile("userData.bin");

        while (myfile >> user >> pass)
        {
            if (user == username && pass == password)
            {
                count = 1;
            }
        }
        myfile.close();
        if (count == 1)
        {
            cout << "login successful" << endl;
        }
        else
        {
            cout << "try again" << endl;
            goto x;
        }
    }

    void signup()
    {
        cout << "\f\fenter username: ";
        cin >> uname;
    label:
        cout << "\n";
        cout << "enter password: ";
        cin >> passw;
        l = passw.length();

        for (int i = 0; i < l; i++)
        {
            for (int j = 33; j < 47; j++)
            {

                a = char(j);
                if (passw[i] == a[0])
                {
                    c1 = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int g = 48; g < 57; g++)
            {

                a = char(g);
                if (passw[i] == a[0])
                {
                    c3 = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int g = 58; g < 64; g++)
            {

                a = char(g);
                if (passw[i] == a[0])
                {
                    c1 = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 65; j < 90; j++)
            {

                a = char(j);
                if (passw[i] == a[0])
                {
                    c4 = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 91; j < 96; j++)
            {

                a = char(j);
                if (passw[i] == a[0])
                {
                    c1 = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 97; j < 122; j++)
            {

                a = char(j);
                if (passw[i] == a[0])
                {                                            
                    c2 = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 123; j < 127; j++)
            {

                a = char(j);
                if (passw[i] == a[0])
                {
                    c1 = 1;
                    break;
                }
            }
        }
        if (l > 8)
        {
            c = 1;
        }

        if (c == 1 && c2 == 1 && c1 == 1 && c3 == 1 && c4 == 1)
        {
            goto label2;
        }
        else
        {

            cout << "Password is weak!" << endl;

            cout << "Strong password suggestion: ";

            srand(time(NULL));
            for (int i = 0; i < 10; i++)
            {

                int val1 = 33 + rand() % 94;
                b = char(val1);
                if (b == "<" || b == ">")
                {
                    b = "1";
                }
                cout << b;
            }

            goto label;
        }

    label2:
        ofstream file("userData.bin", ios::binary | ios::app);

        file << uname << " " << passw << endl;

        file.close();

        cout << "registration successful" << endl;

        login();
    }

    void forget()
    {
        cout << "\f\fenter username: ";
        cin >> sUserID;

        ifstream f1("userData.bin");
        while (f1 >> sID >> spass)
        {
            if (sID == sUserID)
            {
                count = 1;
            }
        }
        f1.close();
        if (count == 1)
        {
            cout << "Your password is " << spass << endl;
            login();
        }
        else
        {
            cout << "Account not found";
        }
    }
};
int account::count;

class user : public account
{
    int option;
    string getcontent;
    static int i;

public:
    void professions()
    {
        cout << "1- Electrician" << endl;
        cout << "2- Mechanic" << endl;
        cout << "3- Plumber" << endl;
        cout << "4- Maid" << endl;
        cout << "5- Gardening" << endl;
        cin >> option;

        if (option == 1)
        {
            ifstream newfile;
            newfile.open("electrician.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "\n";
                    i++;
                }
            }
            newfile.close();
            ////// case 1 ends
        }
        else if (option == 2)
        {
            ifstream newfile;
            newfile.open("mechanic.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "\n";
                    i++;
                }
            }
            newfile.close();
            //// case 2 ends
        }
        else if (option == 3)
        {
            ifstream newfile;
            newfile.open("plumber.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "\n";
                    i++;
                }
            }
            newfile.close();
            ///// case 3 ends
        }
        else if (option == 4)
        {
            ifstream newfile;
            newfile.open("maid.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "\n";
                    i++;
                }
            }
            newfile.close();
            /////// case 4 ends
        }
        else if (option == 5)
        {
            ifstream newfile;
            newfile.open("gardenar.txt", ios::binary | ios::in);
            if (newfile.is_open())
            {
                while (getline(newfile, getcontent))
                {
                    cout << i << "- " << getcontent << "\n";
                    i++;
                }
            }
            newfile.close();
            ////// case 5 ends
        }
    }
};
int user::i = 1;

int main()
{
    user obj;
    int choice;

    cout << "1- Customer" << endl;
    cout << "2- Worker" << endl;
    cout << "3- Admin" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        obj.start();
        obj.professions();
        break;
    case 2:
        obj.start();
        break;
    case 3:
        obj.start();
    }
}
