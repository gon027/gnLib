#ifndef OBJECT_H
#define OBJECT_H

namespace gnLib {

	// 描画させるオブジェクトの基底クラス
	class Object {
	public:
		Object() : isActive(true) {};
		virtual ~Object() {}

		void setActive(bool _active) {
			isActive = _active;
		}

		bool getActive() { return isActive; }

	private:
		bool isActive;
	};
}

#endif // !OBJECT_H
