#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::BasicType(
    const BasicType::Type value
)
    : m_value{ ::std::move(value) }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Setters getters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::set(
    const BasicType::Type value
) -> BasicType::ParentType&
{
    m_value = ::std::move(value);

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::get() const
    -> const BasicType::Type&
{
    return m_value;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Comparisons
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator<=>(
    BasicType::Type& rhs
) const
    -> ::std::partial_ordering
{
    return this->m_value <=> rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator<=>(
    const BasicType& rhs
) const
    -> ::std::partial_ordering
{
    return this->m_value <=> rhs.m_value;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator=(
    BasicType::Type& rhs
) -> BasicType::ParentType&
{
    this->set(rhs);

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator+(
    BasicType::Type& rhs
) -> BasicType::Type
{
    return m_value + rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator+=(
    BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value += rhs;

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator-(
    BasicType::Type& rhs
) -> BasicType::Type
{
    return m_value - rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator-=(
    BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value -= rhs;

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*(
    BasicType::Type& rhs
) -> BasicType::Type
{
    return m_value * rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*=(
    BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value *= rhs;

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator/(
    BasicType::Type& rhs
) -> BasicType::Type
{
    return m_value / rhs;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator/=(
    BasicType::Type& rhs
) -> BasicType::ParentType&
{
    m_value /= rhs;

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    // set the changed flag if it exists
    if constexpr (requires { parent.setChangedFlag(true); }) {
        parent.setChangedFlag(true);
    }
    return parent;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator const BasicType::Type&() const
{
    return m_value;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
    , bool hasChangedFlag
> auto ::xrn::engine::component::detail::BasicType<T, U, hasChangedFlag>::operator*() const
    -> const BasicType::Type&
{
    return m_value;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> ::xrn::engine::component::detail::BasicType<T, U, true>::BasicType(
    BasicType::Type value
)
    : BasicType<T, U, false>{ ::std::move(value) }
    , m_isChanged{ true }
{}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Changed flag
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> auto ::xrn::engine::component::detail::BasicType<T, U, true>::isChanged() const
    -> bool
{
    return m_isChanged;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> void ::xrn::engine::component::detail::BasicType<T, U, true>::setChangedFlag(
    bool value // = true
)
{
    m_isChanged = value;
}

///////////////////////////////////////////////////////////////////////////
template <
    typename T
    , typename U
> auto ::xrn::engine::component::detail::BasicType<T, U, true>::resetChangedFlag()
    -> BasicType::ParentType&
{
    m_isChanged = false;

    auto& parent{ tatic_cast<BasicType::ParentType>(*this) };
    return parent;
}
