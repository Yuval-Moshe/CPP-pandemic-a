#pragma once

#include <ostream>
using namespace std;

#include "City.hpp"
using namespace pandemic;


namespace pandemic{
    class Board{
        friend ostream& operator<<(ostream& output, Board& board);
        public:
            int& operator[](City city);
            bool is_clean();
            Board& remove_cures();
    };
}