#pragma once
#include<iostream>

using namespace std;

void smart_test() {
	auto_ptr<string> t1 = auto_ptr<string>(new string("123"));
	cout << *t1.get() << endl;
	// 不会报错, 但是访问会有异常
	auto_ptr<string> t2 = t1;
	cout << *t2.get() << endl;
	// cout << *t1.get() << endl; 这里报异常


	unique_ptr<string> u1 = unique_ptr<string>(new string("321"));
	cout << *u1.get() << endl;
	unique_ptr<string> u2;
	// u2 = u1;   编辑器会提示异常, 不允许赋值

	// 所以unique_ptr比auto_ptr要安全一些, 并且	auto_ptr 在c++11里也已经抛弃了, 是98的方案

	// shared_ptr, 共享智能指针
	shared_ptr<string> s1 = shared_ptr<string>(new string("sss"));
	shared_ptr<string> s2 = s1;
	cout << s1.use_count() << ',' << s2.use_count() << endl;
	s1.reset();
	cout << s1.use_count() << ',' << s2.use_count() << endl;
	cout << *s2.get() << endl;

	// weak_ptr, 为的是避免shared_ptr的死锁
	weak_ptr<string> w1 = s2;
	cout << w1.use_count() << ',' << s2.use_count() << endl;
	cout << *w1.lock().get() << endl;

	/*
	总结
	智能指针出现是为了避免出现忘记释放指针的情况, 因为智能指针是类, 出类的作用域的时候, 执行析构函数, 自动释放
	auto_ptr 是c++98的, 已经废弃, 因为虽然是独占的智能指针, 但是赋值给其他的auto_ptr时,编译器并不会给出报错
	unique_ptr 是取代了auto_ptr, 给其他的unique_ptr赋值时,会提示异常
	shared_ptr 共享智能指针, 引用计数, 当计数为0时, 会释放
	weak_ptr 为了配合shard_ptr出现的, 防止出现死锁问题
	*/
}
