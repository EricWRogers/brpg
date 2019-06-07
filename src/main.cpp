#include <stdio.h>

#include "debug.hpp"
#include "console.hpp"

int main( int argc, const char* argv[] )
{
	Log( "Hello RPG" );

	std::string possibleChoices[] = {"1", "2", "3"};
	MessageForPlayer("Testing Qestion", possibleChoices);
}
