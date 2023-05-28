#include <raylib.h>

int main(void)
{
	InitWindow(640, 480, "RayPaint");
	InitAudioDevice();

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
			
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
