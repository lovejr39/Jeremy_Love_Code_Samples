#include "frontier_queue.hpp"
#include <iostream>

template <typename T>
State<T> frontier_queue<T>::pop() 
{
  State<T> swapState = queue[0] ;
  queue[0] = queue[queue.size() - 1] ;
  queue[queue.size() - 1] = swapState ;

  State<T> returnState = queue[queue.size() - 1] ;

  queue.pop_back() ;

  std::size_t currentIndex = 0 ;
  std::size_t childIndex = (2 * currentIndex) + 1 ;

  while(childIndex < queue.size())
  {
    if(childIndex + 1 < queue.size())
      if(queue[childIndex].getFCost() > queue[childIndex + 1].getFCost())
        childIndex++ ;

    if(queue[childIndex].getFCost() < queue[currentIndex].getFCost())
    {
      swapState = queue[currentIndex] ;
      queue[currentIndex] = queue[childIndex] ;
      queue[childIndex] = swapState ;
    }

    currentIndex = childIndex ;
    childIndex = (2 * childIndex) + 1 ;
  }
  
  return returnState ;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) 
{
  if(contains(p))
    replaceif(p, cost) ;

  State<T> newState = State<T>(p, cost, heur) ;

  queue.push_back(newState) ;

  State<T> swapState = queue[0] ;

  std::size_t newIndex = queue.size() - 1 ;

  if(newIndex != 0)
  {
    std::size_t parentIndex = (newIndex - 1) / 2 ;
    
    while(newIndex != 0)
    {
      if(queue[parentIndex].getFCost() <= queue[newIndex].getFCost())
        return ;

      swapState = queue[newIndex] ;
      queue[newIndex] = queue[parentIndex] ;
      queue[parentIndex] = swapState ;

      newIndex = parentIndex ;
      parentIndex = (newIndex - 1) / 2 ;
    }
  }
}

template <typename T>
bool frontier_queue<T>::empty()
{ return queue.size() == 0 ;  }

template <typename T> 
bool frontier_queue<T>::contains(const T &p) 
{
  if(empty())
    return false ;
  for(int i = 0 ; i < queue.size() ; i++)
  {
    if(queue[i].getValue() == p)
      return true ;
  }
  return false ;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) 
{
  if(!empty() && contains(p))
  {
    std::size_t currentIndex = 0 ;

    for(int i = 0 ; i < queue.size() ; i++)
      if(queue[i].getValue() == p)
      {
        if(queue[i].getPathCost() < cost)
          return ;
        queue[i].updatePathCost(cost) ;
        currentIndex = i ;
        break ;
      }
    
    std::size_t childIndex = (2 * currentIndex) + 1 ;

    while(childIndex < queue.size())
    {
      if(childIndex + 1 < queue.size())
        if(queue[childIndex].getFCost() > queue[childIndex + 1].getFCost())
          childIndex++ ;

      if(queue[childIndex].getFCost() < queue[currentIndex].getFCost())
      {
        State<T> swapState = queue[currentIndex] ;
        queue[currentIndex] = queue[childIndex] ;
        queue[childIndex] = swapState ;
      }

      currentIndex = childIndex ;
      childIndex = (2 * childIndex) + 1 ;
    }
  }
}