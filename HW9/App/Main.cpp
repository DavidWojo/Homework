#include <iostream>
#include <thread>

using namespace std;

void MyFunc(int x)
{
	cout << "Count down..." << endl;
	while (x > 0)
	{
		cout << x << endl;
		--x;
	}
	cout << "Lift off!" << endl << endl;
}

class MyClass
{
public:
	void operator()(int x) { MyFunc(x); }
};



int main()
{
	constexpr int NUM = 5;


	thread t1{ MyFunc, NUM };
	t1.join();

	thread t2{ MyClass(), NUM };
	t2.join();

	thread t3{ [](int x) { MyFunc(x); }, NUM };
	t3.join();


}