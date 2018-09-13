// Copyright (c) 2018 Jason Graalum
//
// 
// MemBlock.hpp
//
// Memory Block Class interface for New Beginnings Final Proficiency Exam
//

#ifndef _MEMBLOCK_HPP_
#define _MEMBLOCK_HPP_

class MemBlock {
    public:
        // Default Constructor - sets start_addr to 0 and size to 0 
        MemBlock();

        // Constructor that takes the start address for the block and the size
        MemBlock(unsigned int, unsigned int);

        // Getter and Setter methods for next pointer
        MemBlock * getNext();
        void setNext(MemBlock *);

        // Return the size of the current memory block
        unsigned int getSize();

        // Set the size of the current memory block
        void setSize(unsigned int);

        // Return the start address of the current memory block
        unsigned int getAddr();

        // Set the start address of the current memory block
        void setAddr(unsigned int);

        // Print MemBlock Information Header
        void printBlockInfoHeader();

        // Print MemBlock Information
        void printBlockInfo(int index); 

    private:
        unsigned int start_addr;
        unsigned int size;
        MemBlock * next;
};



#endif

