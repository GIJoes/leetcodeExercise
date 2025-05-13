#include "pch.h"

template<typename T>
T GetMax(const T& a, const T& b)
{
	return a > b ? a : b;
}

//类模板
template<typename T>
class Data {
public :
	static constexpr bool copyable = true;
};

/// <summary>
/// 函数模板
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="x"></param>
template<typename T>
void log(T x)
{
	std::cout << x << std::endl;
}

/// <summary>
/// 变量模板
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
T zero = 0;

/// <summary>
/// 变量模板的命名空间
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
bool dataCopyable = Data<T>::copyable;

/// <summary>
/// 别名模板的命名空间
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
using DataList = Data<T*>;

/// <summary>
/// 
/// </summary>
class Collection {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	class Node {
		T value;
	};

	/// <summary>
	/// 类内函数
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	T* alloc() {
		return new T();
	}

	/// <summary>
	/// 类内模板变量
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	static T zero = 0;

	/// <summary>
	/// 类内模板别名
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	using NodePtr = Node<T>*;
};

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class List {
public:
	List() = default;

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="U"></typeparam>
	template<typename U>
	class Handle;

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename U>
	List(List<U> const&);

	
	template<typename U>
	static U Zero;

};

/// <summary>
/// 
/// </summary>
template<typename T>
template<typename U>
class List<T>::Handle {

};

/// <summary>
/// 
/// </summary>
template<typename T>
template<typename U>
List<T>::List(List<U> const&)
{
}

/// <summary>
/// 
/// </summary>
template<typename T>
template<typename U>
U List<T>::Zero = 0;

template<typename T>
union AllocChunck
{
	T object;
	unsigned char bytes[sizeof(T)];
};


TEST(TestTemplate, GetMax) {

	List<double>list;
	//auto x = List<double>::Zero;

	EXPECT_EQ(GetMax(1212432,243254), 1212432);
}

