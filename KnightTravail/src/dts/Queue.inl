namespace dts
{
	template<typename T>
	Queue<T>::Queue()
	{
		m_next = nullptr;
	}

	template<typename T>
	Queue<T>::Queue(T element)
	{
		m_next = nullptr;
		m_element = element;
	}

	template<typename T>
	int Queue<T>::Enqueue(T element)
	{
		Queue* newQueue = new Queue(element);
		newQueue->m_next = m_next;
		m_next = newQueue;

		return 0;
	}

	template<typename T>
	T Queue<T>::Dequeue()
	{
		Queue* temp = nullptr;
		T data;

		if (isEmpty())
		{
			assert(false);
		}

		for (temp = this; temp->m_next != nullptr && temp->m_next->m_next != nullptr; temp = temp->m_next) {}

		data = temp->m_next->m_element;
		delete temp->m_next;
		temp->m_next = nullptr;

		return data;
	}

	template<typename T>
	inline bool Queue<T>::isEmpty()
	{
		return m_next ? false : true;
	}
}