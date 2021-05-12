#include "Medic.hpp"

using namespace std;

namespace pandemic
{

    Medic::Medic(Board& b, City c) : Player(b, c) {
        if(board.is_cure.at(Board::color.at(location))){
            board.disease_level.at(c)=0; 
        }
    }
    
    Medic &Medic::treat(City c) { 
        if (board.disease_level.at(c)==0){
            throw invalid_argument{"alredy cured"};
        }
        if (c != location){
            throw invalid_argument{"not your location! cannot treat"};
        }
        board.disease_level.at(c)=0;   
        return *this;
    }

    Medic &Medic::drive(City c)
    {
        Player::drive(c);
        if(board.is_cure.at(Board::color.at(location))){
            board.disease_level.at(c)=0; 
        }
        return *this;
    }
    
    Medic &Medic::fly_direct(City c)
    {
        Player::fly_direct(c);
        if(board.is_cure.at(Board::color.at(location))){
            board.disease_level.at(c)=0; 
        }
        return *this;
    }
    Medic &Medic::fly_charter(City c)
    {
        Player::fly_charter(c);
        if(board.is_cure.at(Board::color.at(location))){
            board.disease_level.at(c)=0;
        } 
        return *this;
    }
    Medic &Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);
        if(board.is_cure.at(Board::color.at(location))){
            board.disease_level.at(c)=0; 
        }
        return *this;
    }

    string Medic::role(){
        return "Medic";
    }
}