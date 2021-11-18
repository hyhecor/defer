#pragma once

#ifndef __DEFER_H__
#define __DEFER_H__

#include <functional>


#define __DEFER_H_TOKEN_PASTE__(x, y) __##x##__##y##__
#define __DEFER_H_CAT__(x, y) __DEFER_H_TOKEN_PASTE__(x, y)
#define __DEFER_H_UNIQUE_NAME__(prefix) \
    __DEFER_H_CAT__(prefix, __LINE__)

#define DEFER_BEGIN \
defer __DEFER_H_UNIQUE_NAME__(DEFER_FUNC) ([&]()->void \
{

#define DEFER_END \
});


class defer
{
    std::function<void()> callback_ = 0;
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

#endif //!__DEFER_H__

