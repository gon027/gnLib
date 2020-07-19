#ifndef RENDER_H
#define RENDER_H

#define RenderIns Render::Instance

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

#endif // !RENDER_H
