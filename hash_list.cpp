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
    //hello
    return false; }

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

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
