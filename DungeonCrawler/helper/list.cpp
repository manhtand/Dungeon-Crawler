#include "list.h"

List::List()
{

}

void List::push_back(Level* m_level)
{
    Element* tmp = new Element{nullptr, m_level, nullptr};

    if (empty())
    {
        start = tmp;
        m_size++;
        return;
    }

    Element* current = start;
    while (current -> next != nullptr)
    {
        current = current -> next;
    }
    current -> next = tmp;
    tmp -> before = current;
    m_size++;
}

void List::push_front(Level* level)
{
    Element* tmp = new Element{nullptr, level, nullptr};

    if (empty())
    {
        start = tmp;
        m_size++;
        return;
    }

    start -> before = tmp;
    tmp -> next = start;
    start = tmp;
    m_size++;
}

void List::pop_back()
{
    if (start == nullptr)
    {
        throw std::invalid_argument("Liste ist bereits leer");
    }

    if (start -> next == nullptr)
    {
        delete start;
        start = nullptr;
        m_size = 0;
        return;
    }

    Element* current = start;
    while (current -> next -> next != nullptr)
    {
        current = current -> next;
    }
    delete current -> next;
    current -> next = nullptr;
    m_size--;
}

void List::pop_front()
{
    if (start == nullptr)
    {
        throw std::invalid_argument("Liste ist bereits leer");
    }

    if (start -> next == nullptr)
    {
        delete start;
        start = nullptr;
        m_size = 0;
        return;
    }

    Element* current = start -> next;
    delete start;
    current -> before = nullptr;
    start = current;
    m_size--;
}

bool List::empty()
{
    return m_size == 0;
}

int List::size()
{
    return m_size;
}

void List::remove(Level* m_level)
{
    if (empty())
    {
        throw std::invalid_argument("Liste ist leer");
        return;
    }

    if (start -> next == nullptr)
    {
        if (start -> data == m_level)
        {
            delete start;
            start = nullptr;
            m_size = 0;
        }
    }

    Element* current = start;
    while (current -> next != nullptr)
    {
        auto tmp = current -> next;
        if (current -> data == m_level)
        {
            current -> before -> next = current -> next;
            current -> next -> before = current -> before;
            m_size--;
            delete current;
        }
        current = tmp;
    }
}

List::iterator List::begin()
{
    if (empty())
    {
        return iterator(nullptr);
    }
    return iterator(start);
}

List::iterator List::end()
{
    throw std::invalid_argument("Fehler");
}

Level* List::getNext(Level* p_level)
{
    Element* tmpCurrent = start;
    while (tmpCurrent -> data != p_level)
    {
        tmpCurrent = tmpCurrent -> next;
    }

    if (tmpCurrent -> next == nullptr)
    {
        return nullptr;
    }
    return tmpCurrent -> next -> data;
}

Level* List::getBefore(Level* p_level)
{
    Element* tmpCurrent = start;
    while (tmpCurrent -> data != p_level)
    {
        tmpCurrent = tmpCurrent -> next;
    }

    if (tmpCurrent -> before == nullptr)
    {
        return nullptr;
    }
    return tmpCurrent -> before -> data;
}
