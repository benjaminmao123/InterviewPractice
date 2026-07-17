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
        mTail(0),
        mSize(0)
    {}

    // Returns false if full
    bool Push(int value)
    {
        if (Full())
            return false;

        mBuffer[mTail] = value;
        mTail = (mTail + 1) % mCapacity;
        ++mSize;
        return true;
    }

    // Returns std::nullopt if empty
    std::optional<int> Pop()
    {
        if (Empty())
            return std::nullopt;

        int value = mBuffer[mHead];
        mHead = (mHead + 1) % mCapacity;
        --mSize;
        return value;
    }

    bool Empty() const
    {
        return mSize == 0;
    }

    bool Full() const
    {
        return mSize == mCapacity;
    }

private:
    size_t mCapacity;
    std::vector<int> mBuffer;
    size_t mHead;
    size_t mTail;
    size_t mSize;
};