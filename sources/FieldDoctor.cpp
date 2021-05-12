#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{

    FieldDoctor::FieldDoctor(Board& b, City c) : Player(b, c) {}
    
    FieldDoctor &FieldDoctor::treat(City c) { 
        if (c != location && !Board::connected_cities.at(location).contains(c)){
            throw invalid_argument{"not your location or not neigbor city- cannot treat"};
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

    string FieldDoctor::role(){
        return "FieldDoctor";
    }
}