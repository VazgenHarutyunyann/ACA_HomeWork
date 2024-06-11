#include <iostream>
#include <list>

double ListAverage(auto& list)
{
    double sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        sum = sum + (*it);
    }
    
    return sum / list.size();
}

void printList(auto& list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << std::endl;
}

void deleteElements(auto& list , const double& average)
{
    for (auto it = list.begin(); it != list.end(); )
    {
        if (*it < average)
        {
            it = list.erase(it);
        }
        else
        {
            ++it;
        }
        
    }
    
}

int main()
{
    std::list<int> myList{3 , 5 , 10 , 6 , 7};

    double average = ListAverage(myList);
    std::cout << "Average = " << average << std::endl;

    std::cout << "List before: " << std::endl;
    printList(myList);

    std::cout << "List after: " << std::endl;
    deleteElements(myList , average);
    printList(myList);

    return 0;
}