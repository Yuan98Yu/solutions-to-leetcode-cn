#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU缓存机制
#

# @lc code=start
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.__dict = OrderedDict()


    def get(self, key: int) -> int:
        if key not in self.__dict:
            return - 1
        
        self.__dict.move_to_end(key)
        return self.__dict[key]

    def put(self, key: int, value: int) -> None:
        self.__dict[key] = value    
        self.__dict.move_to_end(key)     
        if len(self.__dict) > self.capacity:
            self.__dict.popitem(last= False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

