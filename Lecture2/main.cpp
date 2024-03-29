#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#include <vector>
#include <memory>

namespace jm
{
	class Example : public Game2D
	{
	public:
		std::vector<std::shared_ptr<GeometricObject>> my_objs;

		Example()
			: Game2D()
		{
			auto my_tri = std::make_shared<Triangle>(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			auto my_cir = std::make_shared<Circle>(Colors::red, vec2{ 0.0f, 0.0f }, 0.2f);
			auto my_box = std::make_shared<Box>(Colors::olive, vec2{ 0.5f, 0.5f }, 0.5f, 0.8f);

			my_objs.push_back(my_tri);
			my_objs.push_back(my_cir);
			my_objs.push_back(my_box);
		}

		void update() override
		{
			for (const auto& obj : my_objs)
				obj->draw();
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();

	return 0;
}