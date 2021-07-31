/**
 *  @author:    Qsionc
 *  @date:      30/07/2021
 *  @file:      format.h
 *  @brief:     Class format definition file
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_FORMAT_CLASS_H
#define SMOLFORMAT_FORMAT_CLASS_H

#include <detail/to_string.h>
#include <array>
#include "any_type_const.h"

/**
 * @brief small namespace ;)
 */
namespace smol {
    /**
     * @brief format template class that holds formatted string
     * @details Class is meant to be created as temporary object and either passed to std::ostream based class,
     * or to be implicitly converted to std::string through get() method or operator std::string const&().
     * @tparam Args parameter pack passed during construction of format object
     */
    template<class... Args>
    class format {
    private:
        /**
         * @brief held format string, formatted during object construction
         */
        mutable std::string format_;
        /**
         * @brief const c-style array of size equal to sizeof parameter pack holding list of passed arguments
         * @details Array can consist of number of elements different to arguments to be parsed by class during construction
         */
        const std::array<std::unique_ptr<any_base>, sizeof...(Args)> args_;
    public:
        /**
         * @brief basic constructor of format class which parses the list of arguments and formats input string respectively
         * @example
         * @code{.cpp}
         * smol::format("{} {}", 42, "string"); // will produce "42 string"
         * @endcode
         * @code{.cpp}
         * smol::format("{1} {}", 42, "string"); // will produce "string string"
         * @endcode
         * @details During construction of object, the list of arguments is automatically parsed and put respectively at
         * chosen positions.\n
         * 1. If there is no index number in parenthesis, respectful parameter will be put. If there is none, place will be replaced with empty string\n
         * 2. Indexes must be in range: [0, N-1] where N is number of parameters passed @n
         * @param _format string to be formatted
         * @param _args variadic list of parameters passed to const array of arguments held by object
         */
        explicit format(std::string _format, Args ... _args);

        /**
         * @brief get formatted string
         * @return const reference to formatted string
         */
        [[nodiscard]] std::string const& get() const;

        /**
         * @brief convert object implicitly to std::string
         * @return const reference to formatted string
         */
        operator std::string const&() const;
    };

    /**
     * @brief Convenience operator<< overload for std::ostream to easily put formatted string to target std::ostream
     * @tparam Args template parameter pack
     * @param _ostream reference to target std::ostream
     * @param _format cont reference to target smol::format<Args...> object
     * @return reference to _ostream (operator chaining)
     */
    template<class ... Args>
    std::ostream& operator<<(std::ostream& _ostream, format<Args...> const& _format);
}

#endif //SMOLFORMAT_FORMAT_CLASS_H
