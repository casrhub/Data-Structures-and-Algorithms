#include <iostream>
#include "hashTable.cpp"
#include "hashTable.h"

int main() {
    HASH_TABLE table1(10), table2(10);
    
    int hash_nums[] = {5,16,14,78,52,50,36,58,10};
    //14,32,16,18,52,20,30

    for (int num : hash_nums) {
        table1.quadratic(num);
    }
    std::cout<<"--MODIFIED HASH TABLE 1 WITH QUADRATIC STRATEGY ---"<<std::endl;
    table1.disp_tab();

    for (int num : hash_nums) {
        table2.chain(num);
    }
    std::cout<<"--MODIFIED HASH TABLE 2 WITH CHAIN STRATEGY ---"<<std::endl;
    table2.disp_tab();

    return 0;
}