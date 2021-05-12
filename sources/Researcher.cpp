#include "Researcher.hpp"

using namespace std;

const int cards_sum = 5;

namespace pandemic
{

    Researcher::Researcher(Board& b, City c) : Player(b, c) {}

    Researcher &Researcher::discover_cure(Color c) {
        if(board.is_cure.at(c)){
            return *this;
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
        board.is_cure.at(c)=true;
        return *this;
    }

    string Researcher::role(){
        return "Researcher";
    }

}