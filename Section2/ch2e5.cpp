#include <iostream>
#include <stdexcept>

using namespace std;

class CS310Exception : public exception{

    private:
        string message;

    public:
        CS310Exception(const string& msg): message(msg){}

        const char* what() const noexcept override{
            return message.c_str();
        }
        
};

int main(){
    
    try 
    {
        throw CS310Exception(" Hi this is fun!");
    }
        catch(const CS310Exception& e)
        {
            cerr << e.what() << '\n';
        }
        return 0;
}