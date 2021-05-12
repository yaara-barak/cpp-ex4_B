#pragma once
#include <iostream>
#include <string>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{
      class Player{
         protected:
            City location;
	         std::set<City> cards;
            Board &board;
      
         public:
            Player(Board&, City);
            virtual Player& drive(City);
            virtual Player& fly_direct(City);
            virtual Player& fly_charter(City);
            virtual Player& fly_shuttle(City);
            virtual Player& build();
            virtual Player& discover_cure(Color);
            virtual Player& treat(City);
            virtual Player& take_card (City);
            virtual std::string role(); 
   };
}