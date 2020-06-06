#pragma once

#include <inttypes.h>

class LedBase
{
public:
    virtual ~LedBase() = default;

    virtual void init() { _init(); _turnOff(); }
    virtual void turnOn() { _turnOn(); }
    virtual void turnOff() { _turnOff(); }
    virtual void setPWMValue(uint8_t percent) { _setPWMValue(percent); }
    virtual void update() { }

protected:
    LedBase() = default;
    //LedBase(const LedBase &) = delete;
    //LedBase(const LedBase &&) = delete;

    virtual void _init() {}
    virtual void _turnOn() = 0;
    virtual void _turnOff() = 0;
    virtual void _setPWMValue(uint8_t percent) = 0;
};