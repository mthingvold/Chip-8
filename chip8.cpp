#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <map>
#include <limits.h>
using namespace std;

const int DISPLAY_HEIGHT = 64;
const int DISPLAY_WIDTH = 32;
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
        int big = memory[pc % 4096];
        int little = memory[(pc+1)%4096];
        pc = pc + 2;
        return (big << 8)+ little;
    }

    void exec(uint16_t instruction){
        int l = (instruction & 0xF000) >> 12;
        int x = (instruction & 0x0F00) >> 8;
        int y = (instruction & 0x00F0) >> 4;

        int nnn = instruction & 0x0FFF;
        int nn = instruction & 0x00FF;
        int n = instruction & 0x000F;


        switch (l)
        {
        case 0x00:
            if (x==0x00 && y == 0x0E){
                if (n==0x00){clear();}
                else if (n==0x0E){ret();}
            }
            /* code */
            break;
        case 0x01:
            jump(nnn);
            break;
        case 0x02:
            call(nnn);
            break;
        case 0x03:
            if (v[x] == nn) {skip();}
            break;
        case 0x04:
            if (v[x] != nn) {skip();}
            break;
        case 0x05:
            if (v[x] == v[y]) {skip();}
            break;
        case 0x06:
            v[x] = nn;
            break;
        case 0x07:
            v[x] = (v[x] + nn) % INT8_MAX;
            break;
        case 0x08:
            
            opcodes0x08(x,y,n);
            break;
        case 0x0A:
            i = nnn;
            break;
        case 0x0B:
            jump(nnn + v[0]);
            break;
        case 0x0C:
            v[x] = (rand() % 0xFF) & nn;
            break;
        case 0x0D:
            opcodes0x0D(x,y,n);
            break;

        case 0x0E:
            //TODO
            break;
        default:
            throw(l);
            break;
        }
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
    void clear(){
        cout << "\033[2J\033[1;1H";
        //TODO add the display related code
    }
    void skip(){
        pc = pc + 2;
    }

    void opcodes0x08(int x, int y, int n){
        switch (n){
            case 0:
            v[x] = v[y];
            break;
            case 1:
            v[x] |= v[y];
            break;
            case 2:
            v[x] &= v[y];
            break;
            case 3:
            v[x] ^= v[y];
            break;
            case 4:
            if (v[x] > UINT8_MAX - v[y]){v[0x0F] = 1;} else{v[0x0F] = 0;}
            v[x] = (v[x] + v[y]) % UINT8_MAX;
            break;
            case 5:
            if (0 > UINT8_MAX - (v[x]+v[y])){v[0x0f] = true;}else{v[0x0f] = false;}
            v[x] = v[x] - v[y];
            break;
            case 6:
            v[0x0f] = v[x] & 0x01;
            v[x] >>= 1;
            break;
            case 7:
            v[x] = y - x;
            v[0x0F] = v[x] > y;
            break;

            case 0x0E:
            v[0x0F] = (v[x] & 0x80)>> 7;
            v[x] <<= 1;
            break;
            default:
            cout << "ERRRORRRRR" << endl;
            break;
        }
    }
    void opcodes0x0D(int x, int y, int n){
        v[0x0F] = 0;

        for(int row = 0; row< n; row++){
            unsigned int py = ((v[y] + row) % (uint8_t)DISPLAY_HEIGHT);
            unsigned int sprite_row = memory[i + row];

            for(int col = 0; col < 8; col++){
                unsigned int px = (v[x]+col) % DISPLAY_WIDTH;
                uint8_t on = (sprite_row & (0x80 >> col)) > 0;
                if(!display_ram[py][px]^on){
                    v[0x0F] = 1;
                
                }
                display_ram[py][px]^=on;
            }
        }

        draw_screen();
    }


    void draw_screen(){

    }
 
};

int main(){
    chip8 chip = chip8();
    string name;
    uint8_t a, b;
    a= 2;
    b=3;
    a = a-b;
    cout << "a: " << +a << endl;
    cout << UINT_MAX;
    cout << "TESTSSS" << endl;

    return 0;
}