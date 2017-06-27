#pragma once
namespace util
{
    template <typename T> class Collection
    {
    protected:
        // variables
        unsigned int m_size;
        Iterator<T> * m_head;
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
            if (this->m_head != nullptr) this->m_head->prev() = temp;
            // set head to the temporary node
            this->m_head = temp;
            this->m_size++;
            // value added
            return true;
        };
        inline bool add(const Collection & other) { for (Iterator<T> * i = other; i; i = i->next()) this->add((T&)i); return true; };
        inline bool remove(const T & value)
        {
            // iterate through collection
            for (Iterator<T> * i = this->m_head; i != nullptr;)
            {
                // check iterator value
                if ((T&)*i == value)
                {
                    // store i in temporary
                    Iterator<T> * temp = i;
                    // relink the i iterator
                    if (this->m_size-- == 0) this->m_head = nullptr;
                    if (i->next() != nullptr) i->next()->prev() = i->prev();
                    if (i->next() != nullptr) i->next()->prev() = i->prev();
                    i = i->next();
                    // delete the temporary iterator
                    delete temp;
                }
                else i = i->next();
            }
            // failed to remove
            return false;

            //Iterator<T> * temp1 = this->m_head;
            //// iterate through each
            //while (true)
            //{
            //    // check if empty
            //    if (temp1 == nullptr) break;
            //    // check temp1 value
            //    if ((T&)*temp1 == value)
            //    {
            //        // store temp1 in temp2
            //        Iterator<T> * temp2 = temp1;
            //        // relink temp1 iterator
            //        if (this->m_size == 0) this->m_head = nullptr;
            //        if (temp1->next() != nullptr) temp1->next()->prev() = temp1->prev();
            //        if (temp1->prev() != nullptr) temp1->prev()->next() = temp1->next();
            //        temp1 = temp1->next();
            //        // delete temp2
            //        this->m_size--;
            //        delete temp2;
            //        temp2 = nullptr;
            //        return true;
            //    }
            //    // go to next iterator
            //    temp1 = temp1->next();
            //}
            //// failed to delete
            //return false;
            //for (Iterator<T> * i = this->m_head; i; i = i->next())
            //{
            //    // check if found
            //    if ((T&)*i == value)
            //    {
            //        // store i in temporary
            //        Iterator<T> * temp = i;
            //        // relink the iterators
            //        if (i->next() != nullptr) i->next()->prev() = i->prev();
            //        if (i->prev() != nullptr) i->prev()->next() = i->next();
            //        // delete the temporary
            //        temp = temp->next();
            //        delete temp->prev();
            //        // value deleted
            //        return true;
            //    }
            //}
            // value not found
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
        operator Iterator<T>() { return *this->m_head; };
        operator Iterator<T>*() { return this->m_head; };
    };
}