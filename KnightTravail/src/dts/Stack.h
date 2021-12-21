#include <assert.h>

namespace dts
{
	template<typename T>
	class Stack
	{
	public:
		T m_element;
		Stack* m_next;

		Stack();
		Stack(T element);

		int Push(T element);
		T Pop();
		bool isEmpty();
	};
}

#include "dts/Stack.inl"