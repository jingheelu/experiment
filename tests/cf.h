#if !defined(CF_H__)
#define CF_H__

#include <stdint.h>
#include <iostream>

struct ClOrdID;
struct OrderQty;

template<typename OrderRouterT, typename Field>
struct FieldDecoder
{
    static void Apply() {}
};

template<typename OrderRouterT>
struct FieldDecoder<OrderRouterT, ClOrdID>
{
    template<typename MsgT>
    static void Apply(const MsgT& m, uint64_t& clOrdID)
    {
        clOrdID = m.get_ClOrdID();
    }
};

template<typename OrderRouterT, typename From, typename To>
struct ConvertMessage
{
    static void Apply(const From& from, To& to)
    {
        std::cout << "ConvertMessage<OrderRouterT, typename, typename>::Apply()" << std::endl;
    }
};

template<typename OrderRouterT, typename From>
struct ConvertMessage<OrderRouterT, From, uint64_t>
{
    static void Apply(const From& from, uint64_t& to)
    {
        std::cout << "ConvertMessage<OrderRouterT, typename, uint64_t>::Apply()" << std::endl;
        FieldDecoder<OrderRouterT, ClOrdID>::Apply(from, to);
    }
};

#endif
