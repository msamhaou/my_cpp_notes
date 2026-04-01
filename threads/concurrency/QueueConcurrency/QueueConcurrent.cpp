
#include <QueueConcurrent.hpp>

QueueConcurrent::QueueConcurrent(): max_size(500000), done(false){
}

bool QueueConcurrent::add(T element){
    std::unique_lock<std::mutex> lock(_mutex);
    not_full.wait(lock, [this]{
        return this->_queue.size() < max_size || done;
    })

    if (done)
        return false;
    this->_queue.push(std::move(element));
    not_empty.notify_one();
    return true;
}

std::optional<T> QueueConcurrent::bool(T element){
    std::unique_lock<std::mutex> lock(_mutex);
    not_empty.wait(lock, [this]{
        return this->_queue.size() > 0 || done;
    })
    if (this_queue.size == 0) return std::nullopt;
    T item = std::move(this->_queue.front());
    this->_queue.pop()
    not_full.notify_one();
    return item;
}

size_t QueueConcurrent::size(){
    std::unique_lock<_mutex> lock(_mutex);
    return this->_queue.size();
}



