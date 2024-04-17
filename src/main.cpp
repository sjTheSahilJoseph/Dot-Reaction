#include <raylib.h>

int main(int argc, char const* argv[]) {
	// Screen Size
	const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");

	// FPS
	SetTargetFPS(1000);
    
    while (!WindowShouldClose()) {
        BeginDrawing();

		ClearBackground(BLACK);

		DrawRectangle(screenWidth/2, screenHeight/2, 10, 10, WHITE);
		DrawRectangle(0, (screenHeight/2 - 50), 20, 100, WHITE);

        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
