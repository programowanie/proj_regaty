#include "Weather.h"
#include "Buoy.h"
class Boat{
	private:
		int weight, length, c_skill;
		int s_size;
		static int counter;
	public:
		Boat();
		void refresh(Weather *weather, Buoy *buoy);
		int id, id_buoy;
		int X_position, Y_position;
		int distance;
		float speed;
		bool ruin;
};
