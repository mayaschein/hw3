#ifndef QUEUE_H 
#define QUEUE_H
#include "QueueNode.h"

/*
 * This is a general implementation of a queue class.
 * A queue is a data structure that follows the First In, First Out (FIFO) principle.
 * @attention 
 *      the type of the elements T must support the following operations:
 *      - default c'tor
 *      - destructor
 *      - copy c'tor
 *      - operator =( )
 */
template<class T> 
 class Queue{
    public:

    /*
    * EmptyQueue:
    * Exception in case that a function that isn't supported on empty queues gets an empty queue.
    */
    class EmptyQueue{};

    /*
     * pushBack:
     * The function adds a new element to the end of the queue.
     * @param T element The new element of type T.
     * @exception 
     *      - Will throw an exception if the construction of T fails. 
    */
    void pushBack(const T &element);

    /*
    * front:
    * Gets the first element in the queue.
    * @return reference to the first element in the queue.
    * @exception If the queue is empty, it will abort and throw EmptyQueue.
    */
    T& front();

    /*
    * front(const):
    * Gets the first element in the queue in read-only format.
    * @return const reference to the first element in the queue.
    * @exception If the queue is empty, it will abort and throw EmptyQueue.
    */
    const T& front() const;

   /*
   * popFront:
   * The function removes the first element in the queue.
   * Notice that it doesn't return its value.
   * @exception If the queue is empty, it will abort and throw EmptyQueue.
   */
    void popFront();

    /*
    * size:
    * The function returns the m_current number of elements in the queue. 
    * @return The queue size.
    */
    int size() const;

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
    Iterator begin();
    Iterator end();
    /*
    * end():
    * points to the queue's ending.
    * @exception If an invalid operation is performed on the end() iterator, it will throw InvalidOperation.
    * @return Iterator that points to next to last element.
    */
    ConstIterator begin() const;
    ConstIterator end() const;

    //Default c'tor of an empty Queue:
    Queue();

    /*
    * Copy c'tor:
    * @param queue of type T.
    * @exception 
    *   Memory allocation may fail in the process. If so, bad_alloc is thrown.
    *   If the c'tor of T throws an exception, it is rethrown.
    */
    Queue(const Queue &queue);

    /*
    * Assignment operator:
    * @exception 
    *   Memory allocation may fail in the process. If so, bad_alloc is thrown.
    *   If the c'tor of T throws an exception, it is rethrown.
    */
    Queue& operator=(const Queue<T> &other);

    //destructor
    ~Queue();


    private:

    //pointer to the node containing the first element in the queue:
    QueueNode<T> *m_front;

    //pointer to the node containing the last element in the queue:
    QueueNode<T> *m_back;

    //the queue's size:
    int m_size;
 };

//////////////Iterators//////////////

/*
* Iterator for Queue:
*/

template<class T>
class Queue<T>::Iterator{
    private:
    
    // Pointer to the m_current node
    QueueNode<T>* m_current;

    public:

    //c'tor:
    Iterator(QueueNode<T>* node) :m_current(node) {}

    /*
    * InvalidOperation:
    * Exception in case that an operation on an iterator is invalid.
    */
    class InvalidOperation{};

    /*
    * *( ) operator:
    * Gets a read-only version of the element that the iterator points to.
    * @return reference to the element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    T& operator*() 
    {
        if (!m_current) {
            throw InvalidOperation();
        }
        return m_current->m_data;
    }

    /*
    * ++( ) operator:
    * Moves an iterator to the next element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    Iterator& operator++()
    {
        if (!m_current) {
            throw InvalidOperation();
        }
        m_current = m_current->m_next;
        return *this;
    }

    /*
    * != operator:
    * Compares iterator to another iterator.
    * @param iterator on the same queue.
    * @return - true if the iterators point to different elements.
    *         - false if the iterators point to the same element.
    */
    bool operator!=(const Iterator& it) const
    {
        return this->m_current != it.m_current;
    }
    

    //Function to get the begin iterator
        Iterator begin() {
        return Iterator(m_front);
    }

    // Function to get the ending iterator
    Iterator end() {
        return Iterator(m_back+1);
    }
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};

/*const Iterator for Queue*/
template<class T>
class Queue<T>::ConstIterator{
    private:
    const QueueNode<T>* m_current;
    public:
    ConstIterator(const QueueNode<T>* node) : m_current(node) {}

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
    const T& operator*() const
    {
        if (!(this->m_current)) {
            throw InvalidOperation();
        } 
        return this->m_current->m_data;
    }

    /*
    * ++( ) operator:
    * Moves an iterator to the next element.
    * @exception If the iterator points next to the last member, InvalidOperation is thrown.
    */
    ConstIterator& operator++()
    {
        if (!m_current) {
            throw InvalidOperation();
        } 
        m_current = m_current->m_next;
        return *this;
    }

    /*
    * != operator:
    * Compares iterator to another iterator.
    * @param iterator on the same queue.
    * @return - true if the iterators point to different elements.
    *         - false if the iterators point to the same element.
    */
    bool operator!=(const ConstIterator& it) const
    {
        return this->m_current != it.m_current;
    }


    /*
    * c'tor and assignment operator of the iterator is default.
    */
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
};

//////////////Queue external functions////////////////////////

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

template<class T, class S> 
    Queue<T> filter(const Queue<T>& queue, S predicate);
    

/*
* transform:
* The function recieves a queue and an operation, and applies the operation on each element in the queue.
* Notice that it is making direct changes to the queue, not making a copy!
* @param queue - A queue of type T.
* @param transform - A pointer to a function or a function object which:
*                  recieves one argument of the queue's element type.
*                  returns a value of T.
*/
template<class T, class S> 
    void transform(Queue<T> &queue, S operation);

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
    T reduce (const Queue<T>& queue, T startingValue, T (*operation)(T, T));















//////////////////////////////////////////////////////////////////////////////////////////////end of public




///////////////Queue member function implementations

template<class T> 
void Queue<T>::pushBack(const T &element){
    QueueNode<T>* newNode = new QueueNode<T>(element); //remember it may fail, don't write code before.

    if(m_size){
        m_back->m_next = newNode;
        m_back = newNode;
    }
    else{
        m_back = newNode;
        m_front = newNode;
    }
    ++m_size;
}

template<class T>
T& Queue<T>::front(){
    if(m_size == 0){
        throw EmptyQueue();
    }
    return m_front ->m_data;
}

template<class T>
const T& Queue<T>::front() const{
    if(m_size == 0){
        throw EmptyQueue();
    }
    return m_front->m_data;
}


template<class T> 
void Queue<T>::popFront(){
    if(m_size == 0){
        throw EmptyQueue();
    }
    QueueNode<T> *temp = m_front->m_next;
    delete m_front;
    m_front = temp;
    --m_size;
}


template<class T>
int Queue<T>::size() const{
    return m_size;
}





//default c'tor of an empty queue
template<class T> 
Queue<T>::Queue(){
     m_front = NULL;
     m_back = NULL;
     m_size = 0;
}

//destructor of the queue
template<class T>
Queue<T>::~Queue(){
    deleteList(m_front);
}

//copy c'tor
template<class T> 
Queue<T>::Queue(const Queue<T> &queue) : m_front(NULL), m_back(NULL), m_size(0) {
    try{
        for(const T& element : queue){
            pushBack(element);
        }
    }
    catch(std::bad_alloc& e){
        delete this;
        throw std::bad_alloc();
    }
    catch(...){ //T may throw some other exception.
        delete this;
        throw;
    }
}

// =( ) operator
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other){
    if(this == &other){
        return *this;
    }
    QueueNode<T> newList = copyList(&other);
    deleteList(m_front);
    m_front = &newList;
    m_back = getLastNode(newList);
    return *this;
}

//Function to get the begin iterator
template<class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(m_front);
}

// Function to get the ending iterator
template<class T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(NULL);
}

//Function to get the const begin iterator
template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
    return ConstIterator(m_front);
}

// Function to get the const ending iterator
template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const{
    return ConstIterator(NULL);
}

/////////External functions implementation:

 template<class T, class S> 
  Queue<T> filter(const Queue<T>& queue, S predicate)
{
    Queue<T> result;
    for (typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it)
    {
        if (predicate(*it))
        {
            result.pushBack(*it);
        }
    }

    return result;
}

template<class T>
T reduce (const Queue<T>& queue, T startingValue, T (*operation)(T, T))
{
    T finalValue = startingValue;
    for (typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it)
    {
        finalValue=operation(finalValue,*it);
    }
    return finalValue;
}

template<class T, class S> 
    void transform(Queue<T> &queue, S operation){
        for(T& member : queue){
            operation(member);
        }
    }

#endif //QUEUE_H