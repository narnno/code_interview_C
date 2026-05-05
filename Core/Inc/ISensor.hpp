#ifndef _ISENSOR_HPP_
#define _ISENSOR_HPP_    

#include <stdint.h>

class ISensor{
    public:
		virtual uint16_t getRawValue() = 0;
        virtual float getGain() = 0;
        virtual int16_t getOffset() = 0;
    private:
};

#endif