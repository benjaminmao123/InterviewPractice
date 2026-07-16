#pragma once

#include <vector>
#include <cstdint>

class MessageValidator {
    public:
        /*
            Requirements:
            ---------------
            Message must contain at least 4 bytes.
            The first byte must be 0xAA.
            The last byte must be 0x55.
            Return true only if all requirements are met; otherwise return false.
         */
            bool IsValid(const std::vector<uint8_t>& message)
            {
                return message.size() >= 4 &&
                       message[0] == 0xAA &&
                       message.back() == 0x55;
            }
    };