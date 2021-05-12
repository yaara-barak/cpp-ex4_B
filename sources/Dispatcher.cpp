#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{

    Dispatcher::Dispatcher(Board& b, City c) : Player(b, c) {}

    Dispatcher &Dispatcher::fly_direct(City c) { 
        if (c==location){
            throw invalid_argument{"cant fly to your location"};
        }
        if(board.research_station.at(location)) {
            location = c;
        }
        else {
            Player::fly_direct(c);
        }
        return *this; 
    }

    string Dispatcher::role(){
        return "Dispatcher";
    }
}