#ifndef _PUBLISHER_H
#define _PUBLISHER_H

#include <iostream>

class CMSPublisher
{
    public:
        std::string send_to_queue(std::string payload);
};

#endif
