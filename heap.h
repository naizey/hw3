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
   //constructs an m-ary heap for any m >= 2
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
  
  //Data members
  std::vector<T> data_; // vector to store heap data
  PComparator comp_; // instance of the comparator object
  int m_; // m-aryness of the heap

  //Helper functions 
  void heapifyUp(size_t index);
  void heapifyDown(size_t index);


};


// Add implementation of member functions here

//Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
  m_(n), comp_(c) {}


//Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}


//Push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  data_.push_back(item);
  heapifyUp(data_.size() - 1);
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
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front(); //returns reference to first element in vector, corresponding to top element of heap


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
    throw std::underflow_error("Heap is empty");

  }

  std::swap(data_.front(), data_.back());  //swaps top with last element (most right)
  data_.pop_back(); //removes last element (the top element)
  if(!empty())
  {
    heapifyDown(0); //heapify down from root
  }



}

//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
}


//heapifyUp
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index)
{

  while(index > 0)
  {
    size_t parent = (index - 1) / m_;
    if(comp_(data_[index], data_[parent])) //depending on min or max heap, comp will use less or greater
    {
      std::swap(data_[index], data_[parent]);
      heapifyUp(parent);
    }
    else
    {
      break;
    }
  }
  
}

//heapifyDown
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index)
{
  size_t child = m_ * index + 1; //first child of index
  while(child < data_.size()) //while child is within bounds of vector
  {
    size_t bestChild = child; //initialize best child to first child
    for(size_t i = 1; i < m_ && child + i < data_.size(); ++i) //iterate through children
    {
      if(comp_(data_[child + i], data_[bestChild])) //depending on min or max heap, comp will use less or greater
      {
        bestChild = child + i; //update best child
      }
    }

    if(comp_(data_[bestChild], data_[index])) //^^
    {
      std::swap(data_[index], data_[bestChild]); //swap parent with best child
      index = bestChild; //update index to best child
      child = m_ * index + 1; //update child to new index
    }

    else 
    {
      break; //done early if parent is less than best child
    }
  }
}

#endif

