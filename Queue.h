#ifndef QUEUE_H 
#define QUEUE_H

/*
 * This is a general implementation of a queue class.
 * A queue is a data structure that follows the First In, First Out (FIFO) principle.
*/

template<class T> 
class QueueNode{
    T data;
    QueueNode* next;
};

template<class T> 
 class Queue{
    public:

    /*
    * EmptyQueue:
    * Exception in case that a function which isn't supported on empty queues gets an empty queue.
    */
    class EmptyQueue{};

    /*
     * pushBack:
     * The function adds a new element to the end of the queue.
     * @param &element Reference to the new element. Type must be as the other elements in the queue.
     * @exception If a memory allocation fails, the function will throw bad_alloc. The queue will remain unchanged.
    */
    void pushBack(const T &element);

    /*
    * front:
    * Gets the first element in the queue.
    * @return reference to the first element in the queue.
    * @exception If the queue is empty, it will abort and throw EmptyQueue.
    */
    T &front();

    /*
    * front(const):
    * Gets the first element in the queue in read-only format.
    * @return const reference to the first element in the queue.
    * @exception If the queue is empty, it will abort and throw EmptyQueue.
    */
    const T &front();

   /*
   * popFront:
   * The function removes the first element in the queue.
   * Notice that it doesn't return its value.
   * @exception If the queue is empty, it will abort and throw EmptyQueue.
   */
    void popFront();

    /*
    * size:
    * The function returns the current number of elements in the queue. 
    * @return The queue size.
    */
    int size();

    /*
    * non-const iterator. Only supports non-const queues.
    * Look at the class definition below for more info.
    * @warning The iterator cannot be used after any change to the queue has been made.
    */
    class Iterator;

    /*
    * const iterator. 
    * Look at the class definition below for more info.
    */
    class ConstIterator;

    /*
    * begin():
    * points to the first element in the queue.
    * @return Iterator that points to the first element.
    */
    Iterator begin() const;
    ConstIterator begin() const;

    /*
    * end():
    * points to the queue's ending.
    * @exception If an invalid operation is performed on the end() iterator, it will throw InvalidOperation.
    * @return Iterator that points to next to last element.
    */
    Iterator end() const;
    ConstIterator end() const;

    private:
    
    //m_back->.....->m_front
    QueueNode m_front;
    QueueNode m_back;

 };


/*
* Iterator for Queue:
*/

template<class T>
class Queue<T>::Iterator{
    /*
    * InvalidOperation:
    * Exception in case that an operation on an iterator is invalid.
    */
    class InvalidOperation{};

    /*
    * *( ) operator:
    * Gets a read-only version of the element that the iterator points to.
    * @return const reference to the element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    const T& operator*() const;

    /*
    * ++( ) operator:
    * Moves an iterator to the next element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    Iterator& operator++();
    
    /*
    * != operator:
    * Compares iterator to another iterator.
    * @param iterator on the same queue.
    * @return - true if the iterators point to different elements.
    *         - false if the iterators point to the same element.
    */
    bool operator!=(const Iterator& it) const;
    

    /*
    * c'tor and assignment operator of the iterator is default????????/.
    */
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;


};

/*const Iterator for Queue*/
template<class T>
class Queue<T>::ConstIterator{
    /*
    * InvalidOperation:
    * Exception in case that an operation on an iterator is invalid.
    */
    class InvalidOperation{};

   /*
    * *( ) operator:
    * Gets a read-only version of the element that the iterator points to.
    * @return const reference to the element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    const T& operator*() const;

    /*
    * ++( ) operator:
    * Moves an iterator to the next element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    constIterator& operator++();

    /*
    * != operator:
    * Compares iterator to another iterator.
    * @param iterator on the same queue.
    * @return - true if the iterators point to different elements.
    *         - false if the iterators point to the same element.
    */
    bool operator!=(const constIterator& it) const;

    /*
    * c'tor and assignment operator of the iterator is default.
    */
    Iterator(const constIterator&) = default;
    Iterator& operator=(const constIterator&) = default;
};

/*
* filter:
* The function takes a queue and a predict, applies it to each element in the queue, and creates a new queue
* consisting only of elements for which the predict returns true.
* @param queue - A queue of type T.
* @param predict - A pointer to a function or a function object which:
*                  recieves only one argument of the queue's element type.
*                  returns a boolean value.
* @return Returns a reference to the new queue.
*/

template<class T> 
    Queue<T>& filter(Queue<T> Queue, bool *predict(T));
    

/*
* transform:
* The function recieves a queue and an operation, and applies the operation on each element in the queue.
* Notice that it is making direct changes to the queue, not making a copy!
* @param queue - A queue of type T.
* @param transform - A pointer to a function or a function object which:
*                  recieves one argument of the queue's element type.
*                  returns a value of T.
*/
template<class T> 
    void transform(Queue<T> queue, T *transform(T element));

/*
* reduce:
* The function recieves a queue, a binary operation, and a starting value. 
* It applies the operation on the last element in the queue with the value,
* then applies the operation on the previous element with the result, and continues recursevely.
* When the operation has been applied on all the elements, it will return the result of the last operation.
* @param queue - A queue of type T.
* @param binaryOperator - A pointer to a function or a function object which:
*                  recieves two argument of the queue's element type.
*                  returns a value of T.
*                  
* @param startingValue - a value of the queue's element type.
*/
template<class T>
    T reduce(queue<T> queue, T *binaryOperator(T element, T externalValue), T startingValue);




#endif //QUEUE_H