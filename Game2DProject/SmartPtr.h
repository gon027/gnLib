#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <memory>

// スマートポインタのエイリアス宣言

template<class T>
using UniquePtr = std::unique_ptr<T>;

template<class T>
using SharedPtr = std::shared_ptr<T>;

template<class T>
using WeakPtr = std::weak_ptr<T>;

#endif // !SMARTPTR_H
