#include <raylib.h>

class Score {
	public:
		float x;
		float y;
		float w;
		float h;
		Color c;
		char const* t;
		
		void Draw() {
			DrawText(t, x, y, 50, c);
		}

		void Update() {

		}
};
