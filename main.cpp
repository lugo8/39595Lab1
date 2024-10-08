#include <iostream>

#include "hash_list.h"

int trace_1();
int trace_2();
int trace_3();
int trace_4();
int trace_5();

#ifdef PART2 // Only test iterators in part 2
void iterator_example(hash_list &list)
{
    /** We have to reset the iterator before we use it */
    list.reset_iter();

    /** We want to iterate over all nodes, so keep iterating until we're at the end */
    while (!list.iter_at_end())
    {
        /** Get pointers to key/value pairs */
        std::optional<std::pair<const int *, float *>> node_values = list.get_iter_value();

        /** Increment the VALUE. Note that the key remains unchanged */
        (*node_values.value().second)++;

        std::cout << "Key: " << *node_values.value().first
                  << " and value: " << *node_values.value().second << std::endl;

        /** Go to the next element */
        list.increment_iter();
    }
}
#endif

int main(int argc, char *argv[])
{

#ifdef PART1
    hash_list list;
    //std::cout << "TEST 1:" << std::endl; //TEST1

    if (list.get_size() != 0)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }

    list.insert(3, 3);
    list.insert(4, 4);
    list.insert(5, 5);
    list.insert(6, 6);
    list.insert(6, 6);

    if (list.get_size() != 4)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    }

    //list.print_list();

    if (!list.get_value(3).has_value())
    {
        std::cout << "expected 3 to be in list but it wasn't" << std::endl;
        exit(1);
    }

    // hash_list list2;
    // list2.insert(7, 7);
    // list2.insert(8, 8);
    // list2.insert(9, 9);
    // list2.insert(10, 10);

    // hash_list list3 = list;

    // std::cout << "ORIGINAL: " << std::endl;
    // list.print_list();

    // std::cout << "list3: " << std::endl;
    // list3.print_list();

    // list3 = list2;

    // list2.remove(7);

    // std::cout << "list2: " << std::endl;
    // list2.print_list();

    // std::cout << "list3: " << std::endl;
    // list3.print_list();

     if (!list.remove(3))
     {
         std::cout << "Failed to remove 3 from list" << std::endl;
         exit(1);
     }

     if (list.get_value(3).has_value())
     {
         std::cout << "Unexpected 3 in list" << std::endl;
         exit(1);
     }
    //list.print_list();
    if (!list.remove(6))
     {
         std::cout << "Failed to remove 6 from list" << std::endl;
         exit(1);
     }
    //list.print_list();
    if (list.remove(6))
     {
         std::cout << "thats no good!" << std::endl;
         exit(1);
     }
     //list.print_list();

    if (!list.remove(5))
     {
         std::cout << "Failed to remove 5 from list" << std::endl;
         exit(1);
     }
     //list.print_list();



    if (list.get_size() != 1)
    {
        std::cout << "Invalid size" << std::endl;
        exit(1);
    } //works

    //list.print_list();
    //std::cout << list.get_value(3).value() << std::endl; //ERROR UNCOMENTED
    //std::cout << list.get_value(4).value() << std::endl; //works




    if (!list.remove(4))
     {
         std::cout << "Failed to remove 4 from list" << std::endl;
         exit(1);
     }
     //list.print_list();
    if (list.remove(4))
     {
         std::cout << "Failed to recognise empty list" << std::endl;
         exit(1);
     }
     //list.print_list();
#endif

#ifdef PART2

    iterator_example(list);
#endif

}
