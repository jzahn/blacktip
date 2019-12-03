#include <curses.h>
#include <unistd.h>

#include <cstring>

#include "blacktipexp.h"

#include "blacktip/mix.h"
#include "blacktip/utility.h"

#define WHITE_ON_BLACK 0
#define BLACK_ON_WHITE 1

namespace blacktipexp
{
	Blacktip::Blacktip(char const *algorithimName)
		: planner(algorithimName)
	{
		initscr();
		curs_set(0);
		nodelay(stdscr, TRUE);
		noecho();
		keypad(stdscr, TRUE);
	}

	Blacktip::~Blacktip()
	{
		endwin();
	}

	void Blacktip::loop()
	{
		while (!quit)
		{
			timeMillis += 10 * timeScale;
			planner.calculate(10.0 * timeScale, depth);
			display();
			input();
			usleep(10000);
		}
	}

	void Blacktip::display()
	{
		erase();
		displayCommonInfo();
		displayCompartments();
		refresh();
	}

	void Blacktip::displayCommonInfo()
	{
		char string[15] = {};

		attron(A_REVERSE);
		attron(A_BOLD);
		waddstr(stdscr, "                                                                                ");

		wmove(stdscr, 0, 0);
		waddstr(stdscr, "Blacktip Explorer v0.3");

		attroff(A_BOLD);

		blacktip::DecoAlgorithim *algorithim = planner.getDecoAlgorithim();
		blacktip::AscentMeter &ascentMeter = planner.getAscentMeter();

		wmove(stdscr, 0, 65);
		waddstr(stdscr, "<");
		waddstr(stdscr, algorithim->getAlgorithimName().c_str());
		waddstr(stdscr, ">");

		attroff(A_REVERSE);

		wmove(stdscr, 2, 0);
		waddstr(stdscr, "time");
		sprintf(string, "%4zu", (timeMillis / 1000) / 60);
		wmove(stdscr, 2, 12);
		waddstr(stdscr, string);
		waddstr(stdscr, "m");

		sprintf(string, "%02zu", (timeMillis / 1000) % 60);
		waddstr(stdscr, string);
		waddstr(stdscr, "s");

		wmove(stdscr, 3, 0);
		waddstr(stdscr, "speed");
		sprintf(string, "%6.1f", timeScale);
		wmove(stdscr, 3, 12);
		waddstr(stdscr, string);
		waddstr(stdscr, "X");

		wmove(stdscr, 4, 0);
		waddstr(stdscr, "depth");
		sprintf(string, "%6.1f", depth);
		wmove(stdscr, 4, 12);
		waddstr(stdscr, string);
		waddstr(stdscr, "ft");

		wmove(stdscr, 5, 0);
		waddstr(stdscr, "nodeco");

		wmove(stdscr, 5, 15);
		if (algorithim->getMinutesRemaining() >= 9999.0d)
		{
			waddstr(stdscr, "----");
		}
		else
		{
			sprintf(string, "%3.0f", algorithim->getMinutesRemaining());
			waddstr(stdscr, string);
			waddstr(stdscr, "m");
		}

		wmove(stdscr, 6, 0);
		waddstr(stdscr, "ceiling");
		wmove(stdscr, 6, 15);
		sprintf(string, "%3.1f", algorithim->getCeiling());
		waddstr(stdscr, string);
		waddstr(stdscr, "ft");

		wmove(stdscr, 7, 0);
		waddstr(stdscr, "ambient");
		wmove(stdscr, 7, 15);
		sprintf(string, "%3.1f", algorithim->getFloor());
		waddstr(stdscr, string);
		waddstr(stdscr, "ft");

		wmove(stdscr, 8, 0);
		waddstr(stdscr, "saturation");
		wmove(stdscr, 8, 15);
		sprintf(string, "%3.1f", algorithim->getSaturation() * 100.0d);
		waddstr(stdscr, string);
		waddstr(stdscr, "%");

		wmove(stdscr, 9, 0);
		waddstr(stdscr, "ascent rate");
		wmove(stdscr, 9, 15);
		sprintf(string, "%3.0f", ascentMeter.getInstantaneousRate());
		waddstr(stdscr, string);
		waddstr(stdscr, "fpm");

		wmove(stdscr, 10, 0);
		waddstr(stdscr, "safety stop");
		wmove(stdscr, 10, 15);
		sprintf(string, "%s", planner.getSafetyStopRequired() ? "required" : "optional");
		waddstr(stdscr, string);

		wmove(stdscr, 11, 0);
		waddstr(stdscr, "decompression");
		wmove(stdscr, 11, 15);
		sprintf(string, "%s", planner.getDecompressionStopRequired() ? "required" : "----");
		waddstr(stdscr, string);

		wmove(stdscr, 12, 0);
		waddstr(stdscr, "dive num");
		wmove(stdscr, 12, 15);
		sprintf(string, "%d", planner.getDiveNumber());
		waddstr(stdscr, string);

		wmove(stdscr, 13, 0);
		waddstr(stdscr, "diving");
		wmove(stdscr, 13, 15);
		sprintf(string, "%s", planner.getDiveInProgress() ? "yes" : "no");
		waddstr(stdscr, string);

		wmove(stdscr, 14, 0);
		waddstr(stdscr, "repetitive");
		wmove(stdscr, 14, 15);
		sprintf(string, "%4.1f", blacktip::Utility::minutesToHours(planner.getRepetitiveDiveMinutes()));
		waddstr(stdscr, string);

		wmove(stdscr, 15, 0);
		waddstr(stdscr, "no fly");
		wmove(stdscr, 15, 15);
		sprintf(string, "%4.1f", blacktip::Utility::minutesToHours(planner.getNoFlyMinutes()));
		waddstr(stdscr, string);

		wmove(stdscr, 16, 0);
		waddstr(stdscr, "no dive");
		wmove(stdscr, 16, 15);
		sprintf(string, "%4.1f", blacktip::Utility::minutesToHours(planner.getNoDiveMinutes()));
		waddstr(stdscr, string);

		wmove(stdscr, 17, 0);
		waddstr(stdscr, "mix");
		wmove(stdscr, 17, 15);
		waddstr(stdscr, planner.getMix().getName());

		wmove(stdscr, 18, 0);
		waddstr(stdscr, "pO2");
		wmove(stdscr, 18, 15);
		sprintf(string, "%2.2f", planner.getO2Toxicity().getPO2());
		waddstr(stdscr, string);

		wmove(stdscr, 19, 0);
		waddstr(stdscr, "o2 toxicity");
		wmove(stdscr, 19, 15);
		sprintf(string, "%3.1f", planner.getO2Toxicity().getCNSToxicity() * 100);
		waddstr(stdscr, string);
		waddstr(stdscr, "%");

		wmove(stdscr, 23, 0);
		attron(A_REVERSE);
		waddstr(stdscr, "q - quit          w/s - ascend/descend    a/d - slow/speed time   r - reset time");
		wmove(stdscr, 23, 0);
        attroff(A_REVERSE);
	}

	void Blacktip::displayCompartments()
	{
		char string[15] = {};
		const int xPosition = 30;

		wmove(stdscr, 2, xPosition);
		waddstr(stdscr, "halfT");
		wmove(stdscr, 2, xPosition + 8);
		waddstr(stdscr, "pressure");
		wmove(stdscr, 2, xPosition + 20);
		waddstr(stdscr, "mVal");
		wmove(stdscr, 2, xPosition + 30);
		waddstr(stdscr, "noDeco");
		wmove(stdscr, 2, xPosition + 40);
		waddstr(stdscr, "A/c");

		wmove(stdscr, 3, xPosition);
		waddstr(stdscr, "----------------------------------------------");

		blacktip::DecoAlgorithim *algorithim = planner.getDecoAlgorithim();

		for (unsigned short i = 0; i < algorithim->getNumberOfCompartments(); i++)
		{
			const int yPosition = i + 4;

			blacktip::Compartment compartment = algorithim->getCompartment(i);

			sprintf(string, "%2.0f", compartment.getHalfTime());
			wmove(stdscr, yPosition, xPosition);
			waddstr(stdscr, string);

			sprintf(string, "%6.3f", compartment.getPressureNitrogen());
			wmove(stdscr, yPosition, xPosition + 8);
			waddstr(stdscr, string);
			if (compartment.getIsMaxed())
				waddstr(stdscr, "*");

			sprintf(string, "%6.2f", compartment.getMValue());
			wmove(stdscr, yPosition, xPosition + 18);
			waddstr(stdscr, string);

			sprintf(string, "%2.0f", compartment.getMinutesRemaining());
			wmove(stdscr, yPosition, xPosition + 30);
			waddstr(stdscr, string);

			sprintf(string, "%3.1f", compartment.getFloor());
			wmove(stdscr, yPosition, xPosition + 40);
			waddstr(stdscr, string);

			sprintf(string, "%c", '/');
			waddstr(stdscr, string);

			sprintf(string, "%3.1f", compartment.getCeiling());
			waddstr(stdscr, string);
		}
	}

	void Blacktip::input()
	{
		int ch;
		while ((ch = getch()) != ERR)
		{
			switch(ch)
			{
			case 'q':
				quit = true;
				break;

			case KEY_UP:
			case 'w':
				depth -= 0.1;
				break;

			case KEY_DOWN:
			case 's':
				depth += 0.1;
				break;

			case KEY_LEFT:
			case 'a':
				timeScale /= 10.0;
				break;

			case KEY_RIGHT:
			case 'd':
				timeScale *= 10.0;
				break;
			case 'r':
				timeMillis = 0l;
				break;

			case '1':
				planner.setMix(blacktip::Mix::getMixAir());
				break;

			case '2':
				planner.setMix(blacktip::Mix::getMixEan32());
				break;

			case '3':
				planner.setMix(blacktip::Mix::getMixEan36());
				break;
			}

			if (depth < 0.0)
				depth = 0.0;

			if (timeScale < 0.01)
				timeScale = 0.01;
			else if (timeScale > 100000.0)
				timeScale = 100000.0;
		}
	}
}
