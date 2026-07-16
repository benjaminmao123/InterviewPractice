#pragma once

class Counter
{
public:
    Counter() : value_(0) {}
    void Increment() { value_++; }
    void Reset() { value_ = 0; }
    int Value() const { return value_; }

private:
    int value_;
};
