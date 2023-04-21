#pragma once

namespace xrn::engine::component::detail {

///////////////////////////////////////////////////////////////////////////
/// \brief Basic type to abstract the basic feature of a regular type
/// component
/// \ingroup component
///
/// \include BasicType.hpp <xrn/Engine/Component/Detail/BasicType.hpp>
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag = false
> class BasicType {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    using Type = T;
    using ParentType = U;



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    BasicType(
        BasicType::Type value
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Setters getters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto set(
        BasicType::Type value
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto get() const
        -> const BasicType::Type&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Comparisons
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator<=>(
        BasicType::Type& rhs
    ) const
        -> ::std::partial_ordering;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator<=>(
        const BasicType& rhs
    ) const
        -> ::std::partial_ordering;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        BasicType::Type& rhs
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator+(
        BasicType::Type& rhs
    ) const -> BasicType::Type;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator+=(
        BasicType::Type& rhs
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator-(
        BasicType::Type& rhs
    ) const -> BasicType::Type;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator-=(
        BasicType::Type& rhs
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator*(
        BasicType::Type& rhs
    ) const -> BasicType::Type;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator*=(
        BasicType::Type& rhs
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator/(
        BasicType::Type& rhs
    ) const -> BasicType::Type;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator/=(
        BasicType::Type& rhs
    ) -> BasicType::ParentType&;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator const BasicType::Type&() const;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator*() const
        -> const BasicType::Type&;



protected:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Members
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    BasicType::Type m_value;

};



///////////////////////////////////////////////////////////////////////////
/// \brief Adds the isChanged flag
/// \ingroup component
///
/// \include BasicType.hpp <xrn/Engine/Component/Detail/BasicType.hpp>
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> class BasicType<T, U, true>
    : public BasicType<T, U, false>
{

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    using Type = typename BasicType<T, U, false>::Type;
    using ParentType = typename BasicType<T, U, false>::ParentType;



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    BasicType(
        BasicType::Type value
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Changed flag
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto isChanged() const
        -> bool;

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setChangedFlag(
        bool value = true
    );

    ///////////////////////////////////////////////////////////////////////////
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto resetChangedFlag()
        -> BasicType::ParentType&;



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Members
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    bool m_isChanged{ true };

};

} // namespace xrn::engine::component::detail

///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Engine/Component/Detail/BasicType.impl.hpp>
