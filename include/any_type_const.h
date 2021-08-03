/**
 *  @author:    Qsionc
 *  @date:      31/07/2021
 *  @file:      any_type_const.h
 *  @brief:     Class any_type_cont definition
 *  @Copyright: This software is free to use and distribute free of charge.
 */

#ifndef SMOLFORMAT_ANY_TYPE_CONST_H
#define SMOLFORMAT_ANY_TYPE_CONST_H

#include <string>

/**
 * @brief small namespace ;)
 */
namespace smol {
    /**
     * @brief Class any_base, base class for any_type_const
     * @details Class was created to create uniform interface for universal type holder when parsing argument pack
     */
    class any_base {
    public:
        /**
         * @brief get current value as string
         * @return help value as new string object
         */
        [[nodiscard]] virtual std::string get() const = 0;

        /**
         * @brief virtual default destructor
         */
        virtual ~any_base() = default;
    };

    /**
     * @brief any_type_const is class that holds const value of type T
     * @details This class was created to help parse parameter pack passed to format class
     * and wrap any type passed in simple object that allows for fast to std::string conversion
     * @tparam T - type of held value
     */
    template<class T>
    class any_type_const : public any_base {
    private:
        /**
         * @brief const value of type T - single parameter from parameter pack
         */
        T const value_;
    public:
        /**
         * @brief base constructor requires value of type T.
         * @param _t universal reference to value of type T to be stored as cont T
         */
        explicit any_type_const(T&& _t);

        /**
         * @brief get current value as string
         * @return help value as new string object
         */
        [[nodiscard]] std::string get() const override;
    };
}

#endif //SMOLFORMAT_ANY_TYPE_CONST_H
