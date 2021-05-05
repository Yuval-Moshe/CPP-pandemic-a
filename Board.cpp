#include <ostream>
using namespace std;

#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    int& Board::operator[](City city){
        int* arr = new int [5];
        return *arr;}
    bool Board::is_clean(){return true;}
    ostream &operator<<(ostream &output, Board &board){return output;}
    Board& Board::remove_cures(){return *this;};
}