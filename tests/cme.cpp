#include <stdint.h>
#include <iostream>
#include "cf.h"

struct cme
{
    static const char* const name;
};

const char* const ::cme::name = "cme";

namespace fixmsg
{
    struct ExecutionReport
    {
        uint64_t get_ClOrdID() const
        {
            return 1;
        }

    };
}

int  main()
{
    ::fixmsg::ExecutionReport msg;
    uint64_t id;
    ConvertMessage< ::cme, ::fixmsg::ExecutionReport, uint64_t>::Apply(msg, id);
    std::cout << "id = " << id << std::endl;

    return 0;
}
