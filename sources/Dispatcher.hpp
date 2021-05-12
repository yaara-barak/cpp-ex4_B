#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board&, City);
        Dispatcher &fly_direct(City) override;
        std::string role() override;
    };
}