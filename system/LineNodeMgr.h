#pragma once

#include <basis/seadTypes.h>

template <typename T>
class LineNodeMgr
{
public:
    struct Node
    {
        Node(T* obj_)
            : obj(obj_)
            , next(nullptr)
            , prev(nullptr)
        {
        }

        T* obj;
        Node* next;
        Node* prev;
    };
    static_assert(sizeof(Node) == 0xC);

public:
    LineNodeMgr()
        : mHead(nullptr)
        , mTail(nullptr)
    {
    }

    Node* front() const
    {
        return mHead;
    }

    Node* back() const
    {
        return mTail;
    }

    bool contains(const Node* node) const
    {
        if (node == nullptr)
            return false;

        return node->next != nullptr || node->prev != nullptr || node == mHead;
    }

    virtual void insertAfter(Node* node, Node* basis)
    {
        if (basis == nullptr)
        {
            pushFront(node);
            return;
        }

        if (node == nullptr)
            return;

        node->next = basis->next;
        node->prev = basis;
        basis->next = node;

        if (node->next != nullptr)
            node->next->prev = node;

        if (node->next == nullptr)
            mTail = node;
    }

    virtual void erase(Node* node)
    {
        if (node == nullptr)
            return;

        if (node->prev != nullptr)
            node->prev->next = node->next;

        else if (node == mHead)
            mHead = node->next;

        if (node->next != nullptr)
            node->next->prev = node->prev;

        else if (node == mTail)
            mTail = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }

    virtual void pushBack(Node* node)
    {
        if (node == nullptr)
            return;

        if (mTail != nullptr)
        {
            mTail->next = node;
            node->prev = mTail;
        }
        else
        {
            mHead = node;
        }

        mTail = node;
    }

    virtual void pushFront(Node* node)
    {
        if (node == nullptr)
            return;

        if (mHead != nullptr)
        {
            mHead->prev = node;
            node->next = mHead;
        }
        else
        {
            mTail = node;
        }

        mHead = node;
    }

    virtual void clear()
    {
        while (mHead != nullptr)
            erase(mHead);
    }

protected:
    Node* mHead;
    Node* mTail;
};
static_assert(sizeof(LineNodeMgr<void>) == 0xC);
