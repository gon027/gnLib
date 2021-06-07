#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "Transform.h"

using std::string;

namespace gnLib {

	// �I�u�W�F�N�g�̊��N���X
	class Object {
	public:
		Object() 
			: name("Object")
			, isActive(true)
			, transform()
		{ };

		virtual ~Object() = default;

		// �I�u�W�F�N�g�̖��O��ύX����
		void setName(const string& _name) {
			name = _name;
		}

		// �I�u�W�F�N�g�̖��O���擾����
		const string& getName() {
			return name;
		}

		// Active��ύX����
		void setActive(bool _active) {
			isActive = _active;
		}

		// Active���擾����
		bool getActive() {
			return isActive; 
		}

	public:
		Transform transform;

	protected:
		string name;
		bool isActive;
	};

}

#endif // !OBJECT_H
