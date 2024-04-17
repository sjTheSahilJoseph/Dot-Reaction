#include <raylib.h>

class Ball {
	public:
		float x;
		float y;
		int speed_x;
		int speed_y;
		int w;
		int h;
		
		void Draw() {
		DrawRectangle(x, y, w, h, WHITE);
		}
};

Ball ball;

int main(int argc, char const* argv[]) {
	// Screen Size
	const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");

	// FPS
	SetTargetFPS(1000);

	ball.w = 10;
	ball.h = 10;
	ball.x = screenWidth/2;
	ball.y = screenHeight/2;
	ball.speed_x = 5;
	ball.speed_y = 5;
    
    while (!WindowShouldClose()) {
        BeginDrawing();

		ClearBackground(BLACK);
		ball.Draw();
		DrawRectangle(10, (screenHeight/2 - 50), 20, 100, WHITE);
		DrawRectangle((screenWidth - 20 - 10), (screenHeight/2 - 50), 20, 100, WHITE);

        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
