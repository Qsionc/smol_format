/**
 *  @author:    Qsionc
 *  @date:      30/07/2021
 *  @file:      to_string.h
 *  @brief:     
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_TO_STRING_H
#define SMOLFORMAT_TO_STRING_H

#include <string>
#include <utility>

namespace smol::detail {
    /**
     * @brief converts target object of type T to std::string
     * @tparam T type of object to be converted
     * @param _object universal reference to object of type T
     * @return std::string form of object passed
     */
    template<class T>
    requires std::is_arithmetic_v<std::remove_cvref_t<T>>
    auto to_string(T&& _object) {
        return std::to_string(std::forward<T>(_object));
    }

    /**
     * @brief converts target object of type T to std::string
     * @tparam T type of object to be converted
     * @param _object universal reference to object of type T
     * @return std::string form of object passed
     */
    template<class T>
    requires std::is_convertible_v<T, std::string>
    auto to_string(T&& _object) {
        return std::string(std::forward<T>(_object));
    }
}

#endif //SMOLFORMAT_TO_STRING_H
