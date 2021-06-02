from array import array

class CHIP8(object):
    def __init__(self, data):
        opcode = 0
        self.memory = bytearray(4096)
        self.load_fonts()
        delay_timer = 0
        sound_timer = 0
        # The chip 8 has a total of 2048 pixels
        # Track whether a given pixel is on or off
        gfx = bytearray(2048)
        registers = bytearray(16)
        #Index register and program counter can
        # have values from 0x000 to 0xFFF
        index_reg = 0
        pc = 0x200
        stack = array("H")
        sp = 0
        key = bytearray(16)
        registers = bytearray(16)

    def emulate_cycle(self):
        # Fetch Opcode
        # Decode(lookup) Opcode
        # Exec Opcode
        # Update timers
        None

    def lookup_table(self, opcode):
        None

    def load_fonts(self):
        fonts = [[0xF0, 0x90, 0x90, 0x90, 0xF0],     # 0
            [0x20, 0x60, 0x20, 0x20, 0x70],     # 1
            [0xF0, 0x10, 0xF0, 0x80, 0xF0],     # 2
            [0xF0, 0x10, 0xF0, 0x10, 0xF0],     # 3
            [0x90, 0x90, 0xF0, 0x10, 0x10],     # 4
            [0xF0, 0x80, 0xF0, 0x10, 0xF0],     # 5
            [0xF0, 0x80, 0xF0, 0x90, 0xF0],     # 6
            [0xF0, 0x10, 0x20, 0x40, 0x40],     # 7
            [0xF0, 0x90, 0xF0, 0x90, 0xF0],     # 8
            [0xF0, 0x90, 0xF0, 0x10, 0x90],     # 9
            [0xF0, 0x90, 0xF0, 0x90, 0x90],     # A
            [0xE0, 0x90, 0xE0, 0x90, 0xE0],     # B
            [0xF0, 0x80, 0x80, 0x80, 0xF0],     # C
            [0xE0, 0x90, 0x90, 0x90, 0xE0],     # D
            [0xF0, 0x80, 0xF0, 0x80, 0xF0],     # E
            [0xF0, 0x80, 0xF0, 0x80, 0x80]      # F
        ]
        i = 0
        for row in fonts:
            for hex in row:
                self.memory[i] = hex
                i+=1

c = CHIP8()