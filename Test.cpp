/**
 * Tests for pandemic-a
 *
 * AUTHOR: Yuval Moshe
 * 
 * Date: 2021-05
 */

#include "doctest.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace pandemic;

map<string, vector<string>> &initliaze_city_map()
{
    ifstream units_file{"cities_map.txt"};
    map<string, vector<string>> *con_cities = new map<string, vector<string>>;
    string line;
    while (getline(units_file, line))
    {
        vector<string> *result = new vector<string>;
        istringstream is(line);
        for (string word; is >> word;)
        {
            result->push_back(word);
        }
        con_cities->insert({result->front(), *result});
    }

    return *con_cities;
}

map<string, City> &map_str_to_enum()
{
    map<string, City> *str_enum_map = new map<string, City>;
    str_enum_map->insert({"Algiers ", City::Algiers});
    str_enum_map->insert({"Atlanta", City::Atlanta});
    str_enum_map->insert({"Baghdad ", City::Baghdad});
    str_enum_map->insert({"Bangkok ", City::Bangkok});
    str_enum_map->insert({"Beijing", City::Beijing});
    str_enum_map->insert({"Bogota", City::Bogota});
    str_enum_map->insert({"BuenosAires", City::BuenosAires});
    str_enum_map->insert({"Cairo", City::Cairo});
    str_enum_map->insert({"Chennai", City::Chennai});
    str_enum_map->insert({"Chicago", City::Chicago});
    str_enum_map->insert({"Delhi", City::Delhi});
    str_enum_map->insert({"Essen", City::Essen});
    str_enum_map->insert({"HoChiMinhCity", City::HoChiMinhCity});
    str_enum_map->insert({"HongKong", City::HongKong});
    str_enum_map->insert({"Istanbul", City::Istanbul});
    str_enum_map->insert({"Jakarta", City::Jakarta});
    str_enum_map->insert({"Johannesburg", City::Johannesburg});
    str_enum_map->insert({"Karachi", City::Karachi});
    str_enum_map->insert({"Khartoum", City::Khartoum});
    str_enum_map->insert({"Kinshasa", City::Kinshasa});
    str_enum_map->insert({"Kolkata", City::Kolkata});
    str_enum_map->insert({"Lagos", City::Lagos});
    str_enum_map->insert({"Lima", City::Lima});
    str_enum_map->insert({"London", City::London});
    str_enum_map->insert({"LosAngeles", City::LosAngeles});
    str_enum_map->insert({"Madrid", City::Madrid});
    str_enum_map->insert({"Manila", City::Manila});
    str_enum_map->insert({"MexicoCity", City::MexicoCity});
    str_enum_map->insert({"Miami", City::Miami});
    str_enum_map->insert({"Milan", City::Milan});
    str_enum_map->insert({"Montreal", City::Montreal});
    str_enum_map->insert({"Moscow", City::Moscow});
    str_enum_map->insert({"Mumbai", City::Mumbai});
    str_enum_map->insert({"NewYork", City::NewYork});
    str_enum_map->insert({"Osaka", City::Osaka});
    str_enum_map->insert({"Paris", City::Paris});
    str_enum_map->insert({"Riyadh", City::Riyadh});
    str_enum_map->insert({"SanFrancisco", City::SanFrancisco});
    str_enum_map->insert({"Santiago", City::Santiago});
    str_enum_map->insert({"SaoPaulo", City::SaoPaulo});
    str_enum_map->insert({"Seoul", City::Seoul});
    str_enum_map->insert({"Shanghai", City::Shanghai});
    str_enum_map->insert({"StPetersburg", City::StPetersburg});
    str_enum_map->insert({"Sydney", City::Sydney});
    str_enum_map->insert({"Taipei", City::Taipei});
    str_enum_map->insert({"Tehran", City::Tehran});
    str_enum_map->insert({"Tokyo", City::Tokyo});
    str_enum_map->insert({"Washington", City::Washington});
    return *str_enum_map;
}

TEST_CASE("Good Case")
{
    Board board;
    OperationsExpert oe{board, City::London};
    CHECK_EQ(board[City::London], 0);
    CHECK_THROWS(oe.treat(City::London));
    board[City::London] = 2;
    CHECK_EQ(board[City::London], 2);
    CHECK_NOTHROW(oe.drive(City::NewYork));
    CHECK_NOTHROW(oe.drive(City::Montreal));
    CHECK_NOTHROW(oe.drive(City::Chicago));
    CHECK_NOTHROW(oe.drive(City::SanFrancisco));
    CHECK_NOTHROW(oe.drive(City::LosAngeles));
    CHECK_NOTHROW(oe.drive(City::MexicoCity));
    CHECK_NOTHROW(oe.drive(City::Lima));
    CHECK_NOTHROW(oe.drive(City::Bogota));
    CHECK_NOTHROW(oe.drive(City::BuenosAires));
    CHECK_NOTHROW(oe.drive(City::SaoPaulo));
    CHECK_NOTHROW(oe.drive(City::Lagos));
    CHECK_NOTHROW(oe.drive(City::Kinshasa));
    CHECK_NOTHROW(oe.drive(City::Johannesburg));
    CHECK_NOTHROW(oe.drive(City::Khartoum));
    CHECK_NOTHROW(oe.drive(City::Cairo));
    CHECK_NOTHROW(oe.drive(City::Riyadh));
    CHECK_NOTHROW(oe.drive(City::Karachi));
    CHECK_NOTHROW(oe.drive(City::Mumbai));
    CHECK_NOTHROW(oe.drive(City::Chennai));
    CHECK_NOTHROW(oe.drive(City::Jakarta));
    CHECK_NOTHROW(oe.drive(City::Sydney));
    CHECK_NOTHROW(oe.drive(City::Manila));
    CHECK_NOTHROW(oe.drive(City::Taipei));
    CHECK_NOTHROW(oe.drive(City::Osaka));
    CHECK_NOTHROW(oe.drive(City::Tokyo));
    CHECK_NOTHROW(oe.drive(City::Seoul));
    CHECK_NOTHROW(oe.drive(City::Beijing));
    CHECK_NOTHROW(oe.drive(City::Shanghai));
    CHECK_NOTHROW(oe.drive(City::HongKong));
    CHECK_NOTHROW(oe.drive(City::Kolkata));
    CHECK_NOTHROW(oe.drive(City::Delhi));
    CHECK_NOTHROW(oe.drive(City::Tehran));
    CHECK_NOTHROW(oe.drive(City::Moscow));
    CHECK_NOTHROW(oe.drive(City::StPetersburg));
    CHECK_NOTHROW(oe.drive(City::Essen));
    CHECK_NOTHROW(oe.drive(City::London));
    CHECK_NOTHROW(oe.build());
    Scientist sc{board, City::London, 1};
    sc.take_card(City::Essen);
    CHECK_NOTHROW(sc.discover_cure(Color::Blue));
    CHECK_EQ(board[City::London], 2);
    CHECK_NOTHROW(sc.treat(City::London));
    CHECK_EQ(board[City::London], 0);
    
}
TEST_CASE("Drive to a non-connected city")
{
    /** For each city (A) extract A's neighbors and then for each non-neighbor city of A, 
    check if driving to it throws an exception. **/
    Board board;
    map<string, City> city_enum = map_str_to_enum();
    map<string, vector<string>> cites_map = initliaze_city_map();
    for (map<string, vector<string>>::iterator it = cites_map.begin(); it != cites_map.end(); it++)
    {
        OperationsExpert OE(board, city_enum.find(it->first)->second);
        vector<string> curr_city_nei(it->second.begin() + 2, it->second.end());
        for (map<string, City>::iterator it_v = city_enum.begin(); it_v != city_enum.end(); it_v++)
        {
            if (find(curr_city_nei.begin(), curr_city_nei.end(), it_v->first) == curr_city_nei.end())
            {
                CHECK_THROWS(OE.drive(it_v->second));
            }
        }
    }
}

TEST_CASE("Treat cities with no disease (Level = 0)")
{
    Board board;
    map<string, City> city_enum = map_str_to_enum();
    for (map<string, City>::iterator it = city_enum.begin(); it != city_enum.end(); it++)
    {
        FieldDoctor FD(board, it->second);
        CHECK_THROWS(FD.treat(it->second));
    }
}
TEST_CASE("Test Uniqe Actions")
{
    Board board;
    map<string, vector<string>> cites_map = initliaze_city_map();
    map<string, City> city_enum = map_str_to_enum();

    OperationsExpert OE(board, City::Washington);
    FieldDoctor FD(board, City::Washington);
    Virologist VI(board, City::Washington);
    Medic MD(board, City::Washington);
    Dispatcher DI(board, City::Washington);
    GeneSplicer GE(board, City::Washington);
    Researcher RE(board, City::Washington);
    Scientist SC(board, City::Washington, 4);

    // Check OperationsExpert:
    for (map<string, City>::iterator it_v = city_enum.begin(); it_v != city_enum.end(); it_v++)
    {
        OperationsExpert OE(board, it_v->second);
        FieldDoctor FD(board, it_v->second);
        Virologist VI(board, it_v->second);
        Medic MD(board, it_v->second);
        Dispatcher DI(board, it_v->second);
        GeneSplicer GE(board, it_v->second);
        Researcher RE(board, it_v->second);
        Scientist SC(board, it_v->second, 4);
        CHECK_NOTHROW(OE.build());
        CHECK_THROWS(FD.build());
        CHECK_THROWS(VI.build());
        CHECK_THROWS(MD.build());
        CHECK_THROWS(DI.build());
        CHECK_THROWS(GE.build());
        CHECK_THROWS(RE.build());
        CHECK_THROWS(SC.build());
    }

    // Check FieldDoctor:
    for (map<string, vector<string>>::iterator it = cites_map.begin(); it != cites_map.end(); it++)
    {
        for (vector<string>::iterator it_v = it->second.begin() + 2; it_v != it->second.end(); it_v++)
        {
            board[city_enum.find(*it_v)->second] = 2;
            CHECK_NOTHROW(FD.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(OE.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(VI.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(MD.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(DI.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(GE.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(RE.treat(city_enum.find(*it_v)->second));
            CHECK_THROWS(SC.treat(city_enum.find(*it_v)->second));
        }
    }

    
}