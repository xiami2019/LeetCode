# 使用Python中的有序字典（OrderedDict）
from collections import OrderedDict

class LRUCache(OrderedDict):

    def __init__(self, capacity: int):
        self.capacity = capacity


    def get(self, key: int) -> int:
        if key not in self:
            return -1

        self.move_to_end(key) # 把当前的键值移动到最后端
        return self[key]


    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False) # 如果超出了容量，从最前端弹出元素（最久未使用的）；


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)