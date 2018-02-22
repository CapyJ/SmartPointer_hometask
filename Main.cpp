#include <iostream>

#include "Foo.h"
#include "SmartPtr.h"

#include <memory>

using namespace std;

int main() {

	{
		
		/*Foo s1(2);
		Foo s2(4);

		SmartPtr<Foo> ptr2 = new Foo(122);
		

		SmartPtr <Foo[]> ptr1 = new Foo[4]{ s1, s2, s1, s2 };
		cout<<ptr1[1].GetNum()<<endl;
		SmartPtr <Foo[]> ptr3(ptr1);
		cout << ptr3[1].GetNum() << endl;*/

		SmartPtr<Foo[]> s1 = new Foo[4];
		SmartPtr<Foo[]> s2 = s1;
		SmartPtr<Foo> s3 = new Foo;
		SmartPtr<Foo> s4 = s3;
		SmartPtr<Foo> s5 = new Foo;

		s5.operator=(s3);
		s4 = s5;

		cout << "Count: " << *(s1.count) << endl;
		s2.~SmartPtr();
		cout << "Count: " << *(s1.count) << endl;
		s1.~SmartPtr();
		cout << "Count: " << *(s1.count) << endl;

		cout << "Count: " << *(s3.count) << endl;
		s4.~SmartPtr();
		cout << "Count: " << *(s3.count) << endl;
		s3.~SmartPtr();
		cout << "Count: " << *(s3.count) << endl;

	}


	system("pause");
	return 0;
}