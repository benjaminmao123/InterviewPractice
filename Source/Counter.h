#pragma once

class Counter
{
public:
    Counter() : mValue(0) {}
    void Increment() { mValue++; }
    void Reset() { mValue = 0; }
    int Value() const { return mValue; }

private:
    int mValue;
};
