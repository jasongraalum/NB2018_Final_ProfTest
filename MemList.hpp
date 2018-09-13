// Copyright (c) 2018 Jason Graalum
//
// 
// MemList.hpp
//
// Class interface of MemList for New Beginnings Final Proficiency Exam
// 2018

#ifndef _MEMALLOC_HPP_
#define _MEMALLOC_HPP_

#include "MemBlock.hpp"

class MemList {
    public:
        /////////////////////////////////////////////////////////////////////////////////
        // Level 0 Methods - These are included in the templated code
        /////////////////////////////////////////////////////////////////////////////////
        // Default constructor which creates empty lists for both the Free and Reserved
        // lists
        //
        // Level 0
        //
        MemList();

        // Display the Free List
        //
        // Level 0
        //
        void displayFree();

        // Display the Reserved List
        //
        // Level 0
        //
        void displayReserved();

        /////////////////////////////////////////////////////////////////////////////////
        // Level 1 Methods
        /////////////////////////////////////////////////////////////////////////////////
        // Parameterized constructor which create two lists of MemBlock 
        // The Free List will contain a single MemBlock with all the memory(start_addr and mem_size)
        // The Reserved List will be empty
        //
        // MemList = new MemList(start_addr, mem_size);
        //
        // Level 1
        //
        MemList(unsigned int, unsigned int);

        // Find the first MemBlock in the Free list which greater than or equal to the amount requested(via 
        // the function argument). Update the MemBlock in the Free List - change the start_addr and mem_size
        // by the amount of memory being reserved.
        // Add the newly reserved memory into a new MemBlock in the Reserved List
        // If no MemBlock in the Free List is large enough return NULL, otherwise return a pointer to 
        // the new MemBlock in the Reserved List.
        //
        // Level 1
        //
        MemBlock * reserveMemBlock(unsigned int);


        // Return the total size of all blocks in the Reserved List
        //
        // Level 1
        //
        unsigned int reservedSize();

        // Return the total size of all blocks in the Free List
        //
        // Level 1
        unsigned int freeSize();

        /////////////////////////////////////////////////////////////////////////////////
        // Level 2 Methods
        /////////////////////////////////////////////////////////////////////////////////
        // Removes the MemBlock provided(via the pointer) from the Reserved List and adds it
        // back into the Free List - it must be added back "in order of starting address".
        // If the MemBlock to be freed does exist or it a bad block(it overlaps with a block in the Free
        // list), return false.  Otherwise return true
        //
        // Level 2
        //
        bool freeMemBlock(MemBlock *);

        // Return a pointer to the MemBlcok with the largest size from the Free List
        //
        // Level 2
        //
        MemBlock * maxFree();

        // Return a pointer to the MemBlcok with the smallest size from the Free List
        //
        // Level 2
        //
        MemBlock * minFree();

        // Return the number of MemBlocks in the Free List
        //
        // Level 2
        //
        unsigned int freeBlockCount();

        /////////////////////////////////////////////////////////////////////////////////
        // Level 3 Methods
        /////////////////////////////////////////////////////////////////////////////////
        // Iterate through the Free List - combine any blocks that are adjacent
        // Return the number of MemBlocks removed
        //
        // Level 3
        //
        unsigned int defragFree();

        // Return the start address of the smallest block that fits the size requested
        // Ex:  MemList_Obj->minMax(100);  // Return the address of the smallest block 
        //                                    that is greater than 100
        // The return values are the same as in the "reserveMemBlock" member function.
        //
        // Level 3
        //
        MemBlock * reserveMinMemBlock(unsigned int);

    private:
        // Pointer to the first block in the memory list
        MemBlock * free_head;
        MemBlock * reserved_head;

        // Define the starting address of the memory and total size
        // available in this list when it is created.
        unsigned int mem_start_addr;
        unsigned int mem_size;
};

#endif
