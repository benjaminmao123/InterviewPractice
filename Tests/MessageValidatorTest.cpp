#include <gtest/gtest.h>

#include "MessageValidator.h"

TEST(MessageValidatorTest, ValidMessage)
{
    MessageValidator validator;

    // Test valid message with 4 bytes
    std::vector<uint8_t> message = {0xAA, 0x01, 0x02, 0x55};
    EXPECT_TRUE(validator.IsValid(message));
}   

TEST(MessageValidatorTest, InvalidMessageSize)
{
    MessageValidator validator;

    // Test message with less than 4 bytes
    std::vector<uint8_t> message = {0xAA, 0x01, 0x02};
    EXPECT_FALSE(validator.IsValid(message));

    // Test empty message
    message.clear();
    EXPECT_FALSE(validator.IsValid(message));
}

TEST(MessageValidatorTest, InvalidMessageStart)
{
    MessageValidator validator;
    std::vector<uint8_t> message = {0xAB, 0x01, 0x02, 0x55};
    EXPECT_FALSE(validator.IsValid(message));
}

TEST(MessageValidatorTest, InvalidMessageEnd)
{
    MessageValidator validator;
    std::vector<uint8_t> message = {0xAA, 0x01, 0x02, 0x56};
    EXPECT_FALSE(validator.IsValid(message));
}