#include <iostream>
#include "HASH_TABLE.cpp"
#include "HASH_TABLE.h"

int main() {
    HASH_TABLE table1(10), table2(10);
    
    int hash_nums[] = {14,32,16,18,52,20,30};
    //14,32,16,18,52,20,30

    for (int num : hash_nums) {
        table1.quadratic(num);
    }
    std::cout<<"-- Quadratic Strategy applied to hash table ---"<<std::endl;
    table1.disp_tab();

    for (int num : hash_nums) {
        table2.chain(num);
    }
    std::cout<<"--Chain Strategy applied to hash table ---"<<std::endl;
    table2.disp_tab();

    return 0;
}