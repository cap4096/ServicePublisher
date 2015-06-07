//
// Created by malo on 2015-06-06.
//

#ifndef Habc6a9df0f0d45f7bc95b8af6811a8e5H
#define Habc6a9df0f0d45f7bc95b8af6811a8e5H

#include<string>
#include<vector>
#include "byte_order.h

class KeyValueEntry
{
public:
    std::string key;
    std::string value;

    KeyValueEntry(const std::string& key, const std::string& value) : key(key), value(value)
    { }
};

inline std::u_int8_t* serialize(std::u_int8_t* buffer, const KeyValueEntry& entry)
{
    buffer = serialize(buffer, key);
    buffer = serialize(buffer, value);

    return buffer;
}

inline const std::u_int8_t* deSerialize(KeyValueEntry& entry, const std::u_int8_t* buffer)
{
    buffer = deSerialize(entry.key, buffer);
    buffer = deSerialize(entry.value, buffer);

    return buffer;
}


#endif //SERVICEANNOUNCER_KEYVALUEENTRY_H
