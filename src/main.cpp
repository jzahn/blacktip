#include "blacktipexp.hpp"

int main(int argc, char **argv)
{
	char const *algorithmName;
	if (argc > 1)
        algorithmName = argv[1];
	else
        algorithmName = "";

	blacktipexp::Blacktip blacktip(algorithmName);
	blacktip.loop();
}
