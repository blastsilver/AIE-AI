#pragma once
namespace util
{
    template <typename T> class Collection
    {
    protected:
        // variables
        unsigned int m_size;
        Iterator<T> * m_head;
        Iterator<T> * m_tail;
    public:
        // public defaults
        inline Collection() { this->m_head = nullptr; this->m_size = 0; };
        inline ~Collection() {
            while (true)
            {
                // check if next is empty
                if (this->m_head->next() == nullptr) break;
                // set head to next
                this->m_head = this->m_head->next();
                // delete previous
                delete this->m_head->prev();
            }
            // delete head
            delete this->m_head;
            this->m_head = nullptr;
        }
        inline Collection(const T * buffer, const unsigned int size) : Collection() { for (unsigned int i = 0; i < size; i++) this->add(buffer[i]); };
        // public functions
        inline bool add(const T & value)
        {
            // create temporary node
            Iterator<T> * temp = new Iterator<T>(value, m_head);
            // check if head is not empty
            if (this->m_size != 0) this->m_head->prev() = temp;
            // set head to the temporary node
            this->m_head = temp;
            this->m_size++;
            // value added
            return true;
        };
        inline bool add(const Collection & other) { for (Iterator<T> * i = other; i; i = i->next()) this->add((T&)*i); return true; };
        inline bool remove(const T & value)
        {
            // check if empty
            if (this->m_size == 0) return false;
            // iterate through collection
            for (Iterator<T> * i = this->m_head; i != nullptr; i = i->next())
            {
                // check iterator value
                if ((T&)*i == value)
                {
                    this->m_size--;
                    IteratorRemove(i);
                    return true;
                }
            }
            // failed to remove
            return false;
        }
        inline bool remove(const Collection & other)
        {
            bool result = false;
            for (Iterator<T> * i = other.m_head; i; i = i->next())
            {
                result |= this->remove((T&)*i);
            }
            return result;
        }
        // public operator overloading
        inline operator Iterator<T>() { return *this->m_head; };
        inline operator Iterator<T>*() { return this->m_head; };
    protected:
        // protected functions
        //inline const void IteratorInsertL(Iterator<T> * & node, const T & value) { IteratorInsertLinkL(other, new Iterator<T>(value)); if (this->m_size++ == 0) this->m_tail = other->prev(); };
        //inline const void IteratorInsertR(Iterator<T> * & node, const T & value) { IteratorInsertLinkR(other, new Iterator<T>(value)); if (this->m_size++ == 0) this->m_head = other->next(); };
        //inline const void IteratorInsertLinkL(Iterator<T> * & node, Iterator<T> * & insert) { if (node->prev() != nullptr) node->prev()->next() = insert; node->prev() = insert; insert->next() = node; };
        //inline const void IteratorInsertLinkR(Iterator<T> * & node, Iterator<T> * & insert) { if (node->next() != nullptr) node->next()->prev() = insert; node->next() = insert; insert->prev() = node; };
        inline const void IteratorRemove(Iterator<T> * & node) { Iterator<T> * temp = node; IteratorRemoveLink(node); delete temp; };
        inline const void IteratorRemoveLink(Iterator<T> * & node) { IteratorRelinkL(node); IteratorRelinkR(node); node = node->next(); };
        inline const void IteratorRemoveLinkL(Iterator<T> * & node) { if (node->prev() != nullptr) node->prev()->next() = node->next(); else this->m_head = node->next(); };
        inline const void IteratorRemoveLinkR(Iterator<T> * & node) { if (node->next() != nullptr) node->next()->prev() = node->prev(); else this->m_tail = node->prev(); };
    };
}