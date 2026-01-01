#ifndef LRU_LRUCACHE_HPP
#define LRU_LRUCACHE_HPP

#include <array>
#include <tuple>
#include <chrono>
#include <algorithm>
#include "BaseCache.hpp"

using Add_time = std::chrono::steady_clock::time_point; ///time, when add object to cache

namespace Cache {
    /**
     * Weird LRU cache realization with array.
     * @tparam T generic type of elements
     * @tparam K generic key type
     * @tparam CACHE_SIZE size of cache
     */
    template<typename T, typename K, int CACHE_SIZE = 100>
    class LRU_cache final : public BaseCache {
    private:
        std::array<std::tuple<K, T, Add_time>, CACHE_SIZE> data; ///inner cache data
        int elems_count;

        void recache() const override;

    public:
        LRU_cache();

        ~LRU_cache() = default;

        LRU_cache &operator=(LRU_cache rhs);

        void add_cache_object(T object);

        T get_element(K key) const;

        [[nodiscard]] int element_count() const override;
    };

    template<typename T, typename K, int CACHE_SIZE>
    int LRU_cache<T, K, CACHE_SIZE>::element_count() const {
        return elems_count;
    }

    template<typename T, typename K, int CACHE_SIZE>
    LRU_cache<T, K, CACHE_SIZE> &LRU_cache<T, K, CACHE_SIZE>::operator=(LRU_cache rhs) {
        this->data = rhs.data;
        this->elems_count = rhs.elems_count;
        return *this;
    }

    template<typename T, typename K, int CACHE_SIZE>
    LRU_cache<T, K, CACHE_SIZE>::LRU_cache() {
        elems_count = 0;
        for (int i = 0; i < CACHE_SIZE - 1; ++i) {
            this->data[i] = std::array<std::tuple<T, K, Add_time>, CACHE_SIZE>();
        }
    }

    template<typename T, typename K, int CACHE_SIZE>
    void LRU_cache<T, K, CACHE_SIZE>::add_cache_object(T object) {
        this->data[] = {{, object, std::chrono::steady_clock::now()}};
        ++elems_count;
    }

    template<typename T, typename K, int CACHE_SIZE>
    T LRU_cache<T, K, CACHE_SIZE>::get_element(K key) const {
        std::find_first_of(data.begin(), data.end(), [&](K algo_key) {
            return algo_key == key;
        });
    }

    template<typename T, typename K, int CACHE_SIZE>
    void LRU_cache<T, K, CACHE_SIZE>::recache() const {
//
    }
}

#endif
