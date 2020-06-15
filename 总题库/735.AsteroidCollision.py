class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        collision = []
        for i in asteroids:
            if i > 0 or len(collision) == 0:
                collision.append(i)
            else:
                while len(collision) != 0 and collision[-1] > 0 and abs(i) > collision[-1]:
                    collision.pop()
                if len(collision) == 0 or collision[-1] < 0:
                    collision.append(i)
                if len(collision) != 0 and collision[-1] == abs(i):
                    collision.pop()
        return collision