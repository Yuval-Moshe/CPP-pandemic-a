#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class Scientist : public Player
    {
    public:
        Scientist(Board &board, City city, unsigned int n){};
    };
}