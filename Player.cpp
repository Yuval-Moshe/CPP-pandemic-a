#include <string>
using namespace std;

#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic
{
    Player &Player::drive(City city) { return *this; }
    Player &Player::fly_direct(City City) { return *this; }
    Player &Player::fly_shuttle(City City) { return *this; }
    Player &Player::fly_charter(City City) { return *this; }
    Player &Player::build() {return *this; }
    Player &Player::discover_cure(Color color) { return *this; }
    Player &Player::treat(City city) { return *this; }
    string Player::role()
    {
        string ans = "";
        return ans;
    }
    Player &Player::take_card(City city) { return *this; }
}