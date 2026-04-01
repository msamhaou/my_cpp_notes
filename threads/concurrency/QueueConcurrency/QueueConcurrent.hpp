#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>


template <typename T>
class QueueConcurrent {
private:
    std::mutex _mutex;
    std::condition_variable not_empty;
    std::condition_variable not_full;
    std::atomic<bool> done;
    size_t max_size;
public:
    std::queue<T> _queue;
    QueueConcurrent();
    bool add(T element);
    bool remove(T element);
    size_t size();
};