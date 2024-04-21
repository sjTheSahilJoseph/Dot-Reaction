#include "main.h"

// Screen Size
const int screenWidth = 1280;
const int screenHeight = 800;
const int FPS = 1000;

char player_1_score[] = "89";

Ball ball;

Player player;

Player2_Opponent player2;

Score score1;

Line l1;

int main(int argc, char const* argv[]) {
    InitWindow(screenWidth, screenHeight, "SJ's Dot-Reaction");

	SetTargetFPS(FPS);

	ball.w = 10;
	ball.h = 10;
	ball.c = COLOR2;
	ball.x = (float)screenWidth/2;
	ball.y = (float)screenHeight/2;
	ball.speed_x = .50;
	ball.speed_y = .50;

	player.w = 20;
	player.h = 200;
	player.c = COLOR1;
	player.x = 10;
	player.y = (float)((float)screenHeight/2 - 50);
	player.speed = .99f;
    
	player2.w = 20;
	player2.h = 200;
	player2.c = COLOR1;
	player2.x = (screenWidth - player2.w - 10);
	player2.y = (float)((float)screenHeight/2 - player2.h/2);
	player2.speed = .99f;

	score1.t = player_1_score;
	score1.c = COLOR1;
	score1.r = 50;
	score1.x = (((float)screenWidth/2) - score1.r/2);
	score1.y = 10;

	l1.start_x = ((float)screenWidth/2);
	l1.end_x = ((float)screenWidth/2);
	l1.start_y = (0);
	l1.end_y = ((float)screenHeight);
	l1.c = COLOR1D;

	Rectangle ballRect = { ball.x, ball.y, ball.w, ball.h };
	Rectangle playerRect = { player.x, player.y, player.w, player.h };
	Rectangle player2Rect = { player2.x, player2.y, player2.w, player2.h };

    while (!WindowShouldClose()) {
        BeginDrawing();

		ball.Update();
		player.Update();
		player2.Update(ball.y);


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
		score1.Draw();
		l1.Draw();
        EndDrawing();
    }
    
    CloseWindow();
	return 0;
}
