#include <stdint.h>
#include <raylib.h>

int main(void)
{
	uint64_t score = 0;
	
	InitWindow(640, 480, "Ballon Pop!");
	InitAudioDevice();

	SetTargetFPS(60);

	Texture2D clouds = LoadTexture("clouds.png");
	Sound pop = LoadSound("pop.mp3");
	Music lofi = LoadMusicStream("lofi.mp3");
	Vector2 ballonPos = 
		{GetRandomValue(0, 640), GetRandomValue(60, 480)};

	PlayMusicStream(lofi);
	
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
