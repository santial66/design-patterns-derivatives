
#ifndef WRAPPER_H
#define WRAPPER_H

template <class T>
class Wrapper
{
public:
	Wrapper()
	{
		_dataPtr = 0;
	}

	Wrapper(T const& inner)
	{
		_dataPtr = inner.clone();
	}

	~Wrapper()
	{
		if (_dataPtr != 0)
			delete _dataPtr;
	}

	Wrapper(Wrapper<T> const& orig)
	{
		if (orig._dataPtr != 0)
			_dataPtr = orig._dataPtr->clone();
		else
			_dataPtr = 0;
	}

	Wrapper& operator=(Wrapper<T> const& orig)
	{
		if (this != &orig)
		{
			if (_dataPtr != 0)
				delete _dataPtr;
			if (orig._dataPtr != 0)
				_dataPtr = orig._dataPtr->clone();
			else
				_dataPtr = 0;
		}
	}

	T& operator*()
	{
		return *_dataPtr;
	}

	const T& operator*()const
	{
		return *_dataPtr;
	}

	T* operator->()
	{
		return _dataPtr;
	}

private:
	T* _dataPtr;

};

#endif // !WRAPPER_H


