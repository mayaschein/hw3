//////////QueueNode implimentation
/*
* QueueNode:
* The node for the linked list containing the queue's elements.
* The nodes in the list are arranged in the following way: m_front->.....->m_back->NULL
*/
template<class T> 
struct QueueNode{
    T m_data;
    QueueNode *m_next;

    // remember T's constructor may fail
    QueueNode() : m_data(), m_next(NULL) {}; //may throw an exception if T's c'tor threw an unknown error.
    QueueNode(const T& element) : m_data(element), m_next(NULL) {} //may throw an exception if T's copy c'tor threw an unknown error.
    ~QueueNode() = default;
    QueueNode(const QueueNode& other) : m_data(other.m_data), m_next(other.m_next) {} //may throw an exception if T's copy c'tor threw an unknown error.
    QueueNode& operator =(const QueueNode& other); //copies m_data but not m_next.


};

/*
    * createEmptyList:
    * creates an empty list of a given size (size>0).
    * @param int size - size of the list.
    * @return - returns pointer to the first node in the list.
    * @exceptions 
    *   - will throw bad_alloc if a memory allocation failed
    *   - will throw an exception if T's c'tor threw an unknown error.
    *   - will throw a generic exception if size is non-positive
    */
   template<class T>
    QueueNode<T>* createEmptyList(const int size);



    /*
    * getLastNode:
    * @param - QueueNode node in the list.
    * @return - pointer to the last node in the list.
    */
   template<class T>
    QueueNode<T>* getLastNode(const QueueNode<T>* list);

/* deleteList:
    * Deletes a given list.
    * @param QueueNode - the first node of the list.
    *
    */
template <class T>
void deleteList(const QueueNode<T>* firstNode);

/*
    * copyList:
    * @param - Pointer to the first node in the list.
    * @return - reference to a new copy of the list.
    * @exceptions 
    *   - will throw bad_alloc if a memory allocation failed
    *   - will throw an exception if T's constructor threw a unknown error.
    *   - will throw a generic exception if the parameter is NULL.
    */
   template<class T>
    QueueNode<T>& copyList(const QueueNode<T>* other);

////////////////////////implementation

template<class T>
QueueNode<T>& QueueNode<T>::operator =(const QueueNode& other){
     if (this != &other) {
        m_data = other.m_data;
    }
    return *this;
}

template<class T>
QueueNode<T>* createEmptyList(const int size){
    if(size <=0){
        throw;
    }

    QueueNode<T> *newList = new QueueNode<T>;
    QueueNode<T> *temp = newList;

    for(int i=0; i < size-1; i++){
        try{
            temp->m_next = new QueueNode<T>;
        }

        catch(std::bad_alloc& e){
            deleteList(newList);
            throw std::bad_alloc();
        }
        catch(...){
            deleteList(newList);
            throw;
        }

        temp = temp->m_next;
    }

    return newList;
}



template<class T>
QueueNode<T>* getLastNode(const QueueNode<T>* list){
    if(list == NULL){
        return NULL;
    }

    while(list->m_next != NULL){
        list = list->m_next;
    }

    return list;
}

template<class T>
QueueNode<T>& copyList(const QueueNode<T>* other){
    if(other = NULL){
        throw;
    }

    QueueNode<T>* listCopy = createEmptyList(other->m_size);
    while(listCopy != NULL){
        listCopy = *other;
        listCopy = listCopy->m_next;
        other = other->m_next;
    }

    return *listCopy;
}

template<class T>
void deleteList(const QueueNode<T>* firstNode){
    QueueNode<T>* temp;

    while(firstNode != NULL){
        temp = firstNode->m_next;
        delete firstNode;
        firstNode = temp;
    }
}
