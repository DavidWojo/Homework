#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class BlockingQ
{
public:
	BlockingQ();
	void Push(int i);
	int Pop();
private:
	mutex mtx;
	condition_variable condition_var;
	const static int BUF_SIZE = 5;
	int items[BUF_SIZE];
	int numItems;
	int headPtr;
	int tailPtr;
	void incHead()
	{
		if (this->headPtr == BUF_SIZE - 1)
		{
			this->headPtr = 0;
		}
		else
		{
			this->headPtr++;
		}

	}
	void incTail()
	{
		if (this->tailPtr == BUF_SIZE - 1)
		{
			this->tailPtr = 0;
		}
		else
		{
			this->tailPtr++;
		}
	}
} ;

 BlockingQ::BlockingQ() :
	items {0},
	numItems(0),
	headPtr(0),
	tailPtr(0)
{
}

 void BlockingQ::Push(int i)
{
	unique_lock<mutex> lock(mtx);
	condition_var.wait(lock, [this]() { return numItems < BUF_SIZE; });
	items[headPtr] = i;
	incHead();
	numItems++;
	lock.unlock();
	condition_var.notify_one();
}

int BlockingQ::Pop()
{
	unique_lock<mutex> lock(mtx);
	condition_var.wait(lock, [this]() { return numItems > 0; });
	int item = items[tailPtr];
	incTail();
	numItems--;
	lock.unlock();
	condition_var.notify_one();
	return item;
}

int main(int argc, char* argv[])
{
	const static int iterations = 30;

	mutex mtx;
	BlockingQ q;
	cout << "Hardware Concurrency: " << thread::hardware_concurrency() << endl;

	auto producer = [&]()
	{
		for (int i = 0; i < iterations; i++)
		{
			q.Push(i);
			unique_lock<mutex> lock(mtx);
			cout << "Pushed: " << i << endl;
			lock.unlock();
		}
	};
	auto consumer = [&]()
	{
		for (int i = 0; i < iterations; i++)
		{
			int item = q.Pop();
			unique_lock<mutex> lock(mtx);
			cout << "Popped: " << item << endl;
			lock.unlock();
		}
	};

	thread producerThread(producer);
	thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	return 0;
}

