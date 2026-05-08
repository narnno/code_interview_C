#ifndef ISENSOR_H_
#define ISENSOR_H_

#include <stdint.h>

typedef uint16_t (*ISensorGetRawValueFn)(void *context);
typedef float (*ISensorGetGainFn)(void *context);
typedef int16_t (*ISensorGetOffsetFn)(void *context);

typedef struct
{
    void *context;
    ISensorGetRawValueFn getRawValue;
    ISensorGetGainFn getGain;
    ISensorGetOffsetFn getOffset;
} ISensor;

#endif