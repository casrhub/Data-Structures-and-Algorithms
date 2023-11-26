#ifndef hashTableH
#define hashTableH 
#include <cstddef>
#include <vector>
#include <list>

class HASH_TABLE {

    std::vector<std::list<int>> table;
    int hash_tech(int key);
public:
    HASH_TABLE(int size);
    void disp_tab();
    void quadratic(int key);
    void chain(int key);
};

#endif 