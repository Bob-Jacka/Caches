#ifndef LRU_BASECACHE_HPP
#define LRU_BASECACHE_HPP

/**
 * Namespace for different cache types
 */
namespace Cache {
    class BaseCache {
    public:
        ~BaseCache() = default;

        /**
         * Recache objects in cache object
         */
        virtual void recache() const = 0;

        /**
         * Count how many elements in cache.
         * @return elements count.
         */
        [[nodiscard]] virtual int element_count() const = 0;
    };
}

#endif
