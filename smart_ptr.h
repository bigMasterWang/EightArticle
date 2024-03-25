#pragma once
#include<iostream>

using namespace std;

void smart_test() {
	auto_ptr<string> t1 = auto_ptr<string>(new string("123"));
	cout << *t1.get() << endl;
	// ���ᱨ��, ���Ƿ��ʻ����쳣
	auto_ptr<string> t2 = t1;
	cout << *t2.get() << endl;
	// cout << *t1.get() << endl; ���ﱨ�쳣


	unique_ptr<string> u1 = unique_ptr<string>(new string("321"));
	cout << *u1.get() << endl;
	unique_ptr<string> u2;
	// u2 = u1;   �༭������ʾ�쳣, ������ֵ

	// ����unique_ptr��auto_ptrҪ��ȫһЩ, ����	auto_ptr ��c++11��Ҳ�Ѿ�������, ��98�ķ���

	// shared_ptr, ��������ָ��
	shared_ptr<string> s1 = shared_ptr<string>(new string("sss"));
	shared_ptr<string> s2 = s1;
	cout << s1.use_count() << ',' << s2.use_count() << endl;
	s1.reset();
	cout << s1.use_count() << ',' << s2.use_count() << endl;
	cout << *s2.get() << endl;

	// weak_ptr, Ϊ���Ǳ���shared_ptr������
	weak_ptr<string> w1 = s2;
	cout << w1.use_count() << ',' << s2.use_count() << endl;
	cout << *w1.lock().get() << endl;

	/*
	�ܽ�
	����ָ�������Ϊ�˱�����������ͷ�ָ������, ��Ϊ����ָ������, ������������ʱ��, ִ����������, �Զ��ͷ�
	auto_ptr ��c++98��, �Ѿ�����, ��Ϊ��Ȼ�Ƕ�ռ������ָ��, ���Ǹ�ֵ��������auto_ptrʱ,�������������������
	unique_ptr ��ȡ����auto_ptr, ��������unique_ptr��ֵʱ,����ʾ�쳣
	shared_ptr ��������ָ��, ���ü���, ������Ϊ0ʱ, ���ͷ�
	weak_ptr Ϊ�����shard_ptr���ֵ�, ��ֹ������������
	*/
}
