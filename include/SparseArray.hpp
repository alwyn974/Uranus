//
// Created by nicol on 09/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_SPARSEARRAY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_SPARSEARRAY_HPP


#include <vector>
#include <optional>


template <typename Component> // You can also mirror the definition of std :: vector , that takes an additional allocator .
class sparse_array {
public :
    using value_type = std::optional<Component>;
    using reference_type = value_type &;
    using const_reference_type = value_type const &;
    using container_t = std::vector<value_type>; // optionally add your allocator template here .
    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
public :
    sparse_array() = default; // You can add more constructors .
    sparse_array(sparse_array const &) = default; // copy constructor
    sparse_array(sparse_array &&) noexcept = default; // move constructor
    ~ sparse_array() = default;

    sparse_array &operator=(sparse_array const &); // copy assignment operator
    sparse_array &operator=(sparse_array &&) noexcept; // move assignment operator
    reference_type operator[](std::size_t idx);

    const_reference_type operator[](std::size_t idx) const;

    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    iterator end();

    const_iterator end() const;

    const_iterator cend() const;

    size_type size() const;

    reference_type insert_at(size_type pos, Component const &);

    reference_type insert_at(size_type pos, Component &&);

    template<class ... Params>
    reference_type emplace_at(size_type pos, Params &&...); // optional
    void erase(size_type pos);

    size_type get_index(value_type const &) const;
private :
    container_t _data;
};

template<typename Component>
sparse_array<Component> &sparse_array<Component>::operator=(sparse_array<Component> const &other) {
    _data = other._data;
    return *this;
}

template<typename Component>
sparse_array<Component> &sparse_array<Component>::operator=(sparse_array<Component> &&other) noexcept {
    _data = std::move(other._data);
    return *this;
}

template<typename Component>
typename sparse_array<Component>::reference_type sparse_array<Component>::operator[](std::size_t idx) {
    if (idx >= _data.size())
        _data.resize(idx + 1);
    return _data[idx];
}

template<typename Component>
typename sparse_array<Component>::const_reference_type sparse_array<Component>::operator[](std::size_t idx) const {
    if (idx >= _data.size())
        return std::nullopt;
    return _data[idx];
}

template<typename Component>
typename sparse_array<Component>::iterator sparse_array<Component>::begin() {
    return _data.begin();
}

template<typename Component>
typename sparse_array<Component>::const_iterator sparse_array<Component>::begin() const {
    return _data.begin();
}

template<typename Component>
typename sparse_array<Component>::const_iterator sparse_array<Component>::cbegin() const {
    return _data.cbegin();
}

template<typename Component>
typename sparse_array<Component>::iterator sparse_array<Component>::end() {
    return _data.end();
}

template<typename Component>
typename sparse_array<Component>::const_iterator sparse_array<Component>::end() const {
    return _data.end();
}

template<typename Component>
typename sparse_array<Component>::const_iterator sparse_array<Component>::cend() const {
    return _data.cend();
}

template<typename Component>
typename sparse_array<Component>::size_type sparse_array<Component>::size() const {
    return _data.size();
}

template<typename Component>
typename sparse_array<Component>::reference_type sparse_array<Component>::insert_at(size_type pos, Component const &component) {
    if (pos >= _data.size())
        _data.resize(pos + 1);
    _data[pos] = component;
    return _data[pos];
}

template<typename Component>
typename sparse_array<Component>::reference_type sparse_array<Component>::insert_at(size_type pos, Component &&component) {
    if (pos >= _data.size())
        _data.resize(pos + 1);
    _data[pos] = std::move(component);
    return _data[pos];
}

template<typename Component>
template<class ... Params>
typename sparse_array<Component>::reference_type sparse_array<Component>::emplace_at(size_type pos, Params &&...params) {
    if (pos >= _data.size())
        _data.resize(pos + 1);
    _data[pos] = std::nullopt;
    _data[pos] = Component(std::forward<Params>(params)...);
    return _data[pos];
}

template<typename Component>
void sparse_array<Component>::erase(size_type pos) {
    if (pos >= _data.size())
        return;
    _data[pos] = std::nullopt;
}

template<typename Component>
typename sparse_array<Component>::size_type sparse_array<Component>::get_index(value_type const &value) const {
    for (size_type i = 0; i < _data.size(); i++) {
        if (std::addressof(_data[i]) == std::addressof(value))
            return i;
    }
    return -1;
}

#endif //B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_SPARSEARRAY_HPP
