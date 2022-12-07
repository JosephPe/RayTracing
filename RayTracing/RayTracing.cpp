#include "Renderer/Renderer.h"
#include "Object/Sphere.h"
#include "Object/Scene.h"
#include <iostream>


int main(int, char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(600, 300);

	Canvas canvas(600, 300, renderer);
	Scene scene;
	//auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 }));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1.5, 0, -1 }, 0.7f, std::make_unique<Lambertian>(color3{ 0.63f, 0.01f, 0.36f })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ -1.5, 0, -1 }, 0.25f, std::make_unique<Lambertian>(color3{ 0, 0, 1 })));
	scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.2f, 0.2f, 0.2f })));

	bool quit = false;
	while (!quit)
	{

		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}


		canvas.Clear({ 0, 0, 0, 1 });
		renderer.Render(canvas, scene);
		canvas.Update();
		//for (int i = 0; i < 500; i++)
		//{

		//canvas.DrawPoint({ random(1, 600), random(1, 325)}, {1, 1, 1, 1});
		//canvas.Update();

		//}
		renderer.CopyCanvas(canvas);
		renderer.Present();
	}
	renderer.Shutdown();
	return 0;
}