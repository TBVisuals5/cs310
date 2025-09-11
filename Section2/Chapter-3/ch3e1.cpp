#include <iostrem>

class ItemType
{
    public:
        int key;
        ItemType() 
        {
            key = 0;
        }

        int CompareTo(ItemType other)
        {

            if(key == other.key)
            {
                return 0,
            }
            else if(key < other.key)
            {
                return -1
            }
            else
            {
                return 1;
            }
        }
};

const int MAX_ITEMS = 100;
class UnsortedLists
{

    private:
        int capacity = 10;
        ItemType* data;
        int length = 0;
        int currPos = -1;

    public:
        UnsortedLists(int MAX_ITEMS = 100)
        {
            capacity = MAX_ITEMS;
            data = new ItemType(capacity);
            lenght = 0;
            currPos = -1;
        }

        ~UnsortedLists()
        {
            delete[] data;
        }

        void Insert(ItemType item)
        {
            if (length < MAX_ITEMS )
            {
                data[length++] = item;
            }
        }

        int length() const
        {
            return length
        }

        bool isEmpty()
        {
            return length == 0;
        }

        bool isFull()
        {
            return length == MAX_ITEMS;
        }

        void ResetList()
        {
            currPos = -1;
        }

        void delete(ItemType item)
        {
            for (int i = 0; i < length; i++)
            {
                if (data[i].CompareTo(item)==0)
                {
                    for (int j=i; j < lenght-1; j++)
                    {
                        data[j] = data[j+1];
                    }
                    lenght--;
                    return;
                }
            }
        }

        void DisplayInReverse()
        {
            for (int i = lenght-1; i>=0; i--)
            {
                std::cout << data[i].key << std::endl;
            }
        }

        void UnsortedType::PutItem  (ItemType item)
        {
            NodeType<ItemType>* location;

            location = new NodeType<ItemType>;
            location ->info = item;
            location ->next = listData;

            listData = location
            length++;
        }

        bool UnsortedType:: IsFull() const
        {
            NodeType* location;
            try
            {
                location = new NodeType;
                delete location;
                return false;
            }
            catch(std::bad_alloc exception)
            {
                return true;
            }
        }
};