#pragma once

#include <optional>
#include <cstddef>
#include <vector>

class CircularBuffer 
{
public:
    explicit CircularBuffer(size_t capacity) :
        mCapacity(capacity),
        mBuffer(capacity),
        mHead(0),
        mTail(0)
    {}

    // Returns false if full
    bool Push(int value)
    {
        if (Full())
            return false;

        
    }

    // Returns std::nullopt if empty
    std::optional<int> Pop()
    {

    }

    bool Empty() const
    {

    }

    bool Full() const
    {

    }

private:
    size_t mCapacity;
    std::vector<int> mBuffer;
    size_t mHead;
    size_t mTail;
};