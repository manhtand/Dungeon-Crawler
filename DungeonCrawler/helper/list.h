#ifndef LIST_H
#define LIST_H

#include <level.h>

class List
{
private:
    struct Element
    {
        Element* before;
        Level* data;
        Element* next;
    };

    Element* start = nullptr;
    int m_size = 0;

    class iterator
        {
        public:
            iterator(Element* p_current) : current(p_current)
            {}

            iterator& operator++()
            {
                Element* tmpElement = current -> next;
                if (tmpElement == nullptr)
                {
                    throw invalid_argument("Fehler");
                }
                else
                {
                    setCurrent(tmpElement);
                }
                return *this;
            }

            iterator& operator--()
            {
                Element* tmpElement = current -> before;
                if (tmpElement == nullptr)
                {
                    throw invalid_argument("Fehler");
                }
                else
                {
                    setCurrent(tmpElement);
                }
                return *this;
            }

            Level*& operator*()
            {
                Level* tmpLevel = current -> data;
                if (tmpLevel == nullptr)
                {
                    throw std::invalid_argument("Fehler");
                }
                else
                {
                    return current -> data;
                }
            }

            bool operator==(const iterator& rhs)
            {
                return rhs.current->data == current -> data;
            }

            bool operator!=(const iterator& rhs)
            {
                return rhs.current->data != current->data;
            }

        private:
            Element* current;
            void setCurrent(Element* p_element)
            {
                current = p_element;
            }
        };

    public:
        List();

        void push_back(Level*);
        void push_front(Level*);

        void pop_back();
        void pop_front();

        bool empty();
        int size();

        void remove(Level*);

        iterator begin();
        iterator end();

        Level* getNext(Level*);
        Level* getBefore(Level*);
};

#endif // LIST_H
