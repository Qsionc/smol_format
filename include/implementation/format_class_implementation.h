/**
 *  @author:    Qsionc
 *  @date:      30/07/2021
 *  @file:      format_class_implementation.h
 *  @brief:     Implementation file for class format
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_FORMAT_CLASS_IMPLEMENTATION_H
#define SMOLFORMAT_FORMAT_CLASS_IMPLEMENTATION_H

#include "format_class.h"
#include "detail/formatting.h"
#include "any_type_const_implementation.h"

namespace smol {
    template<class... Args>
    smol::format<Args...>::format(std::string _format, Args ... _args) :
            format_(std::move(_format)),
            args_{std::make_unique<any_type_const<Args>>(std::forward<Args>(_args))...} {
        detail::parse(format_, args_);
    }

    template<class... Args>
    std::string const& smol::format<Args...>::get() const {
        return format_;
    }

    template<class... Args>
    format<Args...>::operator std::string const&() const {
        return get();
    }

    template<class ... Args>
    std::ostream& operator<<(std::ostream& _ostream, format<Args...> const& _format) {
        _ostream << _format.get();
        return _ostream;
    }
}

#endif //SMOLFORMAT_FORMAT_CLASS_IMPLEMENTATION_H
