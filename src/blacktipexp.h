#ifndef BLACKTIP_H
#define BLACKTIP_H

#include "blacktip/decoalgorithim.h"
#include "blacktip/recplanner.h"

namespace blacktipexp 
{
	class Blacktip
	{
	private:
		static const unsigned int ALGORITHIM_DELAY = 1000;

		bool quit = false;
		blacktip::RecreationalPlanner planner;
		double depth = 0.0;
		double timeScale = 1.0;
		long timeMillis = 0;

		void display();
		void displayCommonInfo();
		void displayCompartments();
		void input();

	public:
		Blacktip(char const *algorithimName);
		virtual ~Blacktip();

		void loop();
	};

}

#endif