#include <raylib.h>

class Score {
	public:
		float x;
		float y;
		float w;
		float h;
		float r;
		Color c;
		char const* t;
		
		void Draw() {
			DrawText(t, x, y, r, c);
		}

		void Update() {

		}
};
