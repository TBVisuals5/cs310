#include <iostream>
#include <stdexcept>

using namespace std;

void divide(int a, int b){
    if (b==0){
        throw invalid_argument("Division by zero is invalid!");
    }
    cout <<" Result: " << a/b << endl;
}

int main() {

    string user_input = "y";
    int a, b;

    while(user_input=="y"){
        try
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            divide(10,0);
        }
            catch(const invalid_argument& e)
        {
            cerr << "Caught: "<< e.what() << '\n';
        }
            catch(const exception& e) {

        }

        cout << " Do you want to tray again?[y/n]";
        cin >> a >> b;
    }
    
}