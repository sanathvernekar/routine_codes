template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};
void main()
{
   custom_priority_queue<int> queue;

   queue.push(10);
   queue.push(2);
   queue.push(4);
   queue.push(6);
   queue.push(3);

   queue.remove(6);

   while (!queue.empty())
   {
      std::cout << queue.top();
      queue.pop();

      if (!queue.empty())
      {
        std::cout << ", ";
      }
   }

 }

