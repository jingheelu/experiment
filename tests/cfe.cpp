#include <stdint.h>
#include <iostream>
#include "cf.h"

struct cfe
{
    static const char* const name;
};

const char* const ::cfe::name = "cfe";

namespace fixmsg
{
    struct ExecutionReport
    {
        uint64_t rget_ClOrdID() const
        {
            return 111;
        }
    };
}

#if 0
template<>
template<typename MsgT>
/*static*/ void FieldDecoder< ::cfe, ClOrdID>::Apply(const MsgT& /*m*/, uint64_t& clOrdID)
{
    //clOrdID = m.get_ClOrdID();
    clOrdID = 222;
}
#endif

template<typename From>
struct ConvertMessage< ::cfe, From, uint64_t>
{
    static void Apply(const From& from, uint64_t& to)
    {
        std::cout << "ConvertMessage< ::cfe, typename, uint64_t>::Apply()" << std::endl;
        //FieldDecoder< ::cfe, ClOrdID>::Apply(from, to);
        to = 223;
    }
};

int  main()
{
    ::fixmsg::ExecutionReport msg;
    uint64_t id;
    ConvertMessage< ::cfe, ::fixmsg::ExecutionReport, uint64_t>::Apply(msg, id);
    std::cout << "id = " << id << std::endl;

    return 0;
}
