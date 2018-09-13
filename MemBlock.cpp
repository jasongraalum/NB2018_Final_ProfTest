// Copyright (c) 2018 Jason Graalum
//
// 
// MemBlock.cpp
//
// Memory Block Class implementation for New Beginnings Final Proficiency Exam
//

#include "MemBlock.hpp"
#include <iostream>
#include <iomanip>

// Default constructor
MemBlock::MemBlock() {
    start_addr = 0;
    size = 0;
    next = NULL;
}
// Constructor that takes the start address for the block and the size
MemBlock::MemBlock(unsigned int s_addr, unsigned int block_size) {
    start_addr = s_addr;
    size = block_size;
    next = NULL;
}

// Getter and Setter methods for next pointer
MemBlock * MemBlock::getNext() {
    return next;
}
void MemBlock::setNext(MemBlock * n) {
    this->next = n;
}

// Return the size of the current memory block
unsigned int MemBlock::getSize() {
    return size;
}

// Return the size of the current memory block
void MemBlock::setSize(unsigned int s) {
    size = s;
}

// Return the size of the current memory block
unsigned int MemBlock::getAddr() {
    return start_addr;
}

// Return the size of the current memory block
void MemBlock::setAddr(unsigned int addr) {
    start_addr = addr;
}


// Print MemBlock Information Header
void MemBlock::printBlockInfoHeader()
{
    std::cout << std::setw(12) << " Block |";
    std::cout << std::setw(12) << " StartAddr |";
    std::cout << std::setw(12) << " EndAddr |";
    std::cout << std::setw(12) << " Size ";
    std::cout << std::endl;

    std::cout << "-----------|";
    std::cout << "-----------|";
    std::cout << "-----------|";
    std::cout << "-----------";
    std::cout << std::endl;
}
// Print MemBlock Information
void MemBlock::printBlockInfo(int index) 
{
    std::cout << std::setw(12) << index;
    std::cout << std::setw(12) << start_addr;
    std::cout << std::setw(12) << start_addr + size;
    std::cout << std::setw(12) << size;
    std::cout << std::endl;
}
