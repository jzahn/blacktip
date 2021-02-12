#include "blacktipexp.hpp"

int main(int argc, char **argv)
{
	char const *algorithimName;
	if (argc > 1)
		algorithimName = argv[1];
	else
		algorithimName = "";

	blacktipexp::Blacktip blacktip(algorithimName);
	blacktip.loop();
}
