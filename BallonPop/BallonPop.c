#include <stdio.h>
#include <stdint.h>
#include <raylib.h>

int main(void)
{
	InitWindow(640, 480, "Ballon Pop!");
	InitAudioDevice();

	SetTargetFPS(60);

	uint64_t score = 0;

	Texture2D clouds = LoadTexture("clouds.png");

	Sound pop = LoadSound("pop.mp3");

	Music lofi = LoadMusicStream("lofi.mp3");
	PlayMusicStream(lofi);

	Vector2 ballonPos = 
		{GetRandomValue(0, 640), GetRandomValue(60, 480)};

	while (!WindowShouldClose()) {
		UpdateMusicStream(lofi);

		if (
			CheckCollisionPointCircle(GetMousePosition(), ballonPos, 16) &&
			IsMouseButtonReleased(0)
		) {
			ballonPos = 
				(Vector2){GetRandomValue(0, 640), GetRandomValue(60, 480)};
			score++;
			PlaySound(pop);
		}

		BeginDrawing();
			DrawRectangleGradientV(0, 0, 640, 480, BLUE, SKYBLUE);
			DrawTexture(clouds, 0, 0, WHITE);
			
			DrawText(TextFormat("Score : %d", score), 10, 460, 20, BLACK);

			ballonPos.y--;

			DrawLineV(
					ballonPos,
					(Vector2){ballonPos.x, ballonPos.y + 50}, 
					YELLOW
			);

			DrawCircleV(ballonPos, 16, PINK);
		EndDrawing();
	}

	UnloadTexture(clouds);
	UnloadSound(pop);
	UnloadMusicStream(lofi);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
