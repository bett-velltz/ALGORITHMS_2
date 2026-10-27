//
// Created by 1 on 10.10.2026.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

int main() {

    std::unordered_map<std::string, int> mp;
    std::ifstream f_in("incrementator.in");
    std::ofstream f_out("incrementator.out");

    std::string line;

    while(std::getline(f_in, line)) {
        std::istringstream iss(line);
        std::string name;
        int numb;
        iss >> name >> numb;
        mp[name] += numb;
        f_out << mp[name] << '\n';
    }

    return 0;
}