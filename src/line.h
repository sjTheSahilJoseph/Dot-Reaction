#include <raylib.h>

class Line {
	public:
		float start_x;
		float start_y;
		float end_x;
		float end_y;
		Color c;
		
		void Draw() {
			DrawLine(start_x, start_y, end_x, end_y, c);
		}

		void Update() {

		}
};
