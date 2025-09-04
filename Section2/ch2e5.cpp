#include <iostream>
#include <stdexcept>

using namespace std;

class CS310Exception : public exception{

    private:
        string message;
    public:
        CS310Exception(const string& msg): message(msg)(){
            const char* what() c
        }
}