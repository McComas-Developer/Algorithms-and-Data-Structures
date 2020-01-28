// Author: Michael McComas
// Project 7
// File: priorityqueue.h
// CSCI 3110-001
// Due: 4/15/19
// Remarks: Binary Heap Class Template

#include <iostream>
#include <vector>

using namespace std;

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

// Class Template to compare Max Priority
template<typename Obj>
class MaxPriority{
    public:
        bool compare(const Obj& lhs, const Obj& rhs ) const{
            return lhs >= rhs; }
};
// Class Template to compare Min Priority
template<typename Obj>
class MinPriority{
    public:
        bool compare(const Obj& lhs, const Obj& rhs ) const{
            return lhs <= rhs; }
};

template<typename Obj, typename Compare>
class PriorityQueue{
    public:
        PriorityQueue(){            // Resizes the vector
            heap.resize(50);
            num = 0;
        }     
        void dequeue(){             // Removes the highest priority item
            num--;
            swap(heap[0], heap[num]);
            heap.erase(heap.begin() + num);
            heapDown(0);
        }
        void enqueue(Obj Ob){       // Enqueues item in proper heap order
            heap[num] = Ob;
            heapUp(num);
            num++;
        }
        void print(){               // Displays the items in the heap
            for(int i = 0; i < num; i++){
                cout << heap[i] << "  ";
            }
        }
        bool empty(){               // Returns true if queue is empty
            return((num == 0) ? true:false);
        }
    private:
        int num;                    // Number of actual elements in the vector
        int parent;                 // Parent node
        int lChild;                 // Left child node
        int rChild;                 // Right child node
        int largest;                // The largest value
        Compare cmp;
        vector<Obj> heap;
        // Heap up and index based on its priority
        void heapUp(int n){
            parent = (n - 1) / 2;
            if(cmp.compare(heap[parent], heap[n]) && n > 0){
                swap(heap[parent], heap[n]);
                heapUp(parent);
            }
        }
        // Heap down and index based on its priority
        void heapDown(int n){
            lChild = (2 * n + 1);
            rChild = (2 * n + 2);
            largest = n;
            if(rChild < num && cmp.compare(heap[largest], heap[rChild]))
                largest = rChild;
            else if(lChild < num && cmp.compare(heap[n], heap[lChild]))
                largest = lChild;
            else if(largest != n){
                swap(heap[n], heap[largest]);
                heapDown(largest);
            } 
        }
};
#endif