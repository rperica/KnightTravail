#include <assert.h>

namespace dts
{
	template<typename T>
	class Queue
	{
	public:
		T m_element;
		Queue* m_next;

		Queue();
		Queue(T element);

		int Enqueue(T element);
		T Dequeue();
		bool isEmpty();
	};
}

#include "dts/Queue.inl"