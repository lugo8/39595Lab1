#include "hash_list.h"

hash_list::hash_list() 
{
    size = 0;
    head = NULL;
    iter_ptr = NULL;
}

//Student added to aid in debugging
//Prints out the linked list
void hash_list::print_list()
{
    node* iter = head;
    
    if(head == NULL)
    {
        std::cout << "Empty List" << std::endl;
    }

    else
    {

        while(iter != NULL)
        {
            std::cout << iter->value << " | ";
            iter = iter->next;
        }
        std::cout << "\n";
    }
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) 
{
    node* iter = head;

    //Empty list
    if(head == NULL)
    {
        //Initialize the list
        node* first = new node();
        first->key = key;
        first->value = value;
        first->next = NULL;
        head = first;

        size++;

    }
    
    else
    {
        //Find the key or end of list
        while(iter->next != NULL && iter->key != key)
        {
            iter = iter->next;
        }

        //Update key/value pair
        if(iter->key == key)
        {
            iter->value = value;
        }

        //New key
        else
        {
            node* last = new node();
            last->key = key;
            last->value = value;
            last->next = NULL;
            iter->next = last;

            size++;
        }
    }
    
}

std::optional<float> hash_list::get_value(int key) const 
{
    //Cannot have a value if list is empty
    if(head == NULL)
    {
        return std::nullopt; 
    }

    node* iter = head;

    //Look through all nodes
    while(iter != NULL)
    {
        if(iter->key == key)
        {
            return iter->value;
        }
        
        iter = iter->next;
    }
    
    //If no matching key, return empty optional
    return std::nullopt; 
}

bool hash_list::remove(int key) { 
    //
    
    
    if(head == NULL){
     return false;    
    } 

    node* prevIter = head;
    if(prevIter->key == key){
        head = head->next;
        delete prevIter;
        size--;
        return true;
    }
    node* iter = head->next;//to be continued

    while(iter != NULL)
    {
        if(iter->key == key)
        {
            prevIter->next = iter->next; //link the 2 nodes beside the one to be deleted (iter)
            delete iter; //clear the mem
            size--;
            return true;
        }
        
        iter = iter->next; //check next node
        prevIter = prevIter->next; //previous node must also increment to follow
    }
    //at this point every node has been searched for the key and it was not found, so return false
    return false;
    
}

size_t hash_list::get_size() const 
{ 
    return size; 
}

hash_list::~hash_list() 
{
    //Empty list
    if(head == NULL)
    {
        return;
    }

    node* curr = head;

    node* next = curr->next;

    if(next == NULL)
    {
        delete next;
        delete curr;
        return;
    }

    while(next != NULL)
    {
        delete curr;
        curr = next;
        next = next->next;
    }

    delete curr;
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) 
{
    //Deep copy components
    this->size = other.size;
    if (other.head == NULL) 
    {
        this->head = NULL;
        this->iter_ptr = NULL;
    } 
    else 
    {
        node* newIter = NULL;  // Keep track of iter_ptr in the new list
        this->head = hash_list::cpy_list(other.head, other.iter_ptr, newIter);
        this->iter_ptr = newIter;  // Update iter_ptr correctly
    }
}

node* hash_list::cpy_node(const node* lastNode)
{
    //Deep copy of a node
    node* newNode = new node();
    newNode->key = lastNode->key;
    newNode->next = NULL;
    newNode->value = lastNode->value;

    return newNode;
}

node* hash_list::cpy_list(node* curr, node* lastIter, node*& newIter)
{
    //Init
    if(curr == NULL)
    {
        return NULL;
    }

    int startKey = curr->key;
    node* newHead = NULL;
    node* newCurr = NULL;

    //Iterate through and make copies of each node
    while(curr != NULL)
    {
        //Make a copy of current node
        node* cpy = hash_list::cpy_node(curr);

        if(curr->key == startKey)
        {
            //If start
            newHead = cpy;
            newCurr = cpy;
        }
        else
        {
            newCurr->next = cpy;
            newCurr = cpy;
        }

        //If iter is the current node
        if(curr == lastIter)
        {
            newIter = cpy;
        }


        curr = curr->next;

    }

    newCurr->next = NULL;

    return newHead;
}


hash_list &hash_list::operator=(const hash_list &other) 
{
    //Operator
    if(this == &other) 
    {
        return *this;
    }

    hash_list temp = other;
    std::swap(this->size, temp.size);
    std::swap(this->head, temp.head);
    std::swap(this->iter_ptr, temp.iter_ptr);

    return *this; 
}

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
