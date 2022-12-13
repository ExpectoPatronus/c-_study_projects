#ifndef SRC_S21_MULTISET_H_
#define SRC_S21_MULTISET_H_
#include "s21_set.h"

namespace s21 {
template <class K>
class multiset : public set<K> {
 public:
    /* --БЛОК ПЕРЕОПРЕДЕЛЕНИЯ ТИПОВ-- */
    using key_type = K;
    using value_type = K;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = typename s21::set<K>::set_iter;
    using const_iterator = typename s21::set<K>::set_iter;
    using size_type = size_t;
    using iter_pair = std::pair<iterator, iterator>;
    /* ----------------------------------------------- */

 protected:
    bool insert_check(K value, K key) override;

 public:
    /* --БЛОК КОНСТРУКТОРОВ И ДЕСТРУКТОРОВ-- */
    multiset();
    explicit multiset(std::initializer_list<value_type> const &items);
    multiset(const multiset &s);
    multiset(multiset &&s);
    ~multiset();
    multiset& operator=(multiset &&s);
    /* ----------------------------------------------- */

    /* --БЛОК ФУНКЦИЙ ДЛЯ MULTISET-- */
    iterator insert(const_reference value);
    void merge(multiset& other);
    size_type count(const_reference key);
    iter_pair equal_range(const_reference key);
    iterator lower_bound(const_reference key);
    iterator upper_bound(const_reference key);
    /* ----------------------------------------------- */
};
}  // namespace s21

#endif  // SRC_S21_MULTISET_H_
