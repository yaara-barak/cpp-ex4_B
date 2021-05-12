#include "Virologist.hpp"

using namespace std;

namespace pandemic
{

    Virologist::Virologist(Board& b, City c) : Player(b, c) {}
    
    Virologist &Virologist::treat(City c) {
        if (c != location){
            if (!cards.contains(c)){
                throw invalid_argument{"not your location! cannot treat"};
            }
            cards.erase(c);
            board.disease_level.at(c)--;
        }
        else{
            if (board.disease_level.at(c)==0){
                throw invalid_argument{"alredy cured"};
            }
            if(board.is_cure.at(Board::color.at(c))){
                board.disease_level.at(c)=0;
            }
            else{
                board.disease_level.at(c)--;
            }
        }
        return *this;
    }

    string Virologist::role(){
        return "Virologist";
    }
}