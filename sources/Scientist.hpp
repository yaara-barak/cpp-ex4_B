#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int n;

    public:
        Scientist(Board&, City, int);
        Scientist &discover_cure(Color) override;
        std::string role() override;

    };
}