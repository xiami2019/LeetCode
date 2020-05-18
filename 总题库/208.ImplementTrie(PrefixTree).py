class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.isString = False
        self.next = {}


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        root = self
        for i in word:
            if i not in root.next:
                root.next[i] = Trie()
            root = root.next[i]
        root.isString = True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        root = self
        for i in word:
            if i not in root.next:
                return False
            root = root.next[i]
        return root.isString


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        root = self
        for i in prefix:
            if i not in root.next:
                return False
            root = root.next[i]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)