
#pragma once
#include <list>
#include <vector>
#include <string>

class Ht{
    private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    int hash(std::string key);
    int prime;

    public:
    Ht();
    int salary(std::string jobDescription);
    void insert (std::string key,int value);
    
};

