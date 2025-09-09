#include <iostream>
#include <stdexcept>

using namespace std;

int main (int argc, char const *argv[])
{
    try{
        bool condition = true;
        int nums[] = {2,5,6,75,90};
        int i;

        cout << "Enter an index: ";
        cin >> i;

        //if (i<0 || i>5){
            //throw out_of_range("Index out of bound!");
        //}

        cout << "Num at index " <<i<< ": " << nums[i] << endl;

        if (condition){
            throw runtime_error("Runtime Errow occured!");
        }
        else {
            throw out_of_range("Index out of bound");
        }
    }
        catch( const runtime_error& e){
            cerr << "Runtime Error" << e.what() << '\n';
        }
        catch( const out_of_range& e){
            cerr << "Out of Range Error" << e.what() << '\n';
        }
        catch( const exception& e){
            cerr << "Error: " << e.what() << '\n';
        }

        cout << "Execution continues..." << endl;
        return 0;
}