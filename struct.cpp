#include <iostream>

using namespace std;

//  memory and structs

void main(){
uint8_t getValue() {
    return 0xAB;
}

// storing and manipulating  i uint64_t
uint64_t extended_value = getValue();
// individual bytes
uint8_t byte = (extended_value >> 8) & 0xFF;

/*
The return value is 0xAB(10101011). Since getValue() returns a uint8_t, it represents an 8-bit value.
extendedValue is a uint64_t variable, meaning it has 64 bits. Initially, all bits are zero.
After assignment, extendedValue holds the 0xAB value in its least significant byte (8 bits), while the rest of
the bits remain zero: 00000000 00000000 00000000 00000000 00000000 00000000 00000000
10101011.
The right shift operator >> 8 shifts extendedValue 8 bits to the right, resulting in all zeroes in the least
significant byte (the original 0xAB is shifted out): 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000.
The bitwise AND with 0xFF (which is 11111111 in binary) isolates the least significant byte. Since this byte
is all zeroes, byte1 becomes 00000000 in binary, or 0x00 in hexadecimal.
*/

uint64_t big_value = 0x1122334455667788;
uint8_t byte_array[8];                                             //  11111111.

for (int i = 0; i < 8; i++){
    byte_array[i] = (big_value >> (i * 8)) & 0xFF;
}

// type casting for memory efficiency

uint64_t large_numbers[5] = {1, 2 ,3 ,4, 5}; 
uint8_t small_numbers[5];
for (int i = 0; i < 5; i++){
    small_numbers[i] = static_cast<uint8_t>(large_numbers[i])
}

// bit manipulation for control operations


uint8_t control_register = 0b00001111;  // 0b00001111 -> 0000100000 -> 111011111
// 6th bit
control_register |= (1 << 5);
// clearing 3rd bit
control_register &= ~(1 << 2) // 

// combining multiple uint8_t values into a uint32_t
uint8_t sensor1 = 0x12;
uint8_t sensor2 = 0x34;
uint8_t sensor3 = 0x56;
uint8_t sensor4 = 0x78;

uint32_t combinedSensors = (static_cast<uint32_t>(sensor1) << 24) |
                           (static_cast<uint32_t>(sensor2) << 16) |
                           (static_cast<uint32_t>(sensor3) << 8)  |
                           (static_cast<uint32_t>(sensor3));          01111111 00000000 .... 

// signed to unsigned casting and vice versa
int32_t signed_value = -1234;
uint32_t unsigned_value = static_cast<uint32_t>(signed_value);
int32_t signed_again = static_cast<int32_t>(unsigned_value);


// bitwise operations for flag handling
uint8_t flag = 0b00000000;
// flag pos 2
flag |= (1 << 2);  // -> 0b00000100 | 0b00000000 -> 0b00000100
// checking pos at 4
bool is_set = flag & (1 << 4); // 0b0010000 & 0b00000100 -> 0b00000000 -> had this been 0b00010000 & 0b0010000
// clear flag at pos 2
flags &= ~(1 << 2) //flags = 00000100 & (negation = 11111011) -> flags = 00000100
}

