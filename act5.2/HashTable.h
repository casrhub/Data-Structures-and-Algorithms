
#pragma once
#include <list>
#include <vector>
#include <string>

class Ht{
    private:
    std::vector<std::list<std::pair<std::string, int>>> table;// vector de listas, cada lista interna tinene key value
    int hash(std::string key);
    int prime;

    public:
    Ht();
    int salary(std::string jobDescription);
    void insert (std::string key,int value);
    
};

