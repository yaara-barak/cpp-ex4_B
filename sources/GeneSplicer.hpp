#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        GeneSplicer(Board&, City);
        GeneSplicer &discover_cure(Color) override;
        std::string role() override;

    };
}

