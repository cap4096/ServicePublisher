#ifndef H6933c4fdfe5e408bae6dca4187eb61daH
#define H6933c4fdfe5e408bae6dca4187eb61daH
#include <type_traits>

template<typename T>
u_int8_t* serialize(u_int8_t* buffer, T value)
{
    if(std::is_integral<T>::value)
    {
        if (std::is_unsigned<T>::value)
        {
            for (auto i = 0; i < sizeof(T); i++)
            {
                *buffer ++ =  (value >> (i*8)) & 0xFF;
            }
        }
        if (std::is_signed<T>::value)
        {
            union
            {
                std::make_signed<T>::type s;
                std::make_unsigned<T>::type u;
            } conv;

            conv.s = value;

            for (auto i = 0; i < sizeof(T); i++)
            {
                *buffer++ =  (conv.u >> (i*8)) & 0xFF;
            }
        }
    }
    return buffer;
}

template<typename T>
const u_int8_t* deSerialize(T& value, const u_int8_t* buffer)
{
    if(std::is_integral<T>::value)
    {
        if (std::is_unsigned<T>::value)
        {
            value = 0;
            for (auto i = 0; i < sizeof(T); i++)
            {
                value |= *buffer++ << (i * 8);
            }
        }

        if (std::is_signed<T>::value)
        {
            union
            {
                std::make_signed<T>::type s;
                std::make_unsigned<T>::type u;
            }conv;

            conv.u = 0;
            for (auto i = 0; i < sizeof(T); i++)
            {
                conv.u |= *buffer++ << (i * 8);
            }
            value = conv.s;
        }
    }

    return buffer;
}

inline u_int8_t* serialize(u_int8_t* buffer, const std::string& value)
{
    const std::u_int32_t size = value.size()+1;
    const std::u_int8_t zero = 0;

    buffer = serialize(buffer, size);
    for(char c : value)
    {
        *buffer++ = reinterpret_cast<u_int8_t>(c);
    }
    buffer = serialize(buffer, zero);
}

const u_int8_t* deSerialize(std::string& value, const u_int8_t* buffer)
{
    std::u_int32_t size=0;
    value.clear();

    buffer = deSerialize(size, buffer);
    value.append(0, buffer, size);
    buffer += size;

    return buffer;
}

#endif
