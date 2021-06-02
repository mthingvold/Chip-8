#include <iostream>
#include <vector>
using namespace std;

#include <map>

class chip8 {
    public:
    uint8_t v[16];
    uint16_t pc;
    uint16_t i;
    uint8_t delay_timer;
    uint8_t sound_timer;
    vector<uint16_t> stack;
};

int main(){
    cout << "HELLO \n Enter a name: " << endl;
    string name;
    cin >> name;
    cout << name << endl;
    return 0;
}