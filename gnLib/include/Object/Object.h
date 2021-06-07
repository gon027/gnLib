#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "Transform.h"

using std::string;

namespace gnLib {

	// オブジェクトの基底クラス
	class Object {
	public:
		Object() 
			: name("Object")
			, isActive(true)
			, transform()
		{ };

		virtual ~Object() = default;

		// オブジェクトの名前を変更する
		void setName(const string& _name) {
			name = _name;
		}

		// オブジェクトの名前を取得する
		const string& getName() {
			return name;
		}

		// Activeを変更する
		void setActive(bool _active) {
			isActive = _active;
		}

		// Activeを取得する
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
