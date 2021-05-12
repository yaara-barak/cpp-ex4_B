#include "GeneSplicer.hpp"

using namespace std;

const int cards_sum = 5;

namespace pandemic
{

    GeneSplicer::GeneSplicer(Board& b, City c) : Player(b, c) {}
    
    GeneSplicer &GeneSplicer::discover_cure(Color c) { 
        
        if(!board.is_cure.at(c)){
        
            if(!board.research_station.at(location)){
                throw invalid_argument{"cannot discover cure if there is no research station in the location"};
            }
            if(cards.size() < cards_sum){
                throw invalid_argument{"you dont have 5 cards to throw"};
            }
            board.is_cure.at(c)=true;
            int mone = 1;
            for(auto iterator = cards.begin(); iterator != cards.end(); mone++){
                if(mone == cards_sum){
                     break; 
                }   
                iterator = cards.erase(iterator);
            }
        }
        return *this;
    }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }
}

