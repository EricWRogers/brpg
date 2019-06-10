#include "console.hpp"
#include "debug.hpp"
#include <iostream>

void MessageForPlayer(std::string messageToDisplay, std::string possibleChoices[])
{
    bool loopControl = true;
    std::string response = "";

    while(loopControl)
    {
        std::cout << "" << std::endl;
        std::cout << messageToDisplay << std::endl;

        //for(int i = 0; i < std::size(*possibleChoices); i++)
        //{
        //    std::cout << i + ": " + possibleChoices[i] << std::endl;
        //}

        std::cin >> response;
    }
}