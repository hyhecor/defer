#pragma once

#ifndef _DEFER_H_
#define _DEFER_H_

#include <functional>

#define TOKEN_PASTE(x, y) __##x##__##y##__
#define CAT(x,y) TOKEN_PASTE(x,y)
#define UNIQUE_DEFER_FUNC \
    CAT(DEFER_FUNC, __LINE__)

#define DEFER_BEGIN \
defer UNIQUE_DEFER_FUNC ([&]()->void \
{

#define DEFER_END \
});

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

