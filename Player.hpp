#pragma once
#include <string>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic
{
    class Player
    {
    public:
        Player &drive(City city);
        Player &fly_direct(City City);
        Player &fly_shuttle(City City);
        Player &fly_charter(City City);
        Player &build();
        Player &discover_cure(Color color);
        Player &treat(City city);
        string role();
        Player &take_card(City city);
    };
}