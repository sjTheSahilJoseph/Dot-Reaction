#include <raylib.h>

int main(int argc, char const* argv[]) {
	const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Test", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
