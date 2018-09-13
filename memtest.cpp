// Copyright (c) 2018 Jason Graalum
//
// 
// memtest.cpp
//
// Test main function for New Beginnings Final Proficiency Exame
// 2018

#include <iostream>
#include <cstring>
#include "MemList.hpp"

void memtest0();
void memtest1();
void memtest2();
void memtest3();

int main(int argc, char * argv[])
{
    for(int i = 1; i < argc; i++) {
        if(!strcmp(argv[i],"0")) memtest0();
        if(!strcmp(argv[i],"1")) memtest1();
        if(!strcmp(argv[i],"2")) memtest2();
        if(!strcmp(argv[i],"3")) memtest3();
    }

}
void passTestMsg(MemList * mem) {
        std::cout << "**** TEST PASSED ****" << std::endl << std::endl;
        mem->displayFree();
        mem->displayReserved();
        std::cout << std::endl;
        std::cout << "******************************************" << std::endl << std::endl;
}

void failTestMsg(MemList * mem) {
        std::cout << "**** TEST FAILED ****" << std::endl << std::endl;
        mem->displayFree();
        mem->displayReserved();
        std::cout << std::endl;
        std::cout << "******************************************" << std::endl << std::endl;
}

bool checkMemSizes(MemList * mem, int f, int r) {

    unsigned int fs = mem->freeSize();
    unsigned int rs = mem->reservedSize();

    if(rs != r || fs != f) {
        std::cout << "**** TEST FAILED ****" << std::endl;
        std::cout << "Expected reserved size of " << r << "." << std::endl;
        std::cout << "Found reserved size of " << rs << "." << std::endl;
        std::cout << "Expected free size of " << f << "." << std::endl;
        std::cout << "Found free size of " << fs << "." << std::endl;
        std::cout << "******************************************" << std::endl << std::endl;
        mem->displayFree();
        mem->displayReserved();
        std::cout << std::endl;
        std::cout << "******************************************" << std::endl << std::endl;
        return false;
    }
    return true;
}

// Simple compile test
void memtest0()
{
    std::cout << "Running Level 0 Tests" << std::endl;
    MemList * mem_allocator = new MemList();
    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    std::cout << std::endl;

    std::cout << "Simple constructor and display tests all passed." << std::endl;
}

// Level 1 Tests
// a. Constructor Test
// b. 
int memtest1_1(unsigned int, unsigned int);
int memtest1_2(unsigned int, unsigned int, unsigned int);
int memtest1_3(unsigned int, unsigned int, unsigned int, int);
void memtest1()
{
    int total_count = 0;
    int passed_count = 0;
    std::cout << "Running Level 1 Tests" << std::endl;

    std::cout << "Constructor + reservedSize + freeSize test 1-1-1:" << std::endl;
    passed_count += memtest1_1(100,1000);
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 1-1-2:" << std::endl;
    passed_count += memtest1_1(0,0);
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 1-2-1:" << std::endl;
    passed_count += memtest1_2(100,1000,100);
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 1-3-1:" << std::endl;
    passed_count += memtest1_3(100,1000,100,4);
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 1-3-2:" << std::endl;
    passed_count += memtest1_3(100,1000,300,4);
    total_count++;


    std::cout << "******" << std::endl;
    std::cout << passed_count << " tests of " << total_count << " passed." << std::endl;
    std::cout << "******" << std::endl;
}

int memtest1_1(unsigned int s_addr, unsigned int mem_size) {

    std::cout << "Creating Memory List starting at: " << s_addr << " of size: " << mem_size << std::endl;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    if(!checkMemSizes(mem_allocator,mem_size, 0))
    {
        delete mem_allocator;
        return 0;
    }
    else {
        passTestMsg(mem_allocator);
        delete mem_allocator;
        return 1;
    }

}

int memtest1_2(unsigned int s_addr, unsigned int mem_size, unsigned int size_to_res) {

    std::cout << "Creating Memory List starting at: " << s_addr << " of size: " << mem_size << std::endl;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving memory of size: " << size_to_res << std::endl;
    mem_allocator->reserveMemBlock(size_to_res);
    
    if(!checkMemSizes(mem_allocator, mem_size - size_to_res, size_to_res)) {
        delete mem_allocator;
        return 0;
    }
    else {
        passTestMsg(mem_allocator);
        delete mem_allocator;
        return 1;
    }
}

int memtest1_3(unsigned int s_addr, unsigned int mem_size, unsigned int size_to_res, int mult) {

    std::cout << "Creating Memory List starting at: " << s_addr << " of size: " << mem_size << std::endl;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    unsigned int res_size_final = 0;
    for(int i = 0; i < mult; i++) {
        std::cout << "Reserving memory of size: " << size_to_res << std::endl;
        if(mem_allocator->reserveMemBlock(size_to_res)){
            res_size_final += size_to_res;
        }
        else {
            std::cout << "\tFree memory exceeded." << std::endl;
        }
    }
    unsigned int free_size_final = mem_size - res_size_final;

    unsigned int res_size = mem_allocator->reservedSize();
    unsigned int free_size = mem_allocator->freeSize();

    if(!checkMemSizes(mem_allocator, free_size_final, res_size_final)) {
        delete mem_allocator;
        return 0;
    }
    else {
        passTestMsg(mem_allocator);
        delete mem_allocator;
        return 1;
    }
}
int memtest2_1();
int memtest2_2();
int memtest2_3();
void memtest2()
{
    int passed_count = 0;
    int total_count = 0;
    std::cout << "Running Level 2 Tests" << std::endl;

    std::cout << "Constructor + reservedSize + freeSize test 2-1:" << std::endl;
    passed_count += memtest2_1();
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 2-2:" << std::endl;
    passed_count += memtest2_2();
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 2-3:" << std::endl;
    passed_count += memtest2_3();
    total_count++;

    std::cout << "******" << std::endl;
    std::cout << passed_count << " tests of " << total_count << " passed." << std::endl;
    std::cout << "******" << std::endl;

}
int memtest2_1() {

    int s_addr = 0;
    int mem_size = 1000;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving blocks of size 100, 200, 50 and 75." << std::endl;
    MemBlock * b0 = mem_allocator->reserveMemBlock(100);
    MemBlock * b1 = mem_allocator->reserveMemBlock(200);
    MemBlock * b2 = mem_allocator->reserveMemBlock(50);
    MemBlock * b3 = mem_allocator->reserveMemBlock(75);

    if(!checkMemSizes(mem_allocator,575,425))
    {
        delete mem_allocator;
        return 0;
    }

    std::cout << "Freeing block of size 200." << std::endl;
    mem_allocator->freeMemBlock(b1);

    if(!checkMemSizes(mem_allocator,775,225))
    {
        delete mem_allocator;
        return 0;
    }

    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    delete mem_allocator;
    return 1;
}
int memtest2_2() {

    int s_addr = 0;
    int mem_size = 1000;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving blocks of size 100, 200, 50 and 75." << std::endl;
    MemBlock * b0 = mem_allocator->reserveMemBlock(100);
    MemBlock * b1 = mem_allocator->reserveMemBlock(200);
    MemBlock * b2 = mem_allocator->reserveMemBlock(50);
    MemBlock * b3 = mem_allocator->reserveMemBlock(75);
    MemBlock * b4 = mem_allocator->reserveMemBlock(100);
    MemBlock * b5 = mem_allocator->reserveMemBlock(200);
    MemBlock * b6 = mem_allocator->reserveMemBlock(50);
    MemBlock * b7 = mem_allocator->reserveMemBlock(75);

    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,150,850))
    {
        delete mem_allocator;
        return 0;
    }

    std::cout << "Freeing block of size 200." << std::endl;
    mem_allocator->freeMemBlock(b1);
    std::cout << "Freeing block of size 50." << std::endl;
    mem_allocator->freeMemBlock(b6);

    if(!checkMemSizes(mem_allocator,400,600))
    {
        delete mem_allocator;
        return 0;
    }

    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    delete mem_allocator;
    return 1;
}

int memtest2_3() {

    int s_addr = 0;
    int mem_size = 1000;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving blocks of size 100, 200, 50 and 75." << std::endl;
    MemBlock * b0 = mem_allocator->reserveMemBlock(100);
    MemBlock * b1 = mem_allocator->reserveMemBlock(200);
    MemBlock * b2 = mem_allocator->reserveMemBlock(50);
    MemBlock * b3 = mem_allocator->reserveMemBlock(75);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,575,425))
    {
        delete mem_allocator;
        return 0;
    }

    std::cout << "Freeing block of size 200." << std::endl;
    mem_allocator->freeMemBlock(b1);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,775,225))
    {
        delete mem_allocator;
        return 0;
    }

    std::cout << "Reserving block of size 200." << std::endl;
    b1 = mem_allocator->reserveMemBlock(200);

    if(!checkMemSizes(mem_allocator,575,425))
    {
        delete mem_allocator;
        return 0;
    }

    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    delete mem_allocator;
    return 1;
}

int memtest3_1();
int memtest3_2();
//int memtest3_3();
void memtest3()
{
    int passed_count = 0;
    int total_count = 0;
    std::cout << "Constructor + reservedSize + freeSize test 3-1:" << std::endl;
    passed_count += memtest3_1();
    total_count++;

    std::cout << "Constructor + reservedSize + freeSize test 3-2:" << std::endl;
    passed_count += memtest3_2();
    total_count++;

    /*
    std::cout << "Constructor + reservedSize + freeSize test 3-3:" << std::endl;
    passed_count += memtest3_3();
    total_count++;
    */

    std::cout << "******" << std::endl;
    std::cout << passed_count << " tests of " << total_count << " passed." << std::endl;
    std::cout << "******" << std::endl;

}

int memtest3_1() {

    int s_addr = 0;
    int mem_size = 1000;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving blocks of size 100, 200, 50 and 75." << std::endl;
    MemBlock * b0 = mem_allocator->reserveMemBlock(100);
    MemBlock * b1 = mem_allocator->reserveMemBlock(200);
    MemBlock * b2 = mem_allocator->reserveMemBlock(50);
    MemBlock * b3 = mem_allocator->reserveMemBlock(75);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,575,425))
    {
        delete mem_allocator;
        return 0;
    }

    if(mem_allocator->freeBlockCount() != 1)
    {
        std::cout << "Expecting 1 Block in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }

    std::cout << "Freeing last block reserved." << std::endl;
    mem_allocator->freeMemBlock(b3);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,650,350))
    {
        delete mem_allocator;
        return 0;
    }
    if(mem_allocator->freeBlockCount() != 2)
    {
        std::cout << "Expecting 2 Block in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }
    std::cout << "Defragging Free Memory" << std::endl;
    mem_allocator->defragFree();

    if(!checkMemSizes(mem_allocator,650,350))
    {
        delete mem_allocator;
        return 0;
    }

    if(mem_allocator->freeBlockCount() != 1)
    {
        std::cout << "Expecting 1 Block in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }

    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    delete mem_allocator;
    return 1;
}
int memtest3_2() {

    int s_addr = 0;
    int mem_size = 1000;
    MemList * mem_allocator = new MemList(s_addr, mem_size);

    std::cout << "Reserving blocks of size 100, 200, 50 and 75." << std::endl;
    MemBlock * b0 = mem_allocator->reserveMemBlock(100);
    MemBlock * b1 = mem_allocator->reserveMemBlock(200);
    MemBlock * b2 = mem_allocator->reserveMemBlock(50);
    MemBlock * b3 = mem_allocator->reserveMemBlock(75);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,575,425))
    {
        delete mem_allocator;
        return 0;
    }

    if(mem_allocator->freeBlockCount() != 1)
    {
        std::cout << "Expecting 1 Block in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }

    std::cout << "Freeing first block reserved." << std::endl;
    mem_allocator->freeMemBlock(b0);
    std::cout << "Freeing last block reserved." << std::endl;
    mem_allocator->freeMemBlock(b3);
    mem_allocator->displayFree();
    mem_allocator->displayReserved();

    if(!checkMemSizes(mem_allocator,750,250))
    {
        delete mem_allocator;
        return 0;
    }
    if(mem_allocator->freeBlockCount() != 3)
    {
        std::cout << "Expecting 3 Blocks in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }
    std::cout << "Defragging Free Memory" << std::endl;
    mem_allocator->defragFree();

    if(!checkMemSizes(mem_allocator,750,250))
    {
        delete mem_allocator;
        return 0;
    }

    if(mem_allocator->freeBlockCount() != 2)
    {
        std::cout << "Expecting 2 Blocks in Free List" << std::endl;
        std::cout << "Found " << mem_allocator->freeBlockCount() << " Blocks" <<std::endl;
        failTestMsg(mem_allocator);
        delete mem_allocator;
        return 0;
    }

    mem_allocator->displayFree();
    mem_allocator->displayReserved();
    delete mem_allocator;
    return 1;
}
