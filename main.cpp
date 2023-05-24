#include <iostream>
#include <random>


using namespace std;

int main(int argc, char* argv[])
{
    string chars = "abcdefghijklmnopqrstuvwxyzABCDDEFGHIJKLMNOPQRSTUVWXYZ0123456789#@!$%&*";
    int randomIndex{0};
    string generated_password{""};
    int password_length{0};

    if (argc < 2) {
        password_length = 16;
    } else {
        password_length = stoi(argv[1]);
    }

    for (int i{0}; i < password_length;i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, chars.length() - 1);
        randomIndex = dis(gen);
        generated_password += chars[randomIndex];
    }

    cout << generated_password << endl;
    
    

    return 0;
}