#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class a_type> class Node
{
public:
    Node();
    Node(a_type data);
    Node(a_type data, Node<a_type>* pNext);
    Node(a_type data[], int n);
    Node(const Node& rOther);

    Node* addToEnd(a_type data)
    {
        Node* pNew = new Node(data);
        Node* pEnd = this;
        while (pEnd->m_pNext)
            pEnd = pEnd->m_pNext;

        pEnd->m_pNext = pNew;
        return pNew;
    }

    Node* find(a_type data)
    {
        Node* pNode = this;
        while (pNode)
        {
            if (pNode->m_data == data)
            {
                return pNode;
            }
            pNode = pNode->m_pNext;
        }
        return 0;
    }

    Node* operator[](int index)
    {
        Node<a_type>* pNode = this;
        for (int i = 0; i < index; i++)
        {
            pNode = pNode->m_pNext;
            if (i == index)
            {
                break;
            }
        }
        return pNode;
    }

    // reverse in place
    Node* reverse()
    {
        Node<a_type>* pNewOrder = 0;
        Node<a_type>* pNode = this;
        while (pNode)
        {
            Node<a_type>* pNext = pNode->m_pNext;
            pNode->m_pNext = pNewOrder;
            pNewOrder = pNode;
            pNode = pNext;
        }
        return pNewOrder;
    }

    Node* duplicate()
    {
        Node<a_type>* pNewNode = new Node<a_type>(*this);
        Node<a_type>* pNewHead = pNewNode;
        Node<a_type>* pNode = this;
        while (pNode)
        {
            if (pNode->m_pNext)
            {
                pNewNode = new Node<a_type>(*pNode->m_pNext);
                pNode->m_pNext = pNewNode;
            }
            pNode = pNode->m_pNext;
        }
        return pNewHead;
    }

    void printList();

    // keep those public for simplicity
    a_type m_data;
    Node<a_type>* m_pNext;
};

template<class a_type>
Node<a_type>::Node(a_type data):
    m_data(data),
    m_pNext(0)
{
}

template<class a_type>
Node<a_type>::Node(const Node<a_type>& rOther):
    m_data(rOther.m_data),
    m_pNext(rOther.m_pNext)
{
}

template<class a_type>
Node<a_type>::Node(a_type data, Node<a_type>* pNext):
    m_data(data),
    m_pNext(pNext)
{
}

template<class a_type>
Node<a_type>::Node():
    m_data(a_type()),
    m_pNext(0)
{
}

template<class a_type>
Node<a_type>::Node(a_type data[], int n):
    m_data(0),
    m_pNext(0)
{
    m_data = data[0];
    Node<a_type>* pNode = this;
    for (int i = 1; i < n; i++)
    {
        Node<a_type>* pNew = new Node<a_type>(data[i]);
        pNode->m_pNext = pNew;
        pNode = pNew;
    }
}

template<class a_type>
void Node<a_type>::printList()
{
    Node<a_type> *pNode = this;
    while (pNode)
    {
        std::cout << "Node: " << pNode->m_data << std::endl;
        pNode = pNode->m_pNext;
    }
}

void testLinkedList();

#endif
