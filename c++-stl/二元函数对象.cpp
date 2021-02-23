#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

template <typename T>
struct SumAdd
{
	T operator()(T &t1, T &t2)
	{
		return t1 + t2;
	}
};

//vector相加
void test()
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;

    v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);

    v3.resize(3);
    /*
    template <class _InputIterator1, class _InputIterator2, class _OutputIterator, class _BinaryOperation>
    inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
    _OutputIterator
    transform(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2,
            _OutputIterator __result, _BinaryOperation __binary_op)
    {
        for (; __first1 != __last1; ++__first1, (void) ++__first2, ++__result)
            *__result = __binary_op(*__first1, *__first2);
        return __result;
    }
    */
    std::vector<int>::iterator it = transform(v1.begin(), v1.end(), v2.begin(),v3.begin(), SumAdd<int>());  //要看transform的返回值，以及是如何运行计算的
    for(std::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it) {
        std::cout << *it << std::endl; //5 7 9
    }

}

int main()
{
    test();
    std::cout << "hello world" << std::endl;
}