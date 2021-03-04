from typing import List


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        ans = list()

        sorted_people = sorted(people,
                               key=lambda person: (-person[0], person[1]))
        # print(sorted_people)
        for person in sorted_people:
            k = person[1]
            ans.insert(k, person)

        return ans
