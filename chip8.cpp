#include <iostream>
#include <vector>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <map>

class chip8 {
    public:
    uint8_t v[16];
    uint16_t pc;
    uint16_t i;
    uint8_t delay_timer;
    uint8_t sound_timer;
    vector<uint16_t> stack;
    uint8_t memory[4096];
    bool display_ram[32][64];
    map<uint8_t, SDL_KeyCode> keymap;

    void run(){
        for(;;) {
            if (delay_timer > 0){ delay_timer--;}
            if (sound_timer > 0){ sound_timer--;}
            uint16_t instruction = next_instruction();
        }
    }

    uint16_t next_instruction(){
        return 0;
    }
};

int main(){
    cout << "HELLO \n Enter a name: " << endl;
    string name;
    cin >> name;
    cout << name << endl;
    return 0;
}