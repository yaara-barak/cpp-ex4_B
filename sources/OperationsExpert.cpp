#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic{
        OperationsExpert::OperationsExpert(Board& b, City c) : Player(b, c) {}
        
        OperationsExpert& OperationsExpert::build(){
            board.research_station.at(location)=true;
            return *this;
        }

        string OperationsExpert::role(){
            return "OperationsExpert";
        }
}

