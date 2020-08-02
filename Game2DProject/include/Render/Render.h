#ifndef RENDER_H
#define RENDER_H

namespace gnLib {
#define RenderIns Render::Instance
#define RenderDevice Render::Instance->getGraphics()->getDevice()

	class Graphics;

	class Render {
	public:
		Render();
		~Render() = default;

		static Render* Instance;

		void setGraphics(Graphics* _graphics);
		Graphics* getGraphics() const;

	private:
		Graphics* graphics;

		// コピーコンストラクタ禁止
		Render(const Render& _render) = delete;
		Render& operator= (const Render& _render) = delete;
	};
}

#endif // !RENDER_H
