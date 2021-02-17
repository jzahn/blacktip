#ifndef BLACKTIP_H
#define BLACKTIP_H

#include "blacktip/decoalgorithm.hpp"
#include "blacktip/recplanner.hpp"

namespace blacktipexp
{
	class Blacktip
	{
	private:
		static const unsigned int ALGORITHM_DELAY = 10000;

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
		Blacktip(char const *algorithmName);
		virtual ~Blacktip();

		void loop();
	};

}

#endif
