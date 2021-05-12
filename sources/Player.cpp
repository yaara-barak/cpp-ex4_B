
#include "Player.hpp"

using namespace std;
const int cards_sum = 5;

namespace pandemic {
    Player::Player(Board &b, City c) : board(b), location(c) {

    }

    Player& Player::drive(City c){
        if(!Board::connected_cities.at(location).contains(c)){
            throw invalid_argument{"cannot drive to not neighbor city"};
            //throw invalid_argument{"cannot move from" + location + "to " + c};
        }
        location=c;
        return *this;
    }

    Player& Player::fly_direct(City c){
        if(!cards.contains(c)){
            throw invalid_argument{"you do not have the card of the city you want to fly"};
        }
        cards.erase(c);
        location = c;
        return *this;   
    }
     Player& Player::fly_charter(City c){
        if(!cards.contains(location)){
            throw invalid_argument{"you do not have the card of the city you want to fly"};
        }
        cards.erase(location);
        location = c;
        return *this;   
    }
    Player& Player::fly_shuttle(City c){
        if(c==location){
            throw invalid_argument{"cant fly to your location"};
        }
        if(!board.research_station.at(location)){
            throw invalid_argument{"you dont have a research station in your location"};
        }
        if(!board.research_station.at(c)){
            throw invalid_argument{"dest city dont have a research station"};
        }
        location = c;
        return *this;
    }
    Player& Player::build(){
        if(!cards.contains(location)){
            throw invalid_argument{"cannot build research station if the player dont have a card of the city"};
        }
        if(board.research_station.at(location)){
             return *this;
        }
        board.research_station.at(location)= true;
        cards.erase(location);
        return *this;
    }
    Player& Player::discover_cure(Color c){
        if(!board.is_cure.at(c)){    
            if(!board.research_station.at(location)){
                throw invalid_argument{"cannot discover cure if there is no research station in the location"};
            }
            int mone = 0;
            for(const auto& card : cards){
                if(Board::color.at(card) == c){
                    mone++;
                }
            }
            if(mone < cards_sum){
                throw invalid_argument{"you dont have 5 cards with the correct color"};
            }
            board.is_cure.at(c)=true;
            mone=1;
            for(auto iterator = cards.begin(); iterator != cards.end(); mone++){
                if(mone == cards_sum) {
                    break; 
                }
                if(Board::color.at(*iterator) == c) {
                    iterator = cards.erase(iterator);
                }
                else {
                    ++iterator;
                }
            }
        }
        return *this;
	}
    
    Player& Player::treat(City c){
        if (c != location){
            throw invalid_argument{"not your location! cannot treat"};
        }
        if (board.disease_level.at(c)==0){
            throw invalid_argument{"alredy cured"};
        }
        if(board.is_cure.at(Board::color.at(c))){
                board.disease_level.at(c)=0;
        }
        else{
            board.disease_level.at(c)--;
        }
        return *this;
    }

    Player& Player::take_card(City c){
        cards.insert(c);
        return *this;
    }
    string Player::role(){
		return "basic player";
	}

}