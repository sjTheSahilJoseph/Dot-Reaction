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
	protected:
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

			LimitMovement();
		}
};

class Player2_Opponent : public Player {

	public:
		void Update(float ball_y) {
			if (IsKeyDown(KEY_W)) {
				y = y - speed;
			}

			if (IsKeyDown(KEY_S)) {
				y = y + speed;
			}

			LimitMovement();
		}
};

Ball ball;

Player player;

Player2_Opponent player2;

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
	player.x = 10;
	player.y = (float)((float)screenHeight/2 - 50);
	player.speed = 20;
    
	player2.w = 20;
	player2.h = 100;
	player2.x = (screenWidth - 20 - 10);
	player2.y = (float)((float)screenHeight/2 - player2.h/2);
	player2.speed = 20;

    while (!WindowShouldClose()) {
        BeginDrawing();

		ball.Update();
		player.Update();
		player2.Update(ball.y);

		Rectangle ballRect = { ball.x, ball.y, ball.w, ball.h };
		Rectangle playerRect = { player.x, player.y, player.w, player.h };
		Rectangle player2Rect = { player2.x, player2.y, player2.w, player2.h };

		if (CheckCollisionRecs(ballRect, playerRect)) {
			ball.speed_x *= -1;
		}

		if (CheckCollisionRecs(ballRect, player2Rect)) {
			ball.speed_x *= -1;
		}

		ClearBackground(BLACK);
		ball.Draw();
		player.Draw();
		player2.Draw();
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
