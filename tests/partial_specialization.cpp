#include <iostream>

template<typename OrderRouterT, typename From, typename To>
struct ConvertMessage
{
    static void Apply(const From& from, To& to)
    {
        std::cout << "ConvertMessage<" << OrderRouterT::name << ",typename, typename>::Apply()" << std::endl;
        fa;fak;d
    }
};

template <typename OrderRouterT>
struct ConvertMessage<OrderRouterT, float, float>
{
    static void Apply(const float& from, float& to)
    {
        std::cout << "ConvertMessage<" << OrderRouterT::name << ", float, float>::Apply()" << std::endl;
    }
};

struct Generic
{
    static const char* const name;
};

struct Special1
{
    static const char* const name;
};

struct Special2
{
    static const char* const name;
};

template <>
struct ConvertMessage< ::Special1, float, float>
{
    static void Apply(const float& from, float& to)
    {
        std::cout << "ConvertMessage<" << ::Special1::name << ",float, float>::Apply()" << std::endl;
    }
};

const char* const ::Generic::name = "Generic";
const char* const ::Special1::name = "Special1";
const char* const ::Special2::name = "Special2";

int  main()
{
    int i, j;
    float f, g;

    //ConvertMessage< ::Generic, int, int>::Apply(i, j);
    //ConvertMessage< ::Generic, float, float>::Apply(f, g);
    //ConvertMessage< ::Special1, int, int>::Apply(i, j);
    ConvertMessage< ::Special1, float, float>::Apply(f, g);
    //ConvertMessage< ::Special2, int, int>::Apply(i, j);

    return 0;
}
