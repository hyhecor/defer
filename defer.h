#pragma once

#ifndef _DEFER_H_
#define _DEFER_H_

#include <functional>

#define DEFER_BEGIN(func) \
defer func ([&]()->void \
{

#define DEFER_END }); 

class defer
{
    std::function<void()> callback_ = NULL;
public:
    defer(std::function<void()> callback)
        : callback_(callback)
    {
    }

    ~defer()
    {
        if (this->callback_)
            this->callback_();
    }

};

#endif // !_DEFER_H_

