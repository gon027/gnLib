#ifndef OBJECT_H
#define OBJECT_H

namespace gnLib {

	// �`�悳����I�u�W�F�N�g�̊��N���X
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
