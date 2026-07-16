#include <gtest/gtest.h>

#include "Counter.h"

TEST(CounterTest, DefaultConstructor) {
    Counter counter;
    EXPECT_EQ(counter.Value(), 0);
}

TEST(CounterTest, Increment) {
    Counter counter;
    counter.Increment();
    EXPECT_EQ(counter.Value(), 1);
}

TEST(CounterTest, Reset) {
    Counter counter;
    counter.Increment();
    counter.Reset();
    EXPECT_EQ(counter.Value(), 0);
}