#include <raylib.h>

int main(int argc, char const* argv[]) {
	const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("SJ's Dot-Reaction", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
