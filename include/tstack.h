#pragma once

#include <iostream>
#include <vector>

template<class T>
class Stack
{
	std::vector<T> data;
	int tp;

public:
	Stack(int n = 0, T value = T()) : tp(n - 1)
	{
		if (n < 0)
			throw "negative size";

		data = std::vector<T>(n, value);
	}

	void change(T value) noexcept
	{
		pop();
		push(value);
	}

	void push(const T& val) noexcept
	{
		
		data.push_back(val);
		tp++;
	}

	void pop()
	{
		if (empty()) {
			throw "Stack Empty";
		}

		data.pop_back();
		tp--;
	}

	T& top() 
	{
		if (empty()) {
			throw "Stack Empty";
		}

		return data[tp];
	}

	bool empty() noexcept
	{
		if (tp == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	size_t size()
	{
		return (tp >= 0 ? tp + 1 : 0);
	}
};