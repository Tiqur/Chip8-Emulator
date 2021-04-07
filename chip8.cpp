#include "iostream"
#include "cstring"
#include "random"


// Fontset
unsigned char fontset[80] =
{ 
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

unsigned char randomByte()
{
  std::random_device RD;
  std::mt19937 gen(RD());
  std::uniform_int_distribution<> distr(0, 255U);

  return distr(gen);
}

class CPU
{
  public:
    unsigned char MEMORY[4096]; // Memory ( holds a total of 4096 bytes )
    unsigned char STACK[16];    // Stack ( holds 16 bytes )
    unsigned char V[16];        // Registers ( holds one byte each )
    unsigned char DT;           // 8-bit delay timer
    unsigned char ST;           // 8-bit sound timer
    unsigned short I;           // 16-bit Index register ( indexes the stack )
    unsigned short PC;          // 16-bit Program counter ( Points to the current instruction address )
    bool DISPLAY[2048];         // Represents pixels ( on / off )

    void initialize()
    {
      
      // Reset Values
      this->PC = 0x200;
      this->DT = 0;
      this->ST = 0;
      this->I  = 0;

      // Clear memory
      memset(MEMORY, 0, sizeof(MEMORY));

      // Clear Stack
      memset(STACK, 0, sizeof(STACK));

      // Clear Display
      memset(DISPLAY, 0, sizeof(DISPLAY));

      // Clear Registers
      memset(V, 0, sizeof(V));

      // Load fontset into memory
      for (int i = 0; i < 80; i++)
        this->MEMORY[i+0x50] = fontset[i];
    }
};


int main()
{
  CPU cpu;
  
  // Initialize values
  cpu.initialize();

  // Emulate loop
  while (1)
  {
    break;
  }

  return 0;
}
