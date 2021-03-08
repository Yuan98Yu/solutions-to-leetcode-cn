r'''
@Author: your name
@Date: 2019-11-30 11:54:26
@LastEditTime: 2019-11-30 12:20:58
@LastEditors: Please set LastEditors
@Description: In User Settings Edit
@FilePath: \leetcode\297.二叉树的序列化与反序列化.py
'''
#
# @lc app=leetcode.cn id=297 lang=python3
#
# [297] 二叉树的序列化与反序列化
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
# 	def __init__(self, x):
# 		self.val = x
# 		self.left = None
# 		self.right = None


class Codec:
	def serialize(self, root):
		"""Encodes a tree to a single string.
		
		:type root: TreeNode
		:rtype: str
		"""
		ans = ['']
		def dfs(root):
			if root is None:
				ans[0] += 'n,'
			else:
				ans[0] += str(root.val) + ','
				dfs(root.left)
				dfs(root.right)

		dfs(root)
		return ans[0]
		
	def deserialize(self, data):
		"""Decodes your encoded data to tree.
		
		:type data: str
		:rtype: TreeNode
		"""
		def dfs(dlist):
			if dlist[0] == 'n':
				dlist.pop(0)
				return None
			else:
				root = TreeNode(dlist[0])
				dlist.pop(0)
				root.left = dfs(dlist)
				root.right = dfs(dlist)
				return root
		
		data_list = data.split(',')
		return dfs(data_list)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
# @lc code=end
