class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def bt(counters: dict):
            count = 0
            for key, num in counters.items():
                if num > 0:
                    counters[key] = num - 1
                    count += 1 + bt(counters)
                    counters[key] = num
            return count
        counters = dict()
        for tile in tiles:
            counters[tile] = counters.get(tile, 0) + 1
        return bt(counters)
