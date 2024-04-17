#include <raylib.h>

class Ball {
	public:
		float x;
		float y;
		float speed_x;
		float speed_y;
		float w;
		float h;
		
		void Draw() {
		DrawRectangle(x, y, w, h, WHITE);
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

class Player {
	public:
		float x;
		float y;
		float w;
		float h;
		int speed;

		void Draw() {
			DrawRectangle(x, y, w, h, WHITE);
		}

		void Update() {
			if (IsKeyDown(KEY_K) || IsKeyDown(KEY_UP)) {
				y = y - speed;
			}
			if (IsKeyDown(KEY_J) || IsKeyDown(KEY_DOWN)) {
				y = y + speed;
			}
		}
};

Ball ball;

Player player;

int main(int argc, char const* argv[]) {
	// Screen Size
	const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");

	// FPS
	SetTargetFPS(60);

	ball.w = 10;
	ball.h = 10;
	ball.x = (float)screenWidth/2;
	ball.y = (float)screenHeight/2;
	ball.speed_x = 7;
	ball.speed_y = 7;

	player.w = 20;
	player.h = 100;
	player.x = screenWidth - player.w - 10;
	player.y = (screenHeight/2) - (player.h / 2);
	player.speed = 20;
    
    while (!WindowShouldClose()) {
        BeginDrawing();

		ball.Update();
		player.Update();

		ClearBackground(BLACK);
		ball.Draw();
		DrawRectangle(10, (screenHeight/2 - 50), 20, 100, WHITE);
		player.Draw();
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
