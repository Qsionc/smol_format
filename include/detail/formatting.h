/**
 *  @author:    Qsionc
 *  @date:      30/07/2021
 *  @file:      formatting.h
 *  @brief:     Formatting helper functions
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_FORMATTING_H
#define SMOLFORMAT_FORMATTING_H

#include <string>
#include "format_settings.h"
#include "to_string.h"

namespace smol::detail {
    /**
     * @brief function which returns next index of parameter from parameters passed to format class to be put on next position
     * @param _format string to be read from and later parsed
     * @param _pos current character index in format - in/out param
     * @param _count out param, how many elements to be replaced
     * @return next argument index value
     * @details
     * 1. if returns -2 - there is no more "spots" to be interpreted and replaced with data\n
     * 2. if returns -1 - on current location in format string should be put next element from argument list, if there are any more\n
     * 3. if returns values from 0 onwards, it represents index from which to read data.
     */
    inline int find_index(std::string const& _format, std::string::size_type& _pos, std::string::size_type& _count) {
        _pos = _format.find(detail::settings::format_prefix, _pos);
        auto end = _format.find(detail::settings::format_postfix);
        if (_pos == std::string::npos || end == std::string::npos) {
            return -2;
        }
        _count = end - _pos + 1;
        auto sub_format = _format.substr(_pos + 1, _count - 2);
        if (std::isdigit(sub_format[0])) {
            return std::stoi(sub_format);
        }
        return -1;
    }

    /**
     * @brief parses target format string with arguments passed down from format class as container of arguments
     * @tparam Container any container that supports iterators as well as at() method and size() method
     * @param _format string to be formatted
     * @param _args list of arguments
     * @details
     * This function uses find_index to find index and put proper arguments in its place.
     * If there are no more arguments, any parenthesis are replaced with empty string.\n
     * Additionally, if there is anything between parenthesis and it does not start with digit, is interpreted as empty parenthesis.
     * Otherwise, the number is read and interpreted.
     */
    template<class Container>
    void parse(std::string& _format, Container const& _args) {
        auto count = 0ul;
        auto iter = _args.begin();
        std::string::size_type pos = 0;
        std::string tmp;
        while (true) {
            auto index = find_index(_format, pos, count);
            tmp = (iter != _args.end()) ? (*iter)->get() : "";
            if (index == -2) {
                break;
            } else if (index == -1 || (uint) index >= _args.size()) {
                _format.replace(pos, count, tmp);
            } else {
                _format.replace(pos, count, _args.at(index)->get());
            }

            if (iter != _args.end()) {
                iter++;
            }
        }

    }
}

#endif //SMOLFORMAT_FORMATTING_H
