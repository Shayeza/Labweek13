
#ifndef LAB_WEEK_13_SINGLYLINKEDLIST_HPP
#define LAB_WEEK_13_SINGLYLINKEDLIST_HPP

#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace ais1002 {

    template<typename T>
    class SinglyLinkedList {

    public:
        [[nodiscard]] size_t size() const {
            return size_;
        }

        T &operator[](unsigned int index) {
            if (index >= size_) {
                throw std::runtime_error("Index too large: " + std::to_string(index));
            }

            node<T> *current = head_;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            return current->value;
        }

        void insert(const T &value, unsigned int index) {
            if (index > size_) {
                throw std::runtime_error("Index too large: " + std::to_string(index));
            }

            node<T> *current = head_;
            node<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }

            node<T> *insert = new node(value);
            insert->next = current;
            if (!prev) {
                head_ = insert;
            } else {
                prev->next = insert;
            }

            size_++;
        }

        void addFirst(const T &value) {
            insert(value, 0);
        }

        void addLast(const T &value) {
            insert(value, size_);
        }

        T remove(unsigned int index) {
            if (index >= size_) {
                throw std::runtime_error("Index too large: " + std::to_string(index));
            }

            node<T> *current = head_;
            node<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }

            if (!prev) {
                head_ = current->next;
            } else {
                prev->next = current->next;
            }

            size_--;

            T data = std::move(current->value);
            delete (current);

            return data;
        }

        T removeFirst() {
            return remove(0);
        }

        T removeLast() {
            return remove(size_ - 1);
        }

        friend std::ostream &operator<<(std::ostream &os, const SinglyLinkedList<T> &v) {
            os << "[";
            node<T> *current = v.head_;
            while (current != nullptr) {
                os << current->value;
                if (current->next) {
                    os << " ,";
                }
                current = current->next;
            }
            os << "]";
            return os;
        }

        ~SinglyLinkedList() {
            for (int i = size_ - 1; i >= 0; i--) {
                remove(i);
            }
        }

    private:
        template<class Type>
        struct node {

            Type value;
            node<Type> *next = nullptr;

            explicit node(const Type &value) : value(value) {}
        };

        size_t size_ = 0;
        node<T> *head_ = nullptr;
    };

}// namespace ais1002


#endif//LAB_WEEK_13_SINGLYLINKEDLIST_HPP
