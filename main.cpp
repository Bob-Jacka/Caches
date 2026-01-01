#include "core/entities/LruCache.hpp"

int main() {
    auto lru_cache = Cache::LRU_cache<std::string, int, 100>();
    std::string tmp_object = "tmp_object_to_cache";
    for (int i = 0; i < 99; ++i) {
        lru_cache.add_cache_object(tmp_object + std::to_string(i));
    }
}
