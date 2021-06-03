#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <map>
using namespace std;

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
            exec(instruction);
            this_thread::sleep_for(chrono::milliseconds(2));
        
        }
    }

    uint16_t next_instruction(){
        return 0;
    }

    void exec(uint16_t instruction){
        int l = (instruction & 0xF000) >> 12;
        int x = (instruction & 0x0F00) >> 8;
        int y = (instruction & 0x00F0) >> 4;

        int nnn = instruction & 0x0FFF;
        int nn = instruction & 0x00FF;
        int n = instruction & 0x000F;
    }
    private:
    void jump(uint16_t instruction){
        pc = instruction;
    }

    void call(uint16_t instruction){
        stack.push_back(pc);
        jump(instruction);
    }

    void ret(){
        pc = stack.back();
        stack.pop_back();
    }
 
};

int main(){
    cout << "HELLO \n Enter a name: " << endl;
    string name;
    cin >> name;
    cout << name << endl;
    return 0;
}