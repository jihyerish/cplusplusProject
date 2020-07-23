class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        roomlist.resize(rooms.size());
        for(auto it = roomlist.begin(); it != roomlist.end(); it++)
        {
            *it = 0;
        }
        
        bool ret = checkRoom(0, rooms);
        
        return ret;
    }
private:
    bool checkRoom(int roomNumber, vector<vector<int>>& rooms)
    {
        bool ret = true;
        int nextRoom = -1;
        roomlist[roomNumber] = 1;
        auto keys = rooms[roomNumber];

        //check room
        for(auto it = roomlist.begin(); it != roomlist.end(); it++)
        {
            
            if (*it == 0)
            {
                ret = false;
                break;
            }
        }        
        
        if (true == ret)
            return ret;
        
        //copy key
        for(auto it = keys.begin(); it != keys.end(); it++)
        {
            keylist.push_back(*it);
        }
        
        //check next room by key
        int temp = 0;
        while(0 < keylist.size())
        {
            temp = keylist.back();
            if (roomlist[temp] == 1)
                keylist.pop_back();
            else
            {
                keylist.pop_back();
                nextRoom = temp;
                break;
            }
        }

        if (0 > nextRoom)
            return false;

         return ret = checkRoom (nextRoom, rooms);
    }
    
    vector<int> keylist;
    vector<int> roomlist;
};
