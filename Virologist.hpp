#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
using namespace pandemic;

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        Virologist(Board &board, City city){};
    };
}