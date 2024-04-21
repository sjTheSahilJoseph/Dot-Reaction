#include <raylib.h>
#include "colors.h"

class Player {
	protected:
		bool isMovingUp;
		bool isMovingDown;

		void LimitMovement() {
			if (y <= 0) {
				y = 0;
			}

			if (y + h >= GetScreenHeight()) {
				y = GetScreenHeight() - h;
			}
		}
	public:
		float x;
		float y;
		float w;
		float h;
		float speed;
		Color c;

		Player() : isMovingUp(false), isMovingDown(false) {}

		void Draw() {
			DrawRectangle(x, y, w, h, c);
		}

		void Update() {
			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_UP)) {
				y -= speed;
				c = COLOR3;
				isMovingUp = true;
			} else {
				isMovingUp = false;
			}

			if (IsKeyDown(KEY_F) || IsKeyDown(KEY_DOWN)) {
				y += speed;
				c = COLOR3;
				isMovingDown = true;
			} else {
				isMovingDown = false;
			}

			if (!isMovingUp && !isMovingDown) {
				c = COLOR1;
			}

			LimitMovement();
		}
};

class Player2_Opponent : public Player {

	public:
		void Update(float ball_y) {
			if (IsKeyDown(KEY_K) || IsKeyDown(KEY_UP)) {
				y = y - speed;
				c = COLOR3;
				isMovingUp = true;
			} else {
				isMovingUp = false;
			}


			if (IsKeyDown(KEY_J) || IsKeyDown(KEY_DOWN)) {
				y = y + speed;
				c = COLOR3;
				isMovingDown = true;
			} else {
				isMovingDown = false;
			}

			if (!isMovingUp && !isMovingDown) {
				c = COLOR1;
			}


			LimitMovement();
		}
};
