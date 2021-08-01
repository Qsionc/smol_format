/**
 *  @author:    Qsionc
 *  @date:      31/07/2021
 *  @file:      any_type_class_implementation.h
 *  @brief:     Implementation file for any_type_const class
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_ANY_TYPE_CONST_IMPLEMENTATION_H
#define SMOLFORMAT_ANY_TYPE_CONST_IMPLEMENTATION_H

#include "any_type_const.h"
#include "detail/to_string.h"

namespace smol {
    template<class T>
    any_type_const<T>::any_type_const(T&& _t) : value_(std::forward<T>(_t)) {}

    template<class T>
    std::string any_type_const<T>::get() const {
        return smol::detail::to_string(value_);
    }
}
#endif //SMOLFORMAT_ANY_TYPE_CONST_IMPLEMENTATION_H
