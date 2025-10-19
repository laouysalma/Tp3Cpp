#include <iostream>
#include <iomanip>  
using namespace std;

class Buffer {
private:
    size_t size;           
    unsigned char* data;   

public:
 
    Buffer() {
        size = 0;
        data = nullptr;
        cout << "Constructeur par défaut (buffer vide)" << endl;
    }

    
    Buffer(size_t n) {
        size = n;
        data = new unsigned char[n];  
        for (size_t i = 0; i < n; i++)
            data[i] = 0;  
        cout << "Constructeur paramétré (" << size << " octets)" << endl;
    }

    
    Buffer(const Buffer& autre) {
        size = autre.size;
        if (autre.data != nullptr) {
            data = new unsigned char[size];  
            for (size_t i = 0; i < size; i++)
                data[i] = autre.data[i];  
        } else {
            data = nullptr;
        }
        cout << "Constructeur de copie (" << size << " octets copiés)" << endl;
    }

     
    void fill(unsigned char value) {
        for (size_t i = 0; i < size; i++)
            data[i] = value;
    }

     
    void printHex() const {
        cout << "Buffer de " << size << " octet(s) : ";
        for (size_t i = 0; i < size; i++)
            cout << hex << uppercase << setw(2) << setfill('0') << (int)data[i] << " ";
        cout << dec << endl;
    }

     
    size_t getSize() const {
        return size;
    }

     
    ~Buffer() {
        cout << "Destruction du buffer de " << size << " octet(s)" << endl;
        delete[] data;  
    }
};


int main() {
    Buffer b1;        
    Buffer b2(8);     
    b2.fill(0xAA);    
    Buffer b3 = b2;  

    cout << endl;
    b1.printHex();
    b2.printHex();
    b3.printHex();

    cout << endl;
    return 0; 
}
