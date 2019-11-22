#include "blacktipexp.h"

int main(int argc, char **argv)
{
	char const *algorithimName = 0;
	if (argc > 1)
		algorithimName = argv[1];
	else
		algorithimName = "";

	blacktipexp::Blacktip blacktip(algorithimName);
	blacktip.loop();
}