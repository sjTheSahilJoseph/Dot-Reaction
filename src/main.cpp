#include "main.h"

// Screen Size
const int screenWidth = 1280;
const int screenHeight = 800;
const int FPS = 1000;

Ball ball;

Player player;

Player2_Opponent player2;


int main(int argc, char const* argv[]) {
    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");

	SetTargetFPS(FPS);

	ball.w = 10;
	ball.h = 10;
	ball.c = COLOR2;
	ball.x = (float)screenWidth/2;
	ball.y = (float)screenHeight/2;
	ball.speed_x = .60;
	ball.speed_y = .60;

	player.w = 20;
	player.h = 100;
	player.c = COLOR1;
	player.x = 10;
	player.y = (float)((float)screenHeight/2 - 50);
	player.speed = .9;
    
	player2.w = 20;
	player2.h = 100;
	player2.c = COLOR1;
	player2.x = (screenWidth - 20 - 10);
	player2.y = (float)((float)screenHeight/2 - player2.h/2);
	player2.speed = .9;

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

		ClearBackground(COLOR_BG);
		ball.Draw();
		player.Draw();
		player2.Draw();
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
