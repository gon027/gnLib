#ifndef OBJECT_H
#define OBJECT_H

namespace gnLib {
	class Object {
	public:
		Object() {};
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
