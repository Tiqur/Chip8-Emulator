#include "iostream"


class CPU
{
  public:
    unsigned char MEMORY[4096]; // Memory ( holds a total of 4096 bytes )
    unsigned char STACK[16];    // Stack ( holds 16 bytes )
    unsigned char V[16];        // Registers ( holds one byte each )
    unsigned char PC;           // Program counter
    unsigned char DT;           // 8-bit delay timer
    unsigned char ST;           // 8-bit sound timer
    unsigned short I;           // 16-bit Index register ( indexes the stack )
    bool DISPLAY[2048];         // Represents pixels ( on / off )
};


int main()
{
  return 0;
}
