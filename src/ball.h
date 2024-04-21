#include <raylib.h>

class Ball {
	public:
		float x;
		float y;
		float speed_x;
		float speed_y;
		float w;
		float h;
		Color c;
		
		void Draw() {
		DrawRectangle(x, y, w, h, c);
		}

		void Update() {
			x += speed_x;
			y += speed_y;

			float radius = (float) (w+h) / 4;
			if (y + radius >= GetScreenHeight() || y - radius <= 0 ) {
				speed_y *= -1;
			}
			if (x + radius >= GetScreenWidth() || x - radius <= 0 ) {
				speed_x *= -1;
			}
		}
};
