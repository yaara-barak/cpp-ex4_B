#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor(Board&, City);
        FieldDoctor &treat(City) override;
        std::string role() override;

    };
}