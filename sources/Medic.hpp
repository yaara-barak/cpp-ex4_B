#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board&, City);
        Medic &treat(City) override;
        std::string role() override;
        Medic &drive(City) override;
        Medic &fly_direct(City) override;
        Medic &fly_charter(City) override;
        Medic &fly_shuttle(City) override;

    };
}