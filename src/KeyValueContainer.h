#ifndef H65503b85e0d64dc5b989e8db2ddf0f11H
#define H65503b85e0d64dc5b989e8db2ddf0f11H
#include "KeyValueEntry.h"

class KeyValueContainer
{
public:
    std::vector<KeyValueEntry> entries;

};

inline std::u_int8_t* serialize(std::u_int8_t* buffer, const KeyValueContainer& container)
{
    std::u_int32_t size = container.entries.size();

    buffer = serialize(buffer, size);
    for(const auto& e : container.entries )
    {
        buffer = serialize(buffer, e);
    }

    return buffer;
}

inline const std::u_int8_t* deSerialize(KeyValueContainer& container, const std::u_int8_t* buffer)
{
    std::u_int32_t size = 0;

    buffer = deSerialize(size, buffer);
    for(std::u_int32_t i=0;i<size;i++)
    {
        KeyValueEntry entry;

        buffer = deSerialize(entry, buffer);
        container.entries.push_back(entry);
    }

    return buffer;
}

#endif
