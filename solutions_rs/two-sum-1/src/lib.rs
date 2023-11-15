struct Solution;
use std::collections::HashMap;

impl Solution {
    #[cfg(feature = "brute")]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() - 1 {
            let num1: &i32 = nums.get(i).unwrap();
            for j in i + 1..nums.len() {
                if nums.get(j).unwrap() + num1 == target {
                    return vec![i as i32, j as i32];
                }
            }
        }

        unreachable!()
    }

    #[cfg(feature = "best")]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num2idx = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            if let Some(&j) = num2idx.get(&(target - num)) {
                return vec![i as i32, j as i32];
            }
            num2idx.insert(num, i);
        }

        unreachable!()
    }
}
