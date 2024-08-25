#include "hash_list.h"

hash_list::hash_list() 
{
    size = 0;
    head = nullptr;
    iter_ptr = nullptr;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) 
{
    node* iter_ptr = head;

    //Check to see if key is in bounds of linked list or
    //is adding beyond one bigger than current list
    if(key < 0 || key > size)
    {
        return std::nullopt;
    }

    //If adding to end of list
    if(key == size) 
    {
        //Empty list
        if(head == nullptr)
        {
            //Initialize the list
            node first = {.key = 0, .value = value, .next = nullptr};
            head = &first;
        }

        else
        {
            //Find end of list
            while(iter_ptr != nullptr && iter_ptr->next != nullptr)
            {
                iter_ptr = iter_ptr->next;
            }

            node last = {.key = size, .value = value, .next = nullptr};

            iter_ptr->next = &last;

        }

        size++;
        
    }

    //Replacing a current key/value pair
    else
    {
        //Find the key
        while(iter_ptr->key != key)
        {
            iter_ptr = iter_ptr->next;
        }

        iter_ptr->value = value;

    }
}

std::optional<float> hash_list::get_value(int key) const { return std::nullopt; }

bool hash_list::remove(int key) { return false; }

size_t hash_list::get_size() const { return 0; }

hash_list::~hash_list() {}

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
