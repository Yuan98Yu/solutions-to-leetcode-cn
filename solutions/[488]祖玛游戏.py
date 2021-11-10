from typing import List
import re


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        state_queue = [(board, ''.join(sorted(hand)))]
        states_set = set(state_queue)

        step = 0
        while state_queue:
            states_length = len(state_queue)
            step += 1

            for _ in range(states_length):
                cur_board, cur_hand = state_queue.pop(0)

                for i, color in enumerate(cur_hand):
                    for j in range(0, len(cur_board)):
                        if (i>0 and color == cur_hand[i-1]) or \
                            (j>0 and cur_board[j-1] == cur_board[j] and cur_board[j] == color):
                            continue
                        elif color == cur_board[j]:
                            new_hand = cur_hand[:i] + cur_hand[i + 1:]
                            new_board = self.insert_ball(cur_board, j, color)
                            print(step, new_board, new_hand)

                            if len(new_board) == 0:
                                return step
                            if not (new_board, new_hand) in states_set:
                                state_queue.append((new_board, new_hand))
        return -1

    def insert_ball(self, board: List[str], i: int, color: str):
        new_board = board[:i] + color + board[i:]
        new_board = self.clean(new_board)
        return new_board
    
    @staticmethod
    def clean(s):
        n = 1
        while n:
            s, n = re.subn(r'(.)\1{2,}', '', s)
        return s

