#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    class Registration{
    private:
        string username, userPassword, myArray[2];
        string currentUsername, currentPassword;
        int inputNumber;
    public:
        ofstream file;
        void signIn_or_Login(){
            cout << "Enter 1 to login \nEnter 2 to sign up: \n";
                cin >> inputNumber;

                    if(inputNumber == 1){
                        cout << "Enter username: " << endl;
                            cin >> currentUsername;
                        cout << "Enter password: " << endl;
                            cin >> currentPassword;
                            ifstream file("UserInput.txt");
                                for(int i = 0; i < 2; i++){
                                    file >> myArray[i];
                                }
                            if(myArray[0] == currentUsername && myArray[1] == currentPassword){
                                cout << "Welcome back!";
                            }
                                else{
                                    cout << "Wrong username or password.";
                                }
                    }

                    else if(inputNumber == 2){
                        file.open("UserInput.txt");
                            cout << "Enter a username: ";
                        cin >> username;
                            cout << "Enter a password: ";
                        cin >> userPassword;
                            file << username << " " << userPassword << endl;
                   }
                    else if(inputNumber < 1 || inputNumber > 2){
                        cout << "You entered an invalid input, please try again later.";
                    }
        }

    };

int main()
{
    Registration user1;
    user1.signIn_or_Login();
    user1.file.close();
    return 0;
}
