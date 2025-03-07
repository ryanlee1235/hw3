#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapVec;
  void heapify(int index); // custom heapify function
  void trickleUp(int index); // custom trickleUp function
  int mAry; // tracking the m-ary of heap
  PComparator comp; // custom functor support
};

// Add implementation of member functions here
/**
 * @brief Construct a new Heap object
 * 
 * @param m ary-ness of heap tree (default to 2)
 * @param c binary predicate function/functor that takes two items
 *          as an argument and returns a bool if the first argument has
 *          priority over the second.
 */
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  mAry(m), comp(c)
{}

/**
* @brief Destroy the Heap object
* 
*/
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

/**
 * @brief Push an item to the heap
 * 
 * @param item item to heap
 */
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heapVec.push_back(item);
  trickleUp(heapVec.size() - 1);
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapVec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");
  }
  heapVec[0] = heapVec.back();
  heapVec.pop_back();
  heapify(0);
}

/**
 * @brief Returns true if the heap is empty
 * 
 */
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if((int)heapVec.size() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

  /**
 * @brief Returns size of the heap
 * 
 */
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heapVec.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index)
{
  // grabs left-most child
  int betterChild = mAry * index + 1;
  // if child is out of index it is a leaf
  if(betterChild >= (int)heapVec.size())
  {
    return;
  }
  int newChild = betterChild;
  // iterate to support any m-Ary tree
  for(int i = 0; i < (mAry - 1); i++)
  {
    newChild = newChild + 1;
    if(newChild < (int)heapVec.size())
    {
      // custom comparator
      if(comp(heapVec[newChild], heapVec[betterChild]))
      {
          betterChild = newChild;
      }
    }
  }

  if(comp(heapVec[betterChild], heapVec[index]))
  {
    std::swap(heapVec[index], heapVec[betterChild]);
    heapify(betterChild);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index)
{
  int parent = (index - 1) / mAry;
  if(comp(heapVec[parent], heapVec[index]))
  {
    return;
  }
  if(parent >= 0 && comp(heapVec[index],heapVec[parent]))
  {
    std::swap(heapVec[index], heapVec[parent]);
    trickleUp(parent);
  }
}

#endif

