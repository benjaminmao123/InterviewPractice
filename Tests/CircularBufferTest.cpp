#include <gtest/gtest.h>

#include "CircularBuffer.h"

TEST(CircularBufferTest, DefaultConstructor)
{
    CircularBuffer buffer(3);
    EXPECT_TRUE(buffer.Empty());
    EXPECT_FALSE(buffer.Full());
}

TEST(CircularBufferTest, PushToMaxCapacity)
{
    CircularBuffer buffer(3);
    EXPECT_TRUE(buffer.Push(1));
    EXPECT_TRUE(buffer.Push(2));
    EXPECT_TRUE(buffer.Push(3));
    EXPECT_FALSE(buffer.Push(4)); // Buffer is full
    EXPECT_TRUE(buffer.Full());
}

TEST(CircularBufferTest, PopFromEmptyBuffer)
{
    CircularBuffer buffer(3);
    EXPECT_EQ(buffer.Pop(), std::nullopt); // Buffer is empty
}

TEST(CircularBufferTest, PopNonEmptyBuffer)
{
    CircularBuffer buffer(3);
    buffer.Push(1);
    buffer.Push(2);
    EXPECT_EQ(buffer.Pop(), 1);
    EXPECT_EQ(buffer.Pop(), 2);
    EXPECT_EQ(buffer.Pop(), std::nullopt); // Buffer is now empty
}

TEST(CircularBufferTest, WrapAround)
{
    CircularBuffer buffer(3);
    buffer.Push(1);
    buffer.Push(2);
    buffer.Push(3);
    EXPECT_TRUE(buffer.Full());
    EXPECT_EQ(buffer.Pop(), 1);
    EXPECT_TRUE(buffer.Push(4)); // Should succeed, as we popped one element
    EXPECT_EQ(buffer.Pop(), 2);
    EXPECT_EQ(buffer.Pop(), 3);
    EXPECT_EQ(buffer.Pop(), 4);
}

TEST(CircularBufferTest, EmptyAndFullChecks)
{
    CircularBuffer buffer(2);
    EXPECT_TRUE(buffer.Empty());
    EXPECT_FALSE(buffer.Full());

    buffer.Push(1);
    EXPECT_FALSE(buffer.Empty());
    EXPECT_FALSE(buffer.Full());

    buffer.Push(2);
    EXPECT_FALSE(buffer.Empty());
    EXPECT_TRUE(buffer.Full());

    buffer.Pop();
    EXPECT_FALSE(buffer.Empty());
    EXPECT_FALSE(buffer.Full());

    buffer.Pop();
    EXPECT_TRUE(buffer.Empty());
    EXPECT_FALSE(buffer.Full());
}