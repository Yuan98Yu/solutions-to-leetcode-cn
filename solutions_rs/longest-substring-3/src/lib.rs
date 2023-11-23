use std::cmp::max;
use std::collections::HashMap;
struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut char2idx: HashMap<char, usize> = HashMap::new();
        let mut max_len: usize = 0;
        let mut left = 0;
        for (i, c) in s.chars().enumerate() {
            if char2idx.contains_key(&c) && (char2idx.get(&c).unwrap() >= &left) {
                max_len = max(max_len, i - left);
                left = char2idx.get(&c).unwrap() + 1;
            }
            char2idx.insert(c, i);
        }
        return max(max_len, s.len() - left) as i32;
    }
}
