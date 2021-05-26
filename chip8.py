from array import array

class CPU(object):
    def __init__(self, opcode):
        opcode = 0
        self.memory = bytearray(4096)
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

    def emulate_cycle(self):
        # Fetch Opcode
        # Decode(lookup) Opcode
        # Exec Opcode
        # Update timers
        None

    def lookup_table(self, opcode):
        None